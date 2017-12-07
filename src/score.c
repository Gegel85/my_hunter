/*
** EPITECH PROJECT, 2017
** score
** File description:
** Showing score and highscore
*/

#include <SFML/Graphics.h>
#include "structs.h"

void	change_nb_sprite_rect(int value, game_t *game, int sprite_id)
{
	game->sprites[sprite_id].rect.top = 0;
	game->sprites[sprite_id].rect.left = 8 * value;
	game->sprites[sprite_id].rect.width = 8;
	game->sprites[sprite_id].rect.height = 8;
}

void	init_score(game_t *game, sfVector2f pos, int sprite_id)
{
	for (int i = sprite_id; i < sprite_id + 6; i++) {
		sfSprite_setScale(game->sprites[i].sprite, (sfVector2f){4, 4});
		sfSprite_setPosition(game->sprites[i].sprite, pos);
		change_nb_sprite_rect(0, game, i);
		pos.x += 32;
	}
}

void	draw_score(game_t *game, unsigned int score, sfVector2f pos, int s_id)
{
	init_score(game, pos, s_id);
	for (int i = s_id + 5; score > 0 && i >= 0; i--) {
		change_nb_sprite_rect(score % 10 + 1, game, i);
		score /= 10;
	}
}

void	show_hscore(game_t *game)
{
	sfVector2f	pos = {829, 732};

	if (game->menu == 5)
		pos = (sfVector2f){604, 732};
	sfSprite_setScale(game->sprites[16].sprite, (sfVector2f){4, 4});
	sfSprite_setPosition(game->sprites[16].sprite, pos);
	draw_score(game, game->maxscore, pos, 23);
}

void	show_score(game_t *game)
{
	sfVector2f	pos = {0, 732};

	sfSprite_setScale(game->sprites[9].sprite, (sfVector2f){4, 4});
	sfSprite_setPosition(game->sprites[9].sprite, pos);
	draw_score(game, game->score, pos, 10);
}
