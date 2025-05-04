/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** lower str
*/
#include "my.h"

int my_str_islower(char const *str)
{
    int len = my_strlen(str);

    if (str[0] == '\0')
        return 1;
    for (int i = 0; i < len; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    return 1;
}
