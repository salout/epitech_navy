/*
** EPITECH PROJECT, 2018
** parenthesis.c
** File description:
** functions to handle parenthesis
*/

int my_putchar(char c);

int my_put_nbr(int nb)
{
    int num;

    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            num = nb % 10;
            nb = nb - num;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + num);
        }
        else {
            my_putchar(48 + nb);
        }
    }
    return (0);
}
