/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** met en majuscule str
*/
#include "my.h"

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++){
        if ((str[i] >= 'a') && (str[i] <= 'z'))
            str[i] = (str[i] - 32);
        else
            str[i] = str[i];
    }
    return str;
}
