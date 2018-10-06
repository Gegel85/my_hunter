/*
** EPITECH PROJECT, 2017
** draw_bg
** File description:
** displays the background
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

void	draw_bg(game_t *game)
{
	if (game->menu != 0) {
		show_score(game);
		show_ammos(game);
	}
	show_hscore(game);
	sfSprite_setPosition(game->sprites[0].sprite, (sfVector2f){0, 0});
	game->sprites[0].rect.left = game->background * 256;
	game->sprites[6].rect.left = game->background * 256;
	sfSprite_setTextureRect(game->sprites[0].sprite, game->sprites[0].rect);
}
