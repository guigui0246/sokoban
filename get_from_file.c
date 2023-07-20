/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** retrieve the map from the file
*/

#include "map.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char **get_from_file(int fd, const char *filepath)
{
    char **map;
    int x;
    int y;

    if (fd == -1)
        return NULL;
    x = get_nb_line(filepath);
    y = length_1st_line(filepath);
    if (x <= 0 || y <= 0) {
        return NULL;
    }
    map = load_2d_arr_from_file(fd, x, y);
    close(fd);
    return map;
}

int length_1st_line(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char tmp[1];
    int test = read(fd, tmp, 1);
    int i = 0;

    if (fd == -1) {
        return -1;
    }
    while (test && tmp[0] != '\n') {
        test = read(fd, tmp, 1);
        i++;
    }
    close(fd);
    return i;
}

int get_nb_line(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int test = 1;
    int test2 = 0;
    char tmp[1];
    int i = 0;

    if (fd == -1) {
        return -1;
    }
    while (test) {
        test = read(fd, tmp, 1);
        if (tmp[0] == '\n') {
            i++;
            test2 = 1;
        } else
            test2 = 0;
    }
    close(fd);
    return i + 1 - 2 * test2;
}
