/*
** EPITECH PROJECT, 2017
** menu
** File description:
** Main menu
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

void	change_duck(duck *duck_ex, sfIntRect *rect)
{
	change_duck_state(duck_ex);
	rect->left = duck_ex->state % 3 * 150 + 439 - 5 * duck_ex->type;
	rect->top = duck_ex->type * 172;
	rect->width = 149;
	rect->height = 170;
}

void	menu(game_t *game)
{
	sfIntRect	*rect = &game->sprites[35].rect;
	sfTime		time;
	float		sec;

	time = sfClock_getElapsedTime(game->clock);
	sec = sfTime_asSeconds(time);
	sfSprite_setScale(game->sprites[22].sprite, (sfVector2f){4, 4});
	sfSprite_setPosition(game->sprites[22].sprite, (sfVector2f){0, 0});
	sfSprite_setPosition(game->sprites[36].sprite, (sfVector2f){900, 50});
	sfSprite_setScale(game->sprites[36].sprite, (sfVector2f){-1, 1});
	sfSprite_setPosition(game->sprites[35].sprite, (sfVector2f){130, 260});
	change_duck(&game->ducks[1], rect);
	rect = &game->sprites[36].rect;
	change_duck(&game->ducks[2], rect);
	if (sec >= 1) {
		game->ducks[1].type = rand() % 3;
		game->ducks[2].type = rand() % 3;
		sfClock_restart(game->clock);
	}
}
