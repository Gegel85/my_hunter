/*
** EPITECH PROJECT, 2017
** bonus
** File description:
** Bonus points
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

void	find_good_pos(sfVector2f *pos)
{
	if ((int)pos->x < 0)
		pos-> x = 0;
	if (pos->x + 260 > 1024)
		pos->x = 732;
}

void	set_bonus_pos(int bonus, sfVector2f *pos)
{
	if (bonus >= 10)
		pos->x += 32;
	if (bonus >= 100)
		pos->x += 32;
}

int	init_bonus(int duck_type)
{
	switch (duck_type) {
	case 0:
		return (50);
	case 1:
		return (150);
	case 2:
		return (300);
	}
	return (0);
}

void	display_bonus(game_t *game)
{
	sfVector2f      pos = {game->ducks[0].x - 100, game->ducks[0].y + 200};
	unsigned int	bonus = game->bonus;
	sfVector2f	scale = {4, 4};

	if (bonus > 0) {
		find_good_pos(&pos);
		sfSprite_setScale(game->sprites[17].sprite, scale);
		sfSprite_setPosition(game->sprites[17].sprite, pos);
		pos.x += 196;
		set_bonus_pos(bonus, &pos);
		for (int i = 31; bonus > 0 && i >= 0; i--) {
			sfSprite_setScale(game->sprites[i].sprite, scale);
			sfSprite_setPosition(game->sprites[i].sprite, pos);
			change_nb_sprite_rect(bonus % 10 + 1, game, i);
			bonus /= 10;
			pos.x -= 32;
		}
	}
}
