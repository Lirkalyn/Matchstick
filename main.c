/*
** EPITECH PROJECT, 2020
** mathstick
** File description:
** stick-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int check(char *str1, char *str2)
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
    for (int i = 0; str2[i] != '\0'; i++) {
        if ((str2[i] >= '0' && str2[i] <= '9') || str2[i] == '\n')
            test += 1;
        else if (i == 0 && (str2[i] == '-' || str2[i] == '+'))
            test += 1;
        else
            return 1;
    }
    return 0;
}

int convert(char *str1, char *str2, int *nb1, int *nb2)
{
    if (check(str1, str2))
        return 1;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] >= '0' && str1[i] <= '9') {
            *nb1 *= 10;
            *nb1 += (str1[i] - '0');
        }
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] >= '0' && str2[i] <= '9') {
            *nb2 *= 10;
            *nb2 += (str2[i] - '0');
        }
    if (str1[0] == '-' || str2[0] == '-' ||
        *nb1 <= 1 || *nb1 >= 100 || *nb2 <= 0)
        return 1;
    return 0;
}

int map_maker(int *map, int lim, int pos, int val)
{
    if (lim == 0) {
        map[pos] = (val - 2);
        return 0;
    }
    map[pos] = val;
    map_maker(map, (lim - 1), (pos + 1), (val + 2));
}

int map_displayer(int *map, int lim, int *b_space, int *a_space)
{
    int space = 0;

    for (int i = 0; i < (map[lim] + 2); i++, write(1, "*", 1));
    write(1, "\n", 1);
    for (int i = 0; i < lim; i++) {
        write(1, "*", 1);
        for (int j = 0; j < b_space[i]; j++, write(1, " ", 1));
        for (int j = 0; j < map[i]; j++, write(1, "|", 1));
        for (int j = 0; j < a_space[i]; j++, write(1, " ", 1));
        write(1, "*\n", 2);
    }
    for (int i = 0; i < (map[lim] + 2); i++, write(1, "*", 1));
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int nb_l_max[2] = {[0 ... 1] = 0};
    int *map;
    int *b_space;
    int *a_space;
    int who = 0;

    if (argc != 3 || convert(argv[1], argv[2], &nb_l_max[0], &nb_l_max[1]))
        return 84;
    map = (int *)malloc((nb_l_max[0] + 1) * sizeof(int));
    if (map == NULL || (mallocer(nb_l_max[0], &b_space, &a_space) == 84))
        return 84;
    map_maker(map, nb_l_max[0], 0, 1);
    spacer(map, nb_l_max[0], b_space, a_space);
    map_displayer(map, nb_l_max[0], b_space, a_space);
    who = loop(nb_l_max, map, b_space, a_space);
    if (who == 1)
        my_putstr("I lost... snif... but I'll get you next time!!", 0);
    else if (who == 2)
        my_putstr("You lost, too bad...", 0);
    return who;
}