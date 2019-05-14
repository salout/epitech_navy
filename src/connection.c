/*
** EPITECH PROJECT, 2019
** connection
** File description:
** connect to the other player
*/

#include "navy.h"

void handler(int sig, siginfo_t *si, void *unused)
{
    if (info.p2 == 0)
        info.p2 = si->si_pid;
}

int player_1(char **pos)
{
    struct sigaction sa;

    info.p1 = getpid();
    info.p2 = 0;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    my_printf("my_pid:  %d\nwaiting for enemy connection...\n", info.p1);
    while (info.p2 == 0)
        sigaction(SIGUSR1, &sa, NULL);
    my_printf("\nenemy connected\n\n");
    kill(info.p2, SIGUSR1);
    if (prepar_in_game(pos) == 0) {
        my_printf("I won\n");
        return (0);
    } else {
        my_printf("Enemy won\n");
        return (1);
    }
}

int player_2(char **pos, char *av)
{
    info.p2 = 0;
    info.p1 = my_getnbr(av);
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    my_printf("my_pid:  %d\n", getpid());
    kill(info.p1, SIGUSR1);
    while (info.p2 == 0)
        sigaction(SIGUSR1, &sa, NULL);
    info.p2 = getpid();
    my_printf("successfully connected\n\n");
    if (prepar_in_game(pos) == 0) {
        my_printf("I won\n");
        return (0);
    } else {
        my_printf("Enemy won\n");
        return (1);
    }
}
