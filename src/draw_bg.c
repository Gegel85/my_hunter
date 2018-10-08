/*
** EPITECH PROJECT, 2017
** draw_bg
** File description:
** displays the background
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

//Displays the background
void	draw_bg(game_t *game)
{
	game->sprites[0].rect.left = game->background * 256;
	game->sprites[6].rect.left = game->background * 256;
	sfSprite_setTextureRect(game->sprites[0].sprite, game->sprites[0].rect);
	sfSprite_setTextureRect(game->sprites[6].sprite, game->sprites[6].rect);
	image(game->window,game->sprites[0].sprite, (sfVector2f){0, 0});
	if (game->menu != 0) {
		show_score(game);
		show_ammos(game);
	}
	show_hscore(game);
}
