/*
** EPITECH PROJECT, 2017
** sounds
** File description:
** Everything related to sounds
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "structs.h"

void	load_sounds(game_t *game)
{
	game->musics = malloc(sizeof(*game->musics) * 8);
	game->musics[0] = sfMusic_createFromFile("sound/02-duckhunt-intro.ogg");
	game->musics[1] = sfMusic_createFromFile("sound/04-got-duck.ogg");
	game->musics[2] = sfMusic_createFromFile("sound/06-perfect.ogg");
	game->musics[3] = sfMusic_createFromFile("sound/08-game-over.ogg");
	game->musics[4] = sfMusic_createFromFile("sound/99-duck-falls-sfx.ogg");
	game->musics[5] = sfMusic_createFromFile("sound/99-duck-lands-sfx.ogg");
	game->musics[6] = sfMusic_createFromFile("sound/99-gunshot-sfx.ogg");
	game->musics[7] = sfMusic_createFromFile("sound/01-title-screen.ogg");
	for (int i = 0; i < 8; i++) {
		if (!game->musics[i]) {
			my_printf("Error: Cannot load a sound file\n");
			exit(EXIT_FAILURE);
		}
	}
	sfMusic_setLoop(game->musics[7], sfTrue);
}
