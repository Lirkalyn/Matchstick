/*
** EPITECH PROJECT, 2020
** mathstick
** File description:
** exterminate-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int m_check(char *str1)
{
    int test = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if ((str1[i] >= '0' && str1[i] <= '9') ||  str1[i] == '\n')
            test += 1;
        else if (i == 0 && (str1[i] == '-' || str1[i] == '+'))
            test += 1;
        else
            return 1;
    }
    return 0;
}

int m_convert(char *str1, int *nb1)
{
    if (m_check(str1))
        return 1;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] >= '0' && str1[i] <= '9') {
            *nb1 *= 10;
            *nb1 += (str1[i] - '0');
        }
    if (str1[0] == '-')
        return 1;
    return 0;
}

int ask_line(int *p_line, int *map, int *lim)
{
    char *line = NULL;
    size_t size;

    my_putstr("Line:", 1);
    if (getline(&line, &size, stdin) == -1)
        return 84;
    if (m_convert(line, p_line) == 1) {
        my_putstr("Error: invalid input (positive number expected)", 0);
        *p_line = 0;
        ask_line(p_line, map, lim);
    }
    else if (*p_line == 0 || *p_line > lim[0]) {
        my_putstr("Error: this line is out of range", 0);
        *p_line = 0;
        ask_line(p_line, map, lim);
    }
    ask_line2(p_line, map, lim);
    return 0;
}

int ask_matches2(int *p_line, int *p_matches, int *map, int *lim)
{
    if (*p_matches > lim[1]) {
        my_putstr("Error: you cannot remove more than", 1);
        my_put_nbr(lim[1]);
        my_putstr(" matches per turn", 0);
        *p_matches = 0;
        ask_matches(p_line, p_matches, map, lim);
    }
    else if (*p_matches > map[(*p_line - 1)]) {
        my_putstr("Error: not enough matches on this line", 0);
        *p_matches = 0;
        ask_matches(p_line, p_matches, map, lim);
    }
}

int ask_matches(int *p_line, int *p_matches, int *map, int *lim)
{
    char *line = NULL;
    size_t size;

    my_putstr("Matches:", 1);
    if (getline(&line, &size, stdin) == -1)
        return 84;
    if (m_convert(line, p_matches) == 1) {
        my_putstr("Error: invalid input (positive number expected)", 0);
        *p_matches = 0;
        ask_matches(p_line, p_matches, map, lim);
    }
    else if (*p_matches == 0) {
        my_putstr("Error: you have to remove at least one match", 0);
        *p_matches = 0;
        ask_matches(p_line, p_matches, map, lim);
    }
    ask_matches2(p_line, p_matches, map, lim);
    return 0;
}