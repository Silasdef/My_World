/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** rev
*/
#include "my.h"

char *my_revstr(char *str)
{
    int indexnew = 0;
    int len = my_strlen(str);
    char rep[len];

    for (int i = (len - 1); i >= 0; i--){
        rep[indexnew] = str[i];
        indexnew++;
    }
    for (int a = 0; a != (len); a++){
        str[a] = rep[a];
    }
    return str;
}
