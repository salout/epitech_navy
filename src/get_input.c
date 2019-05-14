/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** get_input
*/

#include "navy.h"

int check_letter(char c)
{
    char good[8] = "ABCDEFGH";

    for (int i = 0; i < 8; i++)
        if (c == good[i])
            return (1);
    return (0);
}

int check_num(char c)
{
    char good[8] = "12345678";

    for (int i = 0; i < 8; i++)
        if (c == good[i])
            return (1);
    return (-1);
}

char *get_input(void)
{
    char *buf = 0;

    do {
        my_printf("attack: ");
        buf = get_next_line(0);
    } while (check_letter(buf[0]) != 1 || check_num(buf[1]) != 1);
    info.hit = 0;
    return (buf);
}
