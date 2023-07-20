/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Check Win condition
*/

#include "move.h"

void check_win(int *test, char **map, char **true_map, int *i)
{
    int place_of_first_button[2];
    int place_of_player[2];

    find_char_in_arr(map, 'P', place_of_player);
    find_char_in_arr(map, 'O', place_of_first_button);
    if (place_of_first_button[0] == -1 && place_of_first_button[1] == -1
        && true_map[place_of_player[0]][place_of_player[1]] != 'O') {
        *test = 0;
        *i = *i + 1;
    }
}
