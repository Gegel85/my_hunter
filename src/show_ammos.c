/*
** EPITECH PROJECT, 2017
** show_ammos
** File description:
** Display the ammos left on the screen
*/

#include <SFML/Graphics.h>
#include "structs.h"

void	show_ammos(game_t *game)
{
	int		miss = 3 - game->miss;
	sfIntRect	*rect = &game->sprites[19].rect;
	sfVector2f	pos = {400, 732};
	sfVector2f	scale = {4, 4};

	sfSprite_setScale(game->sprites[18].sprite, scale);
	sfSprite_setPosition(game->sprites[18].sprite, pos);
	pos = (sfVector2f){412, 736};
	for (int i = 19; i < 22; i++) {
		sfSprite_setScale(game->sprites[i].sprite, scale);
		sfSprite_setPosition(game->sprites[i].sprite, pos);
		pos.x += 32;
	}
	rect->left = miss > 0 ? 0 : 4;
	rect = &game->sprites[20].rect;
	miss--;
	rect->left = miss > 0 ? 0 : 4;
	rect = &game->sprites[21].rect;
	miss--;
	rect->left = miss > 0 ? 0 : 4;
}
