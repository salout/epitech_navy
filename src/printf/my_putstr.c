/*
** EPITECH PROJECT, 2019
** put str
** File description:
** disp string
*/

#include "printf.h"
#include "navy.h"

int my_putchar(char);

void convert_octal(unsigned int num);

int my_putstr(char const *str)
{
    int len = 1;

    for (; str[len]; len += 1);
    write(1, str, len);
    return (0);
}

void put_non_printable(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            convert_octal(str[i]);
        }
        else
            my_putchar(str[i]);
    }
}
