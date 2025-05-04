/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** strstr
*/
#include "my.h"
#include <stddef.h>

static int checkpatern(int index, char *str, char const *to_find, int lenfind)
{
    for (int i = 0; i < lenfind; i++) {
        if (str[i + index] != to_find[i])
            return 0;
    }
    return 1;
}

static int pre_test(char *str, char const *to_find, int lenfind, int *ip)
{
    int lenstr = 0;

    while (str[lenstr] != '\0')
        lenstr++;
    for (int i = 0; i <= (lenstr - lenfind); i++)
        if (checkpatern(i, str, to_find, lenfind) == 1){
            *ip = i;
            return 1;
        }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int len = 0;
    int indexdupatern = 0;

    while (to_find[len] != '\0')
        len++;
    if (pre_test(str, to_find, len, &indexdupatern) == 1)
        return str + indexdupatern;
    else
        return NULL;
}
