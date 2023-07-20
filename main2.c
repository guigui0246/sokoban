/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-guillaume.deplaine
** File description:
** main2
*/

#include <stddef.h>
#include <fcntl.h>
#include "level.h"
#include "sokoban.h"
#include "map.h"

int main2(int *test, int *i)
{
    char **map;

    map = get_from_file(open(LEVEL[*i], O_RDONLY), LEVEL[*i]);
    if (map == NULL || test_valid_map(map) == 84)
        return 84;
    *test = boucle(map, i);
    if (*test != 2) {
        apply_test_effect(test, i);
    }
    rm_map(map);
    return 0;
}

void apply_test_effect(int *test, int *i)
{
    if (*test == 1)
        *test = 2;
    if (*test == 0)
        if (LEVEL[*i] != NULL)
            *test = 2;
}

void check(int *test, char **map_display, char **map, int *i)
{
    check_lose(test, map_display);
    check_win(test, map_display, map, i);
}

int char_test(char c, int test, int *i)
{
    if (c == ' ')
        return 2;
    if (c == 'l') {
        *i = *i + 1;
        return 0;
    }
    if (c == 'q')
        return 136;
    return test;
}
