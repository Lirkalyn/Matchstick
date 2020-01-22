/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char c);
int my_putstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int ask_line(int *p_line, int *map, int *lim);
int ask_line2(int *p_line, int *map, int *lim);
int ask_matches(int *p_line, int *p_matches, int *map, int *lim);
int convert(char *str1, char *str2, int *nb1, int *nb2);
int act(int *p_line, int *p_matches, int *map, int *a_space);
int mallocer(int lim, int **b_space, int **a_space);
int spacer(int *map, int lim, int *b_space, int *a_space);
int loop(int *nb_l_max, int *map, int *b_space, int *a_space);
int map_displayer(int *map, int lim, int *b_space, int *a_space);
int message(int p_line, int p_matches);
int ai(int *map, int *nb_l_max, int *p_line, int *p_matches);
int ai_message(int p_line, int p_matches);
int ai_act(int *p_line, int *p_matches, int *map, int *a_space);

#endif
