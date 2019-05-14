/*
** EPITECH PROJECT, 2018
** decalage.c
** File description:
** dc
*/

#include "navy.h"

int count_char(char *str, char to_find) //add in lib
{
    int count = 0;
    int ite = 0;

    while (str[ite++])
        if (str[ite] == to_find)
            count += 1;
    return (count);
}

char *find_arg(char *input)
{
    char *buff = malloc(sizeof(char) * (count_char(input, '%') + 1));
    int input_ite = 0;
    int buff_ite = 0;

    while (input[input_ite++])
        if (input[input_ite] == '%')
            buff[buff_ite++] = input[input_ite + 1];
    buff[buff_ite] = '\0';
    return (buff);
}
