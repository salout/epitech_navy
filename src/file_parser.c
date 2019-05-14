/*
** EPITECH PROJECT, 2018
** file_parser.c
** File description:
**
*/

#include "navy.h"

int check_cor(char c)
{
    if ((c >= 'A' && c <= 'H') || c == ':')
        return (1);
    else if (c >= '1' && c <= '8')
        return (1);
    else
        return (0);
}

int check_pos(char *pos, int x)
{
    if (pos[0] - 48 != x)
        return (0);
    for (int i = 1; pos[i]; i++) {
        if (i == 1 && pos[i] != ':')
            return (0);
        else if (i == 4 && pos[i] != ':')
            return (0);
        else if (check_cor(pos[i]) == 0)
            return (0);
    }
    return (1);
}

char **get_pos(char **av, int ac)
{
    char **pos = malloc(sizeof (char *) * 5);
    char *temp;
    int i = 0;
    int fd = ac == 2 ? open(av[1], O_RDONLY) : open(av[2], O_RDONLY);

    if (fd == -1)
        return (NULL);
    while ((temp = get_next_line(fd)) != NULL)
        pos[i++] = temp;
    i = 0;
    for (int x = 2; pos[i] != NULL; x++)
        if (check_pos(pos[i++], x) == 0)
            return (NULL);
    return (pos);
}
