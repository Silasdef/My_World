/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** cat str
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int lendest = my_strlen(dest);
    int lensrc = my_strlen(src);

    for (int i = 0; i < lensrc; i++)
        dest[i + lendest] = src[i];
    return dest;
}
