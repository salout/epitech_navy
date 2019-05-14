/*
** EPITECH PROJECT, 2018
** parenthesis.c
** File description:
** functions to handle parenthesis
*/

#include "printf.h"

void my_putchar(char);
void my_putstr(char *);
void my_put_nbr(int);

void convert_dec_to_rec(unsigned int retain, int ite)
{
    unsigned int remain = retain % 16;
    char *num = "0123456789ABCDEF";

    if (retain > 0) {
        convert_dec_to_rec(retain / 16, ite++);
    }
    if (ite != 0 || (ite == 0 && remain != 0))
        my_putchar(num[remain]);
}

void convert_dec_to_hexa_rec(unsigned int retain, int ite)
{
    unsigned int remain = retain % 16;
    char *num = "0123456789abcdef";

    if (retain > 0) {
        convert_dec_to_hexa_rec(retain / 16, ite++);
    }
    if (ite != 0 || (ite == 0 && remain != 0))
        my_putchar(num[remain]);
}
