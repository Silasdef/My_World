/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** oizhvoihz
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[my_strlen(src) + 1] = '\0';
    return dest;
}
