/*
** EPITECH PROJECT, 2017
** change_sprites
** File description:
** All that involve changing sprites
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "structs.h"
#include "function.h"
#include "global.h"

int	change_duck_rect(sfIntRect *rect, game_t *game, int i)
{
	if (game->cheat) {
		game->mousex = game->ducks[0].x + 75;
		game->mousey = game->ducks[0].y + 100;
	}
	switch (game->ducks[0].state / 3) {
	case 2:
	case 0:
		rect->left = game->ducks[0].state % 3 * 150 + 439 - 5 * i;
		rect->top = game->ducks[0].type * 172;
		rect->width = 149;
		return (rect->height = 170);
	case 3:
	case 1:
		rect->left = game->ducks[0].state % 3 * 135 + 34 - 5 * i;
		rect->top = game->ducks[0].type * 172;
		rect->width = 129;
		return (rect->height = 170);
	}
	return (0);
}

void	change_scale(sfRenderWindow *window, duck *ducks, sfSprite *sprite)
{
	sfVector2f	new_scale;
	sfVector2f	pos = {ducks->x, ducks->y};

	if (ducks->state / 3 == 2 || ducks->state / 3 == 3) {
		pos.x = ducks->x + 110;
		pos.y = ducks->y;
		new_scale = (sfVector2f){-1, 1};
	} else
		new_scale = (sfVector2f){1, 1};
	image(window, sprite, pos);
	sfSprite_setScale(sprite, new_scale);
}

void	change_duck_state(duck *ducks)
{
	sfTime  time;
	int	h = 0;
	float	sec;

	time = sfClock_getElapsedTime(ducks->clock);
	sec = sfTime_asSeconds(time);
	if (sec > 0.1) {
		h = ducks->state % 3;
		if (h == 2)
			ducks->state -= 2;
		else
			ducks->state++;
		sfClock_restart(ducks->clock);
	}
}

void	update_ducks(game_t *game)
{
	sprite_f	*sprites = game->sprites;

	game->ducks[0].x += game->speed * ((float)game->ducks[0].type / 2 + 1);
	if (game->ducks[0].direction == 1)
		game->ducks[0].y += abs(game->speed) * ((float)game->ducks[0].type / 2 + 1) / 2;
	else if (game->ducks[0].direction == 2)
		game->ducks[0].y -= abs(game->speed) * ((float)game->ducks[0].type / 2 + 1) / 2;
	if (game->ducks[0].y < -20) {
		game->ducks[0].y = -20;
		game->ducks[0].direction = 0;
	} else if (game->ducks[0].y > 500) {
		game->ducks[0].y = 500;
		game->ducks[0].direction = 0;
	}
	if (!game->randomMultiplicator || rand() % game->randomMultiplicator == 0)
		game->ducks[0].direction = (game->ducks[0].direction + (rand() % 2 + 1)) % 3;
	if (game->ducks[0].x > 1024) {
		game->ducks[0].state += 6;
	} else if (game->ducks[0].x < -110)
		game->ducks[0].state -= 6;
	if (game->ducks[0].direction == 0 && game->ducks[0].state % 6 >= 3)
		game->ducks[0].state -= 3;
	else if (game->ducks[0].direction != 0 && game->ducks[0].state % 6 < 3)
		game->ducks[0].state += 3;
	if (game->ducks[0].x < -110 || game->ducks[0].x > 1024) {
		game->speed *= -1;
		game->bonus /= 2;
		game->ducks[0].hit = 1;
		game->ducks[0].direction = 0;
		game->combo = 0;
	}
	sfSprite_setTextureRect(game->sprites[3].sprite, game->sprites[3].rect);
	change_duck_rect(&sprites[3].rect, game, game->ducks[0].type);
	change_duck_state(&game->ducks[0]);
	change_scale(game->window, &game->ducks[0], sprites[3].sprite);
}

void	change_sprites(game_t *game)
{
	draw_bg(game);
	change_menus(game);
	image(game->window,game->sprites[6].sprite, (sfVector2f){0, 552});
	game_fcts[game->menu](game);
}
