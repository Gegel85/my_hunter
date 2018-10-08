/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** Bonus points
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

/*Find the position the display the bonus
**to avoid it being out of the window*/
void	find_good_pos(int bonus, sfVector2f *pos)
{
	int	size = 0;

	for (; bonus >= 10; bonus /= 10)
		size++;
	if ((int)pos->x < 0)
		pos->x = 0;
	if (pos->x + size * 32 + 196 > 1024)
		pos->x = 1024 - (size + 1) * 32 - 196;
}

//Sets the first bonus digit position
void	set_bonus_pos(int bonus, sfVector2f *pos)
{
	for (; bonus >= 10; bonus /= 10)
		pos->x += 32;
}

//Base bonus depending on the duck type
unsigned int	init_bonus(int duck_type)
{
	switch (duck_type) {
	case 0:
		return (50);
	case 1:
		return (150);
	case 2:
		return (300);
	default:
		//This should never happen;
		return (0);
	}
}

//Displays the bonus number
void	display_bonus(game_t *game)
{
	sfVector2f      pos = {game->ducks[0].x - 100, game->ducks[0].y + 200};
	unsigned int	bonus = game->bonus;
	sfVector2f	scale = {4, 4};

	if (bonus > 0) {
		find_good_pos(bonus, &pos);
		sfSprite_setScale(game->sprites[17].sprite, scale);
		image(game->window, game->sprites[17].sprite, pos);
		pos.x += 196;
		set_bonus_pos(bonus, &pos);
		sfSprite_setScale(game->sprites[32].sprite, scale);
		for (; bonus > 0; bonus /= 10) {
			change_nb_sprite_rect(bonus % 10 + 1, game, 32);
			image(game->window,game->sprites[32].sprite, pos);
			pos.x -= 32;
		}
	}
}
