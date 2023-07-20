/*
** EPITECH PROJECT, 2022
** My_sokoban
** File description:
** get rectangle
*/

#include "map.h"
#include <stdlib.h>
#include "my.h"
#include <fcntl.h>
#include <unistd.h>

char **load_2d_arr_from_file(int fd, int nb_rows, int nb_cols)
{
    char **buf = mem_alloc_2d_array(nb_rows, nb_cols);
    char tmp[1] = "\n";
    int y = 0;

    if (fd == -1)
        return buf;
    for (int i = 0; i < nb_rows; i++) {
        y = read(fd, buf[i], nb_cols);
        read(fd, tmp, 1);
        if (y != nb_cols || tmp[0] != '\n') {
            close(fd);
            free(buf);
            return NULL;
        }
    }
    close(fd);
    return buf;
}
