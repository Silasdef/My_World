/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** insprintable str
*/
#include "my.h"

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);

    if (str[0] == '\0')
        return 1;
    for (int i = 0; i < len; i++)
        if (str[i] < 32 || str[i] > 127)
            return 0;
    return 1;
}
