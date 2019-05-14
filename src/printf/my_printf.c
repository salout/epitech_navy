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
void convert_octal(unsigned int num);
void convert_binary(unsigned int num);
void put_non_printable(char *str);
void convert_dec_to_rec(unsigned int, int);
void convert_dec_to_hexa_rec(unsigned int, int);

void disgusting_p3(va_list *ap, char fmt)
{
    switch (fmt) {
        case 'p' :
            my_putstr("0x");
            convert_dec_to_hexa_rec(va_arg(*ap, unsigned int), 0);
            break;
    }
}

void disgusting_p2(va_list *ap, char fmt)
{
    switch (fmt) {
        case 'S' :
            put_non_printable(va_arg(*ap, char *));
            break;
        case '%' :
            my_putchar('%');
            break;
        case 'o' :
            convert_octal(va_arg(*ap, unsigned int));
            break;
        case 'x' :
            convert_dec_to_hexa_rec(va_arg(*ap, unsigned int), 0);
            break;
        case 'X' :
            convert_dec_to_rec(va_arg(*ap, unsigned int), 0);
            break;
    }
    disgusting_p3(ap, fmt);
}

void disgusting(va_list *ap, char fmt)
{
    switch (fmt) {
        case 'd' :
            my_put_nbr(va_arg(*ap, int));
            break;
        case 'i' :
            my_put_nbr(va_arg(*ap, int));
            break;
        case 's' :
            my_putstr(va_arg(*ap, char *));
            break;
        case 'c' :
            my_putchar(va_arg(*ap, int));
            break;
        case 'b' :
            convert_binary(va_arg(*ap, unsigned int));
            break;
    }
    disgusting_p2(ap, fmt);
}

int my_printf(const char *str, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, str);
    while (str[i]) {
        if (str[i] == '%') {
            disgusting(&ap, str[i + 1]);
            i += 1;
        } else
            my_putchar(str[i]);
        i += 1;
        count += 1;
    }
    va_end(ap);
    return (count);
}
