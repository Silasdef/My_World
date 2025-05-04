/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** strncat sah
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int lendest = my_strlen(dest);
    int lensrc = my_strlen(src);

    for (int i = 0; i < nb; i++)
        dest[i + lendest] = src[i];
    return dest;
}
