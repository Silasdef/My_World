/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** my_str_isalpha
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);

    if (str[0] == '\0')
        return 1;
    for (int i = 0; i < len; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A'
            || str[i] > 'Z'))
            return 0;
    return 1;
}
