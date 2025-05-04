/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** oe
*/
#include "my.h"

static int strlen5(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    my_strlowcase(str);
    if (str[0] <= 'z' && str[0] >= 'a')
        str[0] = str[0] - 32;
    for (int i = 0; i < len; i++)
        if ((str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') &&
            (str[i] < 'A' || str[i] > 'Z')
            && (str[i + 1] <= 'z' && str[i + 1] >= 'a'))
            str[i + 1] = str[i + 1] - 32;
    return str;
}
