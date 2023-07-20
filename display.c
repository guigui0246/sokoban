/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** Display map
*/

#include "my.h"
#include <ncurses.h>

void display_map(char **map)
{
    int x = 0;
    int row = (LINES - my_array_len(map)) / 2;

    if (COLS < my_strlen(map[0]) || LINES < my_array_len(map)) {
        move((LINES - my_nbline_col("Please enlarge terminal to play !", COLS))
            / 2, ((COLS - 33) / 2));
        printw("Please enlarge terminal to play !");
        move((LINES - my_nbline_col("Please enlarge terminal to play !",
            COLS)) / 2 + 1, ((COLS - 34) / 2));
        printw("Enless you want to do it blindly !");
        return;
    }
    while (x < my_array_len(map)) {
        move(row + x, ((COLS - my_strlen(map[x])) / 2));
        printw(map[x]);
        x++;
    }
    move(LINES - 1, COLS - 1);
}
