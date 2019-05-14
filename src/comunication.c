/*
** EPITECH PROJECT, 2018
** comunication.c
** File description:
**
*/

#include "navy.h"

void handler_message(int sig, siginfo_t *si, void *unused)
{
    static int i = 0;
    char a = 'A';
    char b = '1';

    if (sig == SIGUSR1 && i == 0)
        info.msg[i] = info.msg[i] != '\0' ? info.msg[i] + 1 : a;
    else if (sig == SIGUSR1 && i == 1)
        info.msg[i] = info.msg[i] != '\0' ? info.msg[i] + 1 : b;
    if (sig == SIGUSR2 && i == 0)
        i++;
    else if (sig == SIGUSR2 && i == 1) {
        i = 0;
        info.msg[2] = 'O';
        info.msg[3] = '\0';
    }
}

void send_to_pid(pid_t pid, char *mes)
{
    for (int i = mes[0] - 64; i != 0; i--) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
    kill(pid, SIGUSR2);
    usleep(1000);
    for (int i = mes[1] - 48; i != 0; i--) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
    kill(pid, SIGUSR2);
}

void receve_from_pid(void)
{
    struct sigaction sa;

    my_printf("waiting for enemy's attack...\n");
    info.msg = malloc(sizeof (char) * 3);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler_message;
    sigemptyset(&sa.sa_mask);
    while (my_strlen(info.msg) != 3) {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
    }
    info.msg[2] = '\0';
}
