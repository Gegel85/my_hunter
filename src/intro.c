/*
** EPITECH PROJECT, 2017
** intro
** File description:
** Introduction of the game
*/

#include "structs.h"
#include "function.h"
#include "macros.h"
#include <stdio.h>
#include <SFML/Graphics.h>

void	set_dog_rect_int(game_t *game, int i)
{
	int		h = game->dog.animation % 4;

	if (h > 2)
		h = 2;
	game->dog.speed += ABS(game->dog.speed) * 0.1 + 0.75;
	game->var = 0.5;
	game->dog.x += 2 * h;
	if (h != 0)
		game->dog.y += game->dog.speed;
	if (game->dog.y > 525 && game->dog.speed > 0)
		game->menu = 1;
	game->sprites[i].rect.left = h * (222 - 10 * h) + 1;
	game->sprites[i].rect.top = 0;
	game->sprites[i].rect.width = 212 - h * 20;
	game->sprites[i].rect.height = 400;
	sfSprite_setTextureRect(game->sprites[i].sprite, game->sprites[i].rect);
}

void	set_dog_sprite(game_t *game)
{
	sfVector2f	pos = {game->dog.x, game->dog.y};
	int		i = 1;

	if (game->intro > 159 && game->var != 0.5)
		game->dog.animation = 0;
	if (game->intro > 159) {
		i = 2;
		game->dog.animation = (game->intro - 159) / 15;
		set_dog_rect_int(game, i);
	} else {
		game->dog.x += 2;
		game->sprites[i].rect.left = game->dog.animation % 5 * 224 + 10;
		game->sprites[i].rect.top = 0;
		game->sprites[i].rect.width = 220;
		game->sprites[i].rect.height = 192;
		sfSprite_setTextureRect(game->sprites[i].sprite, game->sprites[i].rect);
	}
	image(game->window,game->sprites[i].sprite, pos);
	if (game->dog.animation % 4 >= 2 && game->intro > 159) {
		game->sprites[6].rect.left = game->background * 256;
		sfSprite_setTextureRect(game->sprites[6].sprite, game->sprites[6].rect);
		image(game->window,game->sprites[6].sprite, (sfVector2f){0, 552});
	}
}

void	update_dog(game_t *game)
{
	sfTime		time;
	float		sec;

	time = sfClock_getElapsedTime(game->clock);
	sec = sfTime_asSeconds(time);
	set_dog_sprite(game);
	if (sec > game->var) {
		if (game->intro < 190)
			game->dog.animation++;
		game->dog.animation %= 4;
		sfClock_restart(game->clock);
	}
	game->intro++;
}
