/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Move up
*/

#include "move.h"

void move_up(int *test, char **map, char **map_secret)
{
    int placement_of_player[2];
    char c;

    find_char_in_arr(map, 'P', placement_of_player);
    if (placement_of_player[0] == 0)
        return;
    c = map[placement_of_player[0] - 1][placement_of_player[1]];
    if (c == ' ' || c == 'O') {
        map[placement_of_player[0] - 1][placement_of_player[1]] = 'P';
        put_back(map, placement_of_player, map_secret);
    }
    if (c == 'X' && (placement_of_player[0] > 1)
        && (map[placement_of_player[0] - 2][placement_of_player[1]] == ' '
        || map[placement_of_player[0] - 2][placement_of_player[1]] == 'O')) {
        map[placement_of_player[0] - 2][placement_of_player[1]] = 'X';
        map[placement_of_player[0] - 1][placement_of_player[1]] = 'P';
        put_back(map, placement_of_player, map_secret);
    }
}
