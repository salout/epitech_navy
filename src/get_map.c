/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** get_map
*/

#include "navy.h"

char **fill_pos_empty(char **pos)
{
    pos[0] = my_strdup("........\0");
    pos[1] = my_strdup("........\0");
    pos[2] = my_strdup("........\0");
    pos[3] = my_strdup("........\0");
    pos[4] = my_strdup("........\0");
    pos[5] = my_strdup("........\0");
    pos[6] = my_strdup("........\0");
    pos[7] = my_strdup("........\0");
    pos[8] = NULL;
    return (pos);
}

char **dispable(void)
{
    char **map = malloc(sizeof (char *) * 11);

    map[0] = my_strdup(" |A B C D E F G H\0");
    map[1] = my_strdup("-+---------------\0");
    map[2] = my_strdup("1|\0");
    map[3] = my_strdup("2|\0");
    map[4] = my_strdup("3|\0");
    map[5] = my_strdup("4|\0");
    map[6] = my_strdup("5|\0");
    map[7] = my_strdup("6|\0");
    map[8] = my_strdup("7|\0");
    map[9] = my_strdup("8|\0");
    map[10] = NULL;
    return (map);
}

char **create_map(char **pos)
{
    char **map = malloc(sizeof(char *) * 11);

    map = fill_pos_empty(map);
    for (int i = 0; pos[i]; i++)
        map = add_boat(map, pos[i]);
    return (map);
}
