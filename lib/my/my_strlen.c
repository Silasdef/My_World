/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** silas le goat
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return i;
}
