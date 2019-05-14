/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <ucontext.h>
#include "in_game.h"
#include <struct.h>

int my_strlen(char *);
int player_1(char **);
int check_win(char **);
void receve_from_pid(void);
void send_to_pid(pid_t, char *);
int my_printf(const char *, ...);
int player_2(char **, char *);
int my_getnbr(char const *);
char **create_map(char **);
char *my_strdup(char *);
char **add_boat(char **, char *);
char *get_next_line(int);
void disp_maps(char **, char **);
char **get_pos(char **, int);
void display_help(void);
char **fill_pos_empty(char **);
char **add_boat(char **, char *);
char **dispable(void);

#endif
