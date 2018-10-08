/*
** EPITECH PROJECT, 2017
** save_score.c
** File description:
** Saves the score in a file
*/

#include "structs.h"
#include "my.h"
#include "macros.h"
#include <unistd.h>
#include <stdio.h>

//Saves the score the score.dat
void	save_score(game_t *game)
{
	FILE	*stream;

	stream = fopen("score.dat", "wb");
	if (!stream)
		my_printf(ERR_SAVE_SCORE);
	else {
		fwrite(&game->maxscore, sizeof(game->maxscore), 1, stream);
		fclose(stream);
	}
}

//Loads the best score from score.dat
void	load_score(game_t *game)
{
	FILE	*stream;

	stream = fopen("score.dat", "rb");
	if (!stream) {
		my_printf(ERR_LOAD_SCORE);
		game->maxscore = 0;
	} else {
		fread(&game->maxscore, sizeof(game->maxscore), 1, stream);
		fclose(stream);
		my_printf("Highest score is now %u\n", game->maxscore);
	}
}
