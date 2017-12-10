/*
** EPITECH PROJECT, 2017
** change_sprites
** File description:
** All that involve changing sprites
*/

#include "structs.h"
#include <SFML/Graphics.h>
#include "my.h"
#include "function.h"
#include "global.h"

int	change_duck_rect(sfIntRect *rect, game_t *game, int i)
{
	if (game->cheat) {
		game->mousex = game->ducks[0].x + 75;
		game->mousey = game->ducks[0].y + 100;
	}
	switch (game->ducks[i].state / 3) {
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

void	change_scale(duck *ducks, sfSprite *sprite)
{
	sfVector2f	new_scale;
	sfVector2f	pos;

	if (ducks->state / 3 == 2 || ducks->state / 3 == 3) {
		pos.x = ducks->x + 110;
		pos.y = ducks->y;
		sfSprite_setPosition(sprite, pos);
		new_scale = (sfVector2f){-1, 1};
	} else
		new_scale = (sfVector2f){1, 1};
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
	sfVector2f	pos;
	sprite_f	*sprites = game->sprites;

	game->ducks[0].x += game->speed * (game->ducks[0].type + 1);
	if (game->ducks[0].x > 1024) {
		game->ducks[0].state += 6;
	} else if (game->ducks[0].x < -110)
		game->ducks[0].state -= 6;
	if (game->ducks[0].x < -110 || game->ducks[0].x > 1024) {
		game->speed *= -1;
	        game->bonus /= 2;
		game->ducks[0].hit = 1;
		game->combo = 0;
	}
	change_duck_state(&game->ducks[0]);
	change_duck_rect(&sprites[3].rect, game, game->ducks[0].type);
	pos.x = game->ducks[0].x;
	pos.y = game->ducks[0].y;
	sfSprite_setPosition(sprites[3].sprite, pos);
	change_scale(&game->ducks[0], sprites[3].sprite);
}

void	change_sprites(sprite_f *sprites, game_t *game, int nb)
{
	reset_sprite_pos(sprites, nb);
	draw_bg(game);
	change_menus(game);
	game_fcts[game->menu](game);
}
