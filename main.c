/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** main file
*/

#include <ncurses.h>
#include "my.h"
#include "map.h"
#include <fcntl.h>
#include "sokoban.h"
#include <unistd.h>
#include "level.h"

int main(int argc, char **argv)
{
    int test = 2;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }
    if (argc != 1)
        return 84;
    initscr();
    for (int i = 0; test == 2 && LEVEL[i] != NULL;) {
        if (main2(&test, &i) == 84) {
            i++;
        }
    }
    endwin();
    return test;
}

void help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "    ./my_sokoban\n", 17);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    will play the files called 'level #' in the folder 'dat", 59);
    write(1, "a' where # is the\n    position in the order of the level r", 59);
    write(1, "epresenting a map, containing '#' for\n    walls, 'P' for t", 59);
    write(1, "he player, 'X' for boxes and 'O' for storage locations.\n", 57);
}

int test_valid_map(char **map)
{
    int row = my_array_len(map);

    for (int i = 0; i < row; i++) {
        if (test_valid_map_2(map, i) == 84)
            return 84;
    }
    return 0;
}

int test_valid_map_2(char **map, int i)
{
    int col = my_strlen(map[i]);

    for (int j = 0; j < col; j++) {
        if (map[i][j] != '#' && map[i][j] != ' ' && map[i][j] != 'P'
            && map[i][j] != 'O' && map[i][j] != 'X') {
            rm_map(map);
            return 84;
        }
    }
    return 0;
}

int boucle(char **map, int *i)
{
    char c = 0;
    int test = 17;
    char **map_display = mem_dup_2d_array(map, my_array_len(map),
        my_strlen(map[0]));

    while (test != 1 && test != 0 && test != 84 && test != 2 && test != 136) {
        display_map(map_display);
        refresh();
        c = getch();
        clear();
        check_move(&test, map_display, c, map);
        check(&test, map_display, map, i);
        test = char_test(c, test, i);
    }
    rm_map(map_display);
    return test;
}
