/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "navy.h"

int main(int ac, char **av)
{
    char **pos;

    if (ac < 2) {
        my_printf("try with -h\n");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        display_help();
    if (ac == 2) {
        if ((pos = get_pos(av, ac)) == NULL) {
            write(2, "Bad map.\n", 9);
            return (84);
        }
        return (player_1(pos));
    } else if (ac == 3) {
        if ((pos = get_pos(av, ac)) == NULL) {
            write(2, "Bad map.\n", 9);
            return (84);
        }
        return (player_2(pos, av[1]));
    } else {
        my_printf("try with -h\n");
        return (84);
    }
    return (0);
}
