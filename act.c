/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** let's do it-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int act(int *p_line, int *p_matches, int *map, int *a_space)
{
    message(*p_line, *p_matches);
    map[(*p_line - 1)] -= *p_matches;
    a_space[(*p_line - 1)] += *p_matches;
    *p_line = 0;
    *p_matches = 0;
}

int mallocer(int lim, int **b_space, int **a_space)
{
    *b_space = (int *)malloc(lim * sizeof(int));
    *a_space = (int *)malloc(lim * sizeof(int));
    if (*b_space == NULL || *a_space == NULL)
        return 84;
    return 0;
}

int spacer(int *map, int lim, int *b_space, int *a_space)
{
    int space = 0;

    for (int i = 0; i < lim; i++) {
        space = ((map[lim] - map[i]) / 2);
        b_space[i] = space;
        a_space[i] = space;
    }
}

int over(int *map, int lim)
{
    for (int i = 0; i < lim; i++)
        if (map[i] > 0)
            return 1;
    return 0;
}

int loop(int *nb_l_max, int *map, int *b_space, int *a_space)
{
    int p_line = 0;
    int p_matches = 0;

    while (over(map, nb_l_max[0]) == 1) {
        my_putstr("\nYour turn:", 0);
        if (ask_line(&p_line, map, nb_l_max) == 84)
            return 0;
        else if (ask_matches(&p_line, &p_matches, map, nb_l_max) == 84)
            return 0;
        act(&p_line, &p_matches, map, a_space);
        map_displayer(map, nb_l_max[0], b_space, a_space);
        if (over(map, nb_l_max[0]) == 0)
            return 2;
        my_putstr("\nAI's turn...", 0);
        ai(map, nb_l_max, &p_line, &p_matches);
        ai_act(&p_line, &p_matches, map, a_space);
        map_displayer(map, nb_l_max[0], b_space, a_space);
        if (over(map, nb_l_max[0]) == 0)
            return 1;
    }
}