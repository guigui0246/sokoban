/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Header for map
*/

#ifndef MAP_H
    #define MAP_H

char **load_2d_arr_from_file(int fd, int nb_rows, int nb_cols);
void setup_buf(char **buf, int nb_rows, int nb_cols);
int get_nb_line(const char *filepath);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void display_map(char **map);
char **get_from_file(int fd, const char *filepath);
int length_1st_line(const char *filepath);
void add_l(int *l, char *B, char **map);
void rm_map(char **map);
int main2(int *test, int *i);
void apply_test_effect(int *test, int *i);

#endif
