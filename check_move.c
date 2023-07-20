/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Check move condition
*/

#include "move.h"

void check_move(int *test, char **map, char c, char **map_secret)
{
    if (c < 65 || c > 68) {
        return;
    }
    if (c == 65)
        move_up(test, map, map_secret);
    if (c == 66)
        down(test, map, map_secret);
    if (c == 67)
        right(test, map, map_secret);
    if (c == 68)
        left(test, map, map_secret);
}
