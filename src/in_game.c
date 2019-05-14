/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** in_game
*/

#include "navy.h"

void handler_hit(int sig, siginfo_t *si, void *unused)
{
    if (sig == SIGUSR1)
        info.hit = 1;
    else if (sig == SIGUSR2)
        info.hit = 2;
}

int check_hit_or_miss(char **map, pid_t enemy_pid)
{
    int x = info.msg[0] - 65;
    int y = info.msg[1] - 49;

    if (map[y][x] == '.') {
        my_printf("%s: missed\n\n", info.msg);
        map[y][x] = 'o';
        kill(enemy_pid, SIGUSR1);
    } else {
        my_printf("%s: hit\n\n", info.msg);
        map[y][x] = 'x';
        kill(enemy_pid, SIGUSR2);
    }
    if (check_win(map) == 1)
        return (1);
    else
        return (0);
}

int wait_result(char *input, char **enemy_map)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler_hit;
    sigemptyset(&sa.sa_mask);
    while (info.hit == 0) {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
    }
    if (info.hit == 2) {
        my_printf("%s: hit\n\n", input);
        enemy_map[input[1] - 49][input[0] - 65] = 'x';
    } else {
        my_printf("%s: missed\n\n", input);
        enemy_map[input[1] - 49][input[0] - 65] = 'o';
    }
    if (check_win(enemy_map) == 1)
        return (1);
    else
        return (0);
}

int prepar_in_game(char **pos)
{
    pid_t enemy_pid = info.p1 == getpid() ? info.p2 : info.p1;
    char **enemy_map = malloc(sizeof(char *) * 11);
    char **map = create_map(pos);
    char *input = 0;

    enemy_map = fill_pos_empty(enemy_map);
    return (in_game(enemy_pid, enemy_map, map, input));
}

int in_game(pid_t enemy_pid, char **enemy_map, char **map, char *input)
{
    while (info.p1 == getpid()) {
        disp_maps(map, enemy_map);
        input = get_input();
        send_to_pid(enemy_pid, input);
        if (wait_result(input, enemy_map) != 0)
            return (0);
        receve_from_pid();
        if (check_hit_or_miss(map, enemy_pid) != 0)
            return (1);
    }
    while (info.p2 == getpid()) {
        disp_maps(map, enemy_map);
        receve_from_pid();
        if (check_hit_or_miss(map, enemy_pid) != 0)
            return (1);
        input = get_input();
        send_to_pid(enemy_pid, input);
        if (wait_result(input, enemy_map) != 0)
            return (0);
    }
}
