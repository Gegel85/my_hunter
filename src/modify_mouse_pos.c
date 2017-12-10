/*
** EPITECH PROJECT, 2017
** modify_mouse_pos
** File description:
** Modify the position of the cursor
*/

#include <SFML/Graphics.h>
#include "structs.h"

void	modify_mouse_pos(sfEvent *event, sfRenderWindow *window, game_t *game)
{
	sfVector2f      mpr;
	sfVector2i      mp;
	const sfView    *v = sfRenderWindow_getView(window);
	sfRenderWindow  *w = window;

	mp = (sfVector2i){event->mouseMove.x, event->mouseMove.y};
	mpr = sfRenderWindow_mapPixelToCoords(w, mp, v);
	game->mousex = mpr.x;
	game->mousey = mpr.y;
	if (game->cheat)
		if (game->menu == 1) {
			game->mousex = game->ducks[0].x + 75;
			game->mousey = game->ducks[0].y + 100;
		}
}

void	modify_mouse_pos_press(sfEvent *e, sfRenderWindow *window, game_t *game)
{
	sfVector2f      mpr;
	sfVector2i      mp;
	const sfView    *v = sfRenderWindow_getView(window);
	sfRenderWindow  *w = window;

	mp = (sfVector2i){e->mouseButton.x, e->mouseButton.y};
	mpr = sfRenderWindow_mapPixelToCoords(w, mp, v);
	game->mousex = mpr.x;
	game->mousey = mpr.y;
	if (game->cheat)
		if (game->menu == 1) {
			game->mousex = game->ducks[0].x + 75;
			game->mousey = game->ducks[0].y + 100;
		}
}
