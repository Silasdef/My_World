/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** diplay one b one char of str
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
