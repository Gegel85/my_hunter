/*
** EPITECH PROJECT, 2017
** duck_death
** File description:
** The duck death animation
*/

#include "structs.h"
#include "function.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

void	change_state(game_t *game, float sec)
{
	if (sec > game->var) {
		if (game->ducks[0].state == 9)
			sfMusic_play(game->musics[4]);
		game->var = 0.07;
		game->ducks[0].state++;
		sfClock_restart(game->ducks[0].clock);
		if (game->ducks[0].state == 12)
			game->ducks[0].state = 10;
	}
	if (game->ducks[0].y >= 525) {
		sfMusic_stop(game->musics[4]);
		sfMusic_play(game->musics[5]);
		game->menu = 4;
		sfClock_restart(game->clock);
		game->ducks[0].state = 0;
	}
}

void	change_rect(game_t *game)
{
	int	state = game->ducks[0].state;

	switch (state) {
	case 9:
		game->sprites[3].rect.top = 175 * game->ducks[0].type;
		game->sprites[3].rect.left = 889 + game->ducks[0].type * 5;
		game->sprites[3].rect.width = 150;
		game->sprites[3].rect.height = 170;
		display_bonus(game);
		break;
	case 10:
	case 11:
		game->sprites[3].rect.top = 175 * game->ducks[0].type;
		game->sprites[3].rect.left = 1050 + 100 * (state - 10);
		game->sprites[3].rect.width = 100;
		game->sprites[3].rect.height = 170;
	}
}

void	duck_fall(game_t *game)
{
	sfVector2f	pos;
	sfTime		time;
	float		sec;
	int		cond = game->ducks[0].y <= 550;

	time = sfClock_getElapsedTime(game->ducks[0].clock);
	sec = sfTime_asSeconds(time);
	change_state(game, sec);
	change_rect(game);
	pos.x = game->ducks[0].x;
	pos.y = game->ducks[0].y;
	game->ducks[0].y += (game->ducks[0].state - 8) / 2 * 20 * cond;
	sfSprite_setPosition(game->sprites[6].sprite, (sfVector2f){0, 552});
	sfSprite_setPosition(game->sprites[3].sprite, pos);
}

void	modify_dog_rect(game_t *game)
{
	game->sprites[2].rect.top = 0;
	game->sprites[2].rect.left = 550;
	game->sprites[2].rect.width = 219;
	game->sprites[2].rect.height = 220;
	sfSprite_setPosition(game->sprites[6].sprite, (sfVector2f){0, 552});
}

void	show_dog(game_t *game)
{
	sfTime		time;
	float		sec;
	sfVector2f      pos = {game->dog.x, game->dog.y};

	time = sfClock_getElapsedTime(game->clock);
	sec = sfTime_asSeconds(time);
	modify_dog_rect(game);
	if (sec > 1 && game->var < 1) {
		game->var = 1;
		sfMusic_play(game->musics[1]);
	}
	if (sec > 1 || game->var >= 1) {
		if (game->var == 1 && game->dog.y > 450)
			game->dog.y -= 5;
		else if (game->var == 11 && game->dog.y < 525)
			game->dog.y += 5;
		else
			game->var++;
		sfSprite_setPosition(game->sprites[2].sprite, pos);
	}
}
