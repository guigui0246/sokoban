/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Header for Moving
*/

#ifndef MOVE_H
    #define MOVE_H

void move_up(int *test, char **map, char **map_secret);
void down(int *test, char **map, char **map_secret);
void left(int *test, char **map, char **map_secret);
void right(int *test, char **map, char **map_secret);
int *find_char_in_arr(char **arr, char c, int *test);
int find_char_in_arr_part2(char **arr, char c, int *test);
void put_back(char **map, int *place, char **map_secret);

#endif
