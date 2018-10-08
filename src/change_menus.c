/*
** EPITECH PROJECT, 2017
** change_menus
** File description:
** Change menus when needed
*/

#include "structs.h"
#include "my.h"
#include "function.h"

//Restart the game
void	restart(game_t *game)
{
	reset_game(game);
	my_printf("Restarting game\n");
	game->menu = 5;
	game->miss = 0;
	sfMusic_play(game->musics[7]);
}

//End of the game
void	end_game(game_t *game)
{
	int     miss = game->miss;
	int     score = game->score;

	my_printf("Final score : %u\nFinal missed : %i\n", score, miss);
	game->menu = 2;
	sfMusic_play(game->musics[3]);
	if (game->clock)
		sfClock_restart(game->clock);
}

//Conditions to change menu
void	change_menus(game_t *game)
{
	sfTime  time;
	float   sec;

	time = sfClock_getElapsedTime(game->clock);
	sec = sfTime_asSeconds(time);
	if (game->miss >= 3 && game->menu == 1) {
		end_game(game); //Game over
	} else if (sec > 4 && game->menu == 2) {
		//After game over, check if the score beats the current best score
		if (game->score > game->maxscore) {
			game->maxscore = game->score;
			my_printf("New highest score !\n");
		}
		restart(game);
	} else if (game->var >= 12 && game->menu == 4) {
		/* After the dog animation when a duck is hit,
		** reset and spawn a new duck*/
		game->menu = 1;
		game->ducks[0].x = -100;
		game->ducks[0].y = rand() % 450;
		create_type(&game->ducks[0]);
		game->bonus = init_bonus(game->ducks[0].type);
	}
}
