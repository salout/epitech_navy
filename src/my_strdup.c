/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** duplicate a string
*/

#include "navy.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *buff = 0;
    int len = 0;

    for (; src[len]; len += 1);
    buff = malloc(sizeof(char) * (len + 2));
    for (; src[i]; i += 1)
        buff[i] = src[i];
    buff[i] = 0;
    return (buff);
}