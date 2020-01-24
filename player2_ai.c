/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** just for that-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int ask_line2(int *p_line, int *map, int *lim)
{
    if (map[(*p_line - 1)] <= 0) {
        my_putstr("Error: there is no more matches on this line", 0);
        *p_line = 0;
        return ask_line(p_line, map, lim);
    }
    return 0;
}

int message(int p_line, int p_matches)
{
    my_putstr("Player removed", 1);
    my_put_nbr(p_matches);
    my_putstr(" match(es) from line", 1);
    my_put_nbr(p_line);
    my_putchar('\n');
}

int ai_message(int p_line, int p_matches)
{
    my_putstr("AI removed", 1);
    my_put_nbr(p_matches);
    my_putstr(" match(es) from line", 1);
    my_put_nbr(p_line);
    my_putchar('\n');
    return 0;
}

int ai_act(int *p_line, int *p_matches, int *map, int *a_space)
{
    map[(*p_line - 1)] -= *p_matches;
    a_space[(*p_line - 1)] += *p_matches;
    *p_line = 0;
    *p_matches = 0;
}

int ai(int *map, int *nb_l_max, int *p_line, int *p_matches)
{
    for (int i = (nb_l_max[0] - 1); i >= 0; i--)
        if (map[i] > 1)
            if ((map[i] - 1) > nb_l_max[1]) {
                *p_matches = nb_l_max[1];
                *p_line = (i + 1);
                return ai_message(*p_line, *p_matches);
            }
            else {
                *p_matches = (map[i] - 1);
                *p_line = (i + 1);
                return ai_message(*p_line, *p_matches);
            }
    if (*p_matches == 0)
        for (int i = (nb_l_max[0] - 1); i >= 0; i--)
            if (map[i] >= 1) {
                *p_matches = 1;
                *p_line = (i + 1);
                return ai_message(*p_line, *p_matches);
            }
}