/*
** EPITECH PROJECT, 2017
** modify_duck_speed
** File description:
** Modify the duck speed
*/

#include "structs.h"
#include "my.h"
#include "function.h"
#include <SFML/Graphics.h>

void	create_type(duck *duck)
{
	int	type = rand() % 12;

	if (type <= 8)
		duck->type = 0;
	else if (type <= 10)
		duck->type = 1;
	else
		duck->type = 2;
}

void	change_duck_speed(game_t *game)
{
	game->menu = 3;
	game->dog.x = game->ducks[0].x - 50;
	game->dog.y = 500;
	if (game->speed < 0) {
		game->speed *= -1;
		game->ducks[0].state -= 6;
		game->ducks[0].x += 100;
	}
	if (game->speed < 50)
		game->speed++;
	if (game->ducks[0].hit == 0)
		sfMusic_play(game->musics[2]);
	game->ducks[0].hit = 0;
	game->score += (game->ducks[0].type + 1) * 100 + game->bonus;
	game->ducks[0].state = 9;
	sfClock_restart(game->ducks[0].clock);
}

int	modify_duck_speed(game_t *game)
{
	int	x = game->ducks[0].x;
	int	y = game->ducks[0].y;
	float	mx = game->mousex;
	float	my = game->mousey;

	sfMusic_play(game->musics[6]);
	if (mx > x && mx < x + 150 && my > y + 50 && my < y + 160) {
		change_duck_speed(game);
		return (my_printf("Well done !\nScore : %u\n", game->score));
	}
	game->miss++;
	return (my_printf("Too Bad...\nMissed : %i\n", game->miss));
}
