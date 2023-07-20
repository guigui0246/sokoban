/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** split str in array of word
*/

#include <stdlib.h>
int my_strlen(char const *str);
int my_array_len(char const **str);
int my_str_isnum(char const *str);
int my_str_isalpha(char const *str);
char *my_strdup(char const *str);

char **loop_str_to_word(int size, char **dup, char const *str)
{
    int i;
    int len = 1;
    char **ret = malloc(sizeof(char *) * (size + 1));

    ret[0] = dup[0];
    for (i = 0; i < my_strlen(str); i++) {
        if (dup[0][i] == '\0') {
            ret[len] = &dup[0][i + 1];
            len++;
        };
    };
    return ret;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    char *dup = my_strdup(str);
    char test[] = "\0\0";
    int len = 0;
    char **ret = {0};

    if (my_strlen(str) == 0)
        return ret;
    for (i = 0; i < my_strlen(str); i++) {
        test[0] = dup[i];
        if (!(my_str_isnum(test) || my_str_isalpha(test))) {
            dup[i] = '\0';
            len++;
        };
    };
    return loop_str_to_word(len, &dup, str);
}
