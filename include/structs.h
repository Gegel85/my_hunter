/*
** EPITECH PROJECT, 2017
** structs.h
** File description:
** All the structures of the project
*/

#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct {
	char	*file_path;
	int	width;
	int	height;
} sprite_conf;

typedef struct {
	sfSprite	*sprite;
	sfTexture	*texture;
	sfIntRect	rect;
} sprite_f;

typedef struct {
	int	x;
	int	y;
	int	state;
	int	type;
	int	hit;
	sfClock	*clock;
} duck;

typedef struct {
	int	x;
	int	y;
	float	speed;
	int	animation;
} dog_t;

typedef struct {
	int		menu;
	int		intro;
	int		background;
	float		mousex;
	float		mousey;
	int		speed;
	int		miss;
        duck		*ducks;
	dog_t		dog;
	float		var;
	sfClock		*clock;
	sfFont		*font;
	sfMusic		**musics;
	sprite_f	*sprites;
	unsigned int	bonus;
	unsigned int	score;
	unsigned int	maxscore;
} game_t;

#endif
