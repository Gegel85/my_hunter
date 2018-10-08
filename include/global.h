/*
** EPITECH PROJECT, 2017
** global
** File description:
** global variable
*/

#ifndef _GLOB_H_
#define _GLOB_H_

#include "structs.h"
#include "function.h"

//Game menus functions
void	(*game_fcts[])(game_t *) = {
	&update_dog,
	&update_ducks,
	&game_over,
	&duck_fall,
	&show_dog,
	&menu
};

#endif
