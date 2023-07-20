/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Move up
*/

#include "move.h"

void left(int *test, char **map, char **map_secret)
{
    int placement_of_player[2];
    char c;

    find_char_in_arr(map, 'P', placement_of_player);
    if (placement_of_player[1] == 0)
        return;
    c = map[placement_of_player[0]][placement_of_player[1] - 1];
    if (c == ' ' || c == 'O') {
        map[placement_of_player[0]][placement_of_player[1] - 1] = 'P';
        put_back(map, placement_of_player, map_secret);
    }
    if (c == 'X' && (placement_of_player[1] > 1)
        && (map[placement_of_player[0]][placement_of_player[1] - 2] == ' '
        || map[placement_of_player[0]][placement_of_player[1] - 2] == 'O')) {
        map[placement_of_player[0]][placement_of_player[1] - 2] = 'X';
        map[placement_of_player[0]][placement_of_player[1] - 1] = 'P';
        put_back(map, placement_of_player, map_secret);
    }
}
