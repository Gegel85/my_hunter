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
#include <fcntl.h>

void	save_score(game_t *game)
{
	int	fd;

	fd = open("score.dat", O_WRONLY | O_CREAT, 0664);
	if (fd == -1)
		my_printf(ERR_SAVE_SCORE);
	else {
		write(fd, &game->maxscore, sizeof(game->maxscore));
		close(fd);
	}
}

void	load_score(game_t *game)
{
	int	fd;

	fd = open("score.dat", O_RDONLY);
	if (fd == -1) {
		my_printf(ERR_LOAD_SCORE);
		game->maxscore = 0;
	} else {
		read(fd, &game->maxscore, sizeof(game->maxscore));
		close(fd);
		my_printf("Highest score is now %u\n", game->maxscore);
	}
}
