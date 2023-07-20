/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Check lose condition
*/

#include "fail.h"
#include "my.h"

bool_t blocked(char **map, int i, int j)
{
    return ((i < 1 || i == my_array_len(map) - 1
        || (map[i - 1][j] != ' ' && map[i - 1][j] != 'O'
        && map[i - 1][j] != 'P')
        || (map[i + 1][j] != ' ' && map[i + 1][j] != 'O'
        && map[i + 1][j] != 'P'))
        && ((j < 1 || j == my_strlen(map[0]) - 1)
        || (map[i][j - 1] != ' ' && map[i][j - 1] != 'O'
        && map[i][j - 1] != 'P')
        || (map[i][j + 1] != ' ' && map[i][j + 1] != 'O'
        && map[i][j + 1] != 'P')));
}

void check_lose(int *test, char **map)
{
    int int_etoile[2];

    if (find_all_boxes(map, int_etoile))
        *test = 1;
}

bool_t find_all_boxes(char **arr, int *test)
{
    int row = my_array_len(arr);

    for (int i = 0; i < row; i++) {
        test[0] = i;
        test[1] = find_all_boxes_part2(arr, test);
        if (test[1] == 0)
            return 0;
    }
    return 1;
}

bool_t find_all_boxes_part2(char **arr, int *test)
{
    int col = my_strlen(arr[test[0]]);

    for (test[1] = 0; test[1] < col; test[1]++) {
        if (arr[test[0]][test[1]] == 'X' && !blocked(arr, test[0], test[1]))
            return 0;
    }
    return 1;
}
