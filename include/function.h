/*
** EPITECH PROJECT, 2017
** functions header
** File description:
** contains functions' prototypes
*/

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <SFML/Graphics.h>
#include "structs.h"

int		analyse_events(sfRenderWindow *window, game_t *game);
int		manage_mouse_click(sfRenderWindow *window, game_t *game);
int		manage_keyboard(sfEvent event, game_t *game);
int		close_window(sfRenderWindow *window);
unsigned int	init_bonus(int duck_type);
int		rand(void);
int		modify_duck_speed(game_t *game);
void		reset_game(game_t *game);
void		reset_sprite_pos(sprite_f *sprites, int nb);
void		change_sprites(game_t *game);
void		display_sprites(sfRenderWindow *win, sprite_f *sprites, int nb);
void		load_sounds(game_t *game);
void		change_duck_state(duck *ducks);
void		draw_bg(game_t *game);
void		update_dog(game_t *game);
void		change_menus(game_t *game);
void		load_score(game_t *game);
void		save_score(game_t *game);
void		game_over(game_t *game);
void		duck_fall(game_t *game);
void		show_dog(game_t *game);
void		create_type(duck *duck);
void		show_hscore(game_t *game);
void		show_score(game_t *game);
void		display_bonus(game_t *game);
void		show_ammos(game_t *game);
void		modify_mouse_pos(sfEvent *ev, sfRenderWindow *win, game_t *g);
void		my_hunter(game_t *game_struct);
void		update_ducks(game_t *game);
void		menu(game_t *game);
void		display_combo(game_t *game);
void		modify_mouse_pos_press(sfEvent *event, sfRenderWindow *window, game_t *game);
void		change_nb_sprite_rect(int value, game_t *game, int sprite_id);
sprite_f	create_sprite(sprite_conf config);
sprite_f	*create_things(game_t *game, int nb);
sprite_conf	*get_sprites_conf(sprite_conf *configs);
void		image(sfRenderWindow *window, sfSprite *sprite, sfVector2f pos);
void		draw_score(game_t *game, unsigned int score, sfVector2f pos, int s_id);

#endif
