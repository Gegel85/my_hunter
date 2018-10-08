/*
** EPITECH PROJECT, 2017
** my_hunter.c
** File description:
** Main function for the project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "structs.h"
#include "function.h"
#include "my.h"
#include "macros.h"

void	verify_score(game_t *game)
{
	int	miss = game->miss;
	int	score = game->score;

	if (game->score > game->maxscore) {
		game->maxscore = game->score;
		my_printf("New highest score !\n");
	}
	my_printf("Final score : %u\nFinal missed : %i\n", score, miss);
	my_printf("Highest score of this session was %u !\n", game->maxscore);
}

void	free_csfml(game_t *game, int nb)
{
	for (int i = 0; i < nb; i++)
		if (game->sprites[i].sprite)
			sfSprite_destroy(game->sprites[i].sprite);
	for (int i = 0; i < nb; i++)
		if (game->sprites[i].texture)
			sfTexture_destroy(game->sprites[i].texture);
	for (int i = 0; i < 3; i++)
		if (game->ducks[i].clock)
			sfClock_destroy(game->ducks[i].clock);
	for (int i = 0; i < 8; i++)
		if (game->musics[i])
			sfMusic_destroy(game->musics[i]);
}

void	destroy_all(game_t *game, int nb, sfRenderWindow *window)
{
	verify_score(game);
	if (game->cheat)
		my_printf("Score is not saved in cheat mode !\n");
	else
		save_score(game);
	free_csfml(game, nb);
	sfClock_destroy(game->clock);
	free(game->ducks);
	free(game->sprites);
	sfRenderWindow_destroy(window);
}

void	my_hunter(game_t *game_struct)
{
	sfVideoMode	mode = {1024, 800, 32};
	sfRenderWindow	*window;
	game_t		game = *game_struct;
	int		nb_sprite = 42;
	sfImage		*icon = sfImage_createFromFile("sprites/icon.png");

	window = sfRenderWindow_create(mode, "my_hunter", 6, NULL);
	if (!window)
		exit(EXIT_FAILURE);
	if (icon)
		sfRenderWindow_setIcon(window, 32, 32, sfImage_getPixelsPtr(icon));
	sfRenderWindow_setFramerateLimit(window, 30);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	game.sprites = create_things(&game, nb_sprite);
	game.window = window;
	sfMusic_play(game.musics[7]);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, (sfColor){0, 0, 0, 255});
		change_sprites(&game);
		analyse_events(window, &game);
		sfRenderWindow_display(window);
	}
	destroy_all(&game, nb_sprite, window);
}
