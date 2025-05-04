/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** met des minuscules
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] = (str[i] + 32);
        else
            str[i] = str[i];
    }
    return str;
}
