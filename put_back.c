/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Put the thing back in place
*/

#include "move.h"

void put_back(char **map, int *place, char **map_secret)
{
    if (map_secret[place[0]][place[1]] == 'O')
        map[place[0]][place[1]] = 'O';
    else
        map[place[0]][place[1]] = ' ';
}
