/*
** EPITECH PROJECT, 2017
** main
** File description:
** main function of the project
*/

#include "function.h"
#include "my.h"
#include <stdlib.h>

void	display_description(void)
{
	my_printf("\tThe goal is to shoot the ducks. Each duck\n\t");
	my_printf("gives a number of points depending on its color\n\t");
	my_printf("and a bonus which is devided by 2 each time it\n\t");
	my_printf("reachs the border of the screen.\n\n\tAt the ");
	my_printf("beggining, you have 3 ammos. You loose one when\n\t");
	my_printf("you miss a duck. When no ammos are left, the score is\n\t");
	my_printf("saved if better than the highscore and the game restart.\n");
	my_printf("\n\tBlack ducks : \tBase points : 100\n");
	my_printf("\t\t\tBase bonus points : 50\n\t\t\tSpeed : normal\n");
	my_printf("\n\tRed ducks : \tBase points : 200\n");
	my_printf("\t\t\tBase bonus points : 150\n\t\t\tSpeed : 2x faster\n");
	my_printf("\n\tBlue ducks : \tBase points : 300\n");
	my_printf("\t\t\tBase bonus points : 300\n\t\t\tSpeed : 3x faster\n");
}

void	display_help(int argc, char **args)
{
	int	return_value = 0;

	for (int i = 1; i < argc; i++)
		if (!compare_strings(args[i], "-h")) {
			return_value = 84;
			my_printf("Invalid argument '%s'\n", args[i]);
			break;
		}
	my_printf("USAGE\n\t%s [-h]\n\n", args[0]);
	my_printf("DESCRIPTION\n\t-h : display this help\n\n");
	display_description();
	exit(return_value);
}

int	main(int argc, char **args)
{
	if (argc > 1)
		display_help(argc, args);
	my_hunter();
	return (0);
}
