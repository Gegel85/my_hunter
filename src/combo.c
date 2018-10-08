/*
** EPITECH PROJECT, 2017
** combo
** File description:
** display the combo
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

//Sets the combo last digit position
void	set_combo_pos(int bonus, sfVector2f *pos)
{
	for (; bonus >= 10; bonus /= 10)
		pos->x += 32;
}

//Displays the compo
void	display_combo(game_t *game)
{
	sfVector2f      pos = {550, 750};
	unsigned int    bonus = game->combo;
	sfVector2f      scale = {4, 4};
	int		i = 40;

	sfSprite_setScale(game->sprites[38].sprite, scale);
	image(game->window,game->sprites[38].sprite, pos);
	pos.x += 196;
	set_combo_pos(bonus, &pos);
	do {
		sfSprite_setScale(game->sprites[i].sprite, scale);
		change_nb_sprite_rect(bonus % 10 + 1, game, i);
		image(game->window,game->sprites[i].sprite, pos);
		bonus /= 10;
		pos.x -= 32;
		i--;
	} while (bonus > 0 && i >= 0);
}
