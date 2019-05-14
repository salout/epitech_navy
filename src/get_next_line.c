/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
**
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++);
    return (i);
}

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (;src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

char *get_line(char *line, int cursor, char *buff, int *begin)
{
    char *newline;
    int oldlen;

    oldlen = line != 0 ? my_strlen(line) : 0;
    newline = malloc(sizeof (char) * oldlen + cursor + 1);
    line != 0 ? my_strncpy(newline, line, oldlen) : \
    my_strncpy(newline, "", oldlen);
    newline[oldlen + cursor] = 0;
    my_strncpy(newline + oldlen, buff + *begin, cursor);
    if (line)
        free(line);
    *begin = *begin + (cursor + 1);
    return (newline);
}

char *get_next_line(int fd)
{
    static char buff[4069];
    static int size = 0;
    static int begin;
    int cursor = 0;
    char *line = NULL;

    for (; 1; cursor++) {
        if (size <= begin) {
            begin = 0;
            if ((size = read(fd, buff, 4069)) == 0)
                return (line);
            if (size == -1)
                return (NULL);
            cursor = 0;
        }
        if (buff[begin + cursor] == '\n')
            return (get_line(line, cursor, buff, &begin));
        if (begin + cursor == size - 1)
            line = get_line(line, cursor + 1, buff, &begin);
    }
}
