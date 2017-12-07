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

void	destroy_all(game_t *game, int nb, sfRenderWindow *window)
{
	verify_score(game);
	save_score(game);
	for (int i = 0; i < nb; i++)
		sfSprite_destroy(game->sprites[i].sprite);
	for (int i = 0; i < nb; i++)
		sfTexture_destroy(game->sprites[i].texture);
	for (int i = 0; i < 3; i++)
		sfClock_destroy(game->ducks[i].clock);
	for (int i = 0; i < 8; i++)
		sfMusic_destroy(game->musics[i]);
	sfClock_destroy(game->clock);
	free(game->ducks);
	free(game->sprites);
	sfRenderWindow_destroy(window);
}

void	my_hunter(void)
{
	sfEvent		event;
	sfVideoMode	mode = {1024, 800, 32};
	sfRenderWindow	*window;
	game_t		game;
	int		nb_sprite = 37;

	window = sfRenderWindow_create(mode, "my_hunter", 6, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        game.sprites = create_things(&game, nb_sprite);
	sfMusic_play(game.musics[7]);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		change_sprites(game.sprites, &game, nb_sprite);
		analyse_events(window, event, &game);
		display_sprites(window, game.sprites, nb_sprite);
		sfRenderWindow_display(window);
	}
	destroy_all(&game, nb_sprite, window);
}
