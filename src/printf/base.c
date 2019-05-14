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

unsigned int powa(unsigned int num, int pow)
{
    unsigned int res = num;

    if (pow == 0)
        return (1);
    for (int i = 1; i < pow; i++)
        res *= num;
    return (res);
}

void convert_dec_to_base_rec(unsigned int retain, int base, int ite)
{
    unsigned int remain = retain % base;

    if (retain > 0) {
        convert_dec_to_base_rec(retain / base, base, ite++);
    }
    if (ite != 0 || (ite == 0 && remain != 0))
        my_putchar(remain + 48);
}

void convert_octal(unsigned int num)
{
    convert_dec_to_base_rec(num, 8, 0);
}

void convert_binary(unsigned int num)
{
    convert_dec_to_base_rec(num, 2, 0);
}