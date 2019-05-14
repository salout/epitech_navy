/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** disp
*/

#include "navy.h"

void put_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
}

void disp_maps(char **map, char **enemy)
{
    int u = 0;
    char **disp = dispable();

    my_printf("my positions:\n%s\n%s", disp[0], disp[1]);
    for (int i = 2; i < 10; i++, u++) {
        my_printf("\n%s%c", disp[i], map[u][0]);
        for (int run = 1; map[u][run]; run++) {
            my_printf(" %c", map[u][run]);
        }
    }
    write(1, "\n\nenemy's positions:\n", 21);
    u = 0;
    my_printf("%s\n%s", disp[0], disp[1]);
    for (int i = 2; i < 10; i++, u++) {
        my_printf("\n%s%c", disp[i], enemy[u][0]);
        for (int run = 1; enemy[u][run]; run++) {
            my_printf(" %c", enemy[u][run]);
        }
    }
    write(1, "\n\n", 2);
}

void display_help(void)
{
    my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION");
    my_printf("\n     first_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n");
    my_printf("     navy_positions: file representing the positions");
    my_printf(" of the ships.\n");
}