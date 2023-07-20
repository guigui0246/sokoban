/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** print string until '\0' starting at *str
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    };
    return (0);
}
