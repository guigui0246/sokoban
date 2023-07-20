/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Header for Main programm
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H

int boucle(char **map, int *i);
void help(void);
int test_valid_map(char **map);
int test_valid_map_2(char **map, int i);
void check_lose(int *test, char **map);
void check_win(int *test, char **map, char **true_map, int *i);
void check_move(int *test, char **map, char c, char **map_secret);
int char_test(char c, int test, int *i);
void check(int *test, char **map_display, char **map, int *i);

#endif
