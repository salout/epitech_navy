/*
** EPITECH PROJECT, 2018
** add boat
** File description:
** add_boat
*/

#include "navy.h"

char **puty_in_map(int x, int y, char **map, char *pos)
{
    int len = pos[0] - 48;

    for (int i = 0; i != len; y++, i++)
        map[y][x] = pos[0];
    return (map);
}

char **putx_in_map(int x, int y, char **map, char *pos)
{
    int len = pos[0] - 48;

    for (int i = 0; i != len; x++, i++)
        map[y][x] = pos[0];
    return (map);
}

char **add_boat(char **map, char *pos)
{
    int s_x = 0;
    int s_y = 0;

    if (pos[2] == pos[5]) {
        s_x = pos[2] - 65;
        if (pos[3] < pos[6])
            s_y = pos[3] - 49;
        else
            s_y = pos[6] - 47;
        return (puty_in_map(s_x, s_y, map, pos));
    }
    else {
        s_y = (pos[3]) - 49;
        if (pos[2] < pos[5])
            s_x = pos[2] - 65;
        else
            s_x = pos[5] - 65;
        return (putx_in_map(s_x, s_y, map, pos));
    }
}