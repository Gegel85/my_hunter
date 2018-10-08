/*
** EPITECH PROJECT, 2017
** game_over
** File description:
** display game over
*/

#include "structs.h"
#include "function.h"

//Game over loop
void	game_over(game_t *game)
{
	sfVector2f	pos;

	for (int i = 5; i >= 3; i--) {
		pos.x = game->ducks[i - 3].x;
		pos.y = game->ducks[i - 3].y;
		image(game->window,game->sprites[i].sprite, pos);
	}
	image(game->window,game->sprites[8].sprite, (sfVector2f){0, 0});
}
