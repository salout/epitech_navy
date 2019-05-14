/*
** EPITECH PROJECT, 2017
** win_condition.c
** File description:
**
*/

#include "navy.h"

int check_win(char **map)
{
    int cross = 0;

    for (int i = 0; map[i]; i++)
        for (int x = 0; map[i][x]; x++)
            if (map[i][x] == 'x')
                cross++;
    if (cross == 14)
        return (1);
    else
        return (0);
}
