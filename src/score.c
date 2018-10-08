/*
** EPITECH PROJECT, 2017
** score
** File description:
** Showing score and highscore
*/

#include <SFML/Graphics.h>
#include "structs.h"
#include "function.h"

void	change_nb_sprite_rect(int value, game_t *game, int sprite_id)
{
	game->sprites[sprite_id].rect.top = 0;
	game->sprites[sprite_id].rect.left = 8 * value;
	game->sprites[sprite_id].rect.width = 8;
	game->sprites[sprite_id].rect.height = 8;
	sfSprite_setTextureRect(game->sprites[sprite_id].sprite, game->sprites[sprite_id].rect);
}

void	draw_score(game_t *game, unsigned int score, sfVector2f pos, int s_id)
{
	sfSprite_setScale(game->sprites[s_id].sprite, (sfVector2f){4, 4});
	pos.x += 32 * 5;
	for (int i = 0; score > 0 || i < 6; i++) {
		change_nb_sprite_rect(score == 0 ? 0 : score % 10 + 1, game, s_id);
		image(game->window,game->sprites[s_id].sprite, pos);
		pos.x -= 32;
		score /= 10;
	}
}

void	show_hscore(game_t *game)
{
	sfVector2f	pos = {829, 10};

	if (game->cheat) {
		sfSprite_setScale(game->sprites[41].sprite, (sfVector2f){4, 4});
		image(game->window,game->sprites[41].sprite, pos);
	}
	pos = (sfVector2f){829, 732};
	if (game->menu == 5)
		pos = (sfVector2f){604, 732};
	sfSprite_setScale(game->sprites[16].sprite, (sfVector2f){4, 4});
	image(game->window,game->sprites[16].sprite, pos);
	draw_score(game, game->maxscore, pos, 23);
}

void	show_score(game_t *game)
{
	sfVector2f	pos = {0, 732};

	if (game->menu != 5) {
		display_combo(game);
		sfSprite_setScale(game->sprites[9].sprite, (sfVector2f){4, 4});
		image(game->window,game->sprites[9].sprite, pos);
		draw_score(game, game->score, pos, 10);
	}
}
