/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Find char in char**
*/

#include "move.h"
#include "my.h"

int *find_char_in_arr(char **arr, char c, int *test)
{
    int row = my_array_len(arr);

    for (int i = 0; i < row; i++) {
        test[0] = i;
        test[1] = find_char_in_arr_part2(arr, c, test);
        if (test[1] >= 0)
            return test;
    }
    test[0] = -1;
    return test;
}

int find_char_in_arr_part2(char **arr, char c, int *test)
{
    int col = my_strlen(arr[test[0]]);

    for (test[1] = 0; test[1] < col; test[1]++) {
        if (arr[test[0]][test[1]] == c)
            return test[1];
    }
    return -1;
}
