/*
** EPITECH PROJECT, 2017
** reset_sprite_pos
** File description:
** sets all sprites pos out of the screen
*/

#include "structs.h"
#include <SFML/Graphics.h>

void	reset_sprite_pos(sprite_f *sprites, int nb)
{
	sfVector2f	pos = {1000, 1000};

	for (int i = 0; i < nb; i++)
		sfSprite_setPosition(sprites[i].sprite, pos);
}
