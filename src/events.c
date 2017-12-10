/*
** EPITECH PROJECT, 2017
** event
** File description:
** All that involve event managing
*/

#include <SFML/Graphics.h>
#include <time.h>
#include "structs.h"
#include "function.h"
#include "my.h"

void	display_mouse(game_t *game)
{
	sfSprite	*sprite1 = game->sprites[33].sprite;
	sfSprite	*sprite2 = game->sprites[34].sprite;
	sfSprite	*sprite = game->sprites[37].sprite;
	int		mx = game->mousex;
	int		my = game->mousey;
	sfVector2f	nul = {0, 0};
	sfVector2f	pos = {game->mousex - 15, game->mousey - 15};

	sfSprite_setScale(sprite1, (sfVector2f){4, 4});
	sfSprite_setScale(sprite2, (sfVector2f){4, 4});
	if (game->menu == 5) {
		if (mx >= 342 && mx <= 680 && my >= 496 && my <= 580)
			sfSprite_setPosition(sprite1, nul);
		else if (mx >= 342 && mx <= 680 && my >= 596 && my <= 680)
			sfSprite_setPosition(sprite2, nul);
	}
	sfSprite_setPosition(sprite, pos);
}

int	analyse_events(sfRenderWindow *window, sfEvent event, game_t *game)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		switch ((int)event.type) {
		case (int)sfEvtClosed:
			close_window(window);
			break;
		case (int)sfEvtMouseButtonPressed:
			modify_mouse_pos_press(&event, window, game);
			manage_mouse_click(window, game);
			break;
		case (int)sfEvtMouseMoved:
			modify_mouse_pos(&event, window, game);
		}
	}
	display_mouse(game);
	return (0);
}

int	manage_mouse_click(sfRenderWindow *window, game_t *game)
{
	int	mx = game->mousex;
	int	my = game->mousey;

	if (game->menu == 1) {
		game->var = 1 + !game->ducks[0].hit * 0.8;
		modify_duck_speed(game);
	} else if (game->menu == 5) {
		if (mx >= 342 && mx <= 680 && my >= 496 && my <= 580) {
			game->menu = 0;
			sfMusic_play(game->musics[0]);
			sfMusic_stop(game->musics[7]);
		} else if (mx >= 342 && mx <= 680 && my >= 596 && my <= 680)
			close_window(window);
	}
	return (0);
}

int	close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	return (0);
}
