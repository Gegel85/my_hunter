/*
** EPITECH PROJECT, 2017
** sprites
** File description:
** sprites loading and changing
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "function.h"
#include "structs.h"
#include "global2.h"
#include "my.h"


//Display a sprite on screen at the given position
void	image(sfRenderWindow *window, sfSprite *sprite, sfVector2f pos)
{
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(window, sprite, NULL);
}


//Create a new sprite from the config
sprite_f	create_sprite(sprite_conf config)
{
	sfTexture	*texture;
	sfSprite	*sprite = sfSprite_create();
	sprite_f	sprite_full;
	sfIntRect	rect = {0, 0, config.width, config.height};

	if (!sprite)
		exit(EXIT_FAILURE);
	texture = sfTexture_createFromFile(config.file_path, NULL);
	if (!texture) {
		my_printf("Error: Cannot load file %s\n", config.file_path);
		exit(EXIT_FAILURE);
	}
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setScale(sprite, config.scale);
	sprite_full.sprite = sprite;
	sprite_full.texture = texture;
	sprite_full.rect = rect;
	sfSprite_setTextureRect(sprite, rect);
	return (sprite_full);
}

//Reset all vars
void	reset_game(game_t *game)
{
	for (int i = 0; i < 3; i++) {
		game->ducks[i].x = 10000 * (i + i);
		game->ducks[i].y = 0;
		game->ducks[i].state = 0;
		game->ducks[i].type = rand() % 3;
		game->ducks[i].hit = 0;
		if (game->ducks[i].clock)
			sfClock_destroy(game->ducks[i].clock);
		game->ducks[i].clock = sfClock_create();
	}
	game->dog.x = 0;
	game->dog.y = 575;
	game->dog.speed = -175;
	game->dog.animation = 0;
	game->background = rand() % 6;
	game->speed = 10;
	game->var = 0.1;
	game->bonus = init_bonus(game->ducks[0].type);
	game->intro = 0;
	game->menu = 5;
	game->randomMultiplicator = 50;
	game->combo = 0;
	game->score = 0;
}

//Create all game objects and init vars
sprite_f	*create_things(game_t *game, int nb)
{
	sprite_f	*sprites = malloc(nb * sizeof(*sprites));

	srand(time(NULL));
	game->ducks = malloc(3 * sizeof(*game->ducks));
	if (!game->ducks)
		exit(EXIT_FAILURE);
	memset(game->ducks, 0, 3 * sizeof(*game->ducks));
	for (int i = 0; i < nb; i++)
		sprites[i] = create_sprite(s_config[i]);
	load_sounds(game);
	load_score(game);
	game->mousex = 0;
	game->mousey = 0;
	game->miss = 0;
	game->clock = sfClock_create();
	reset_game(game);
	return (sprites);
}
