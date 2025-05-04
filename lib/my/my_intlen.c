/*
** EPITECH PROJECT, 2025
** my_intlen
** File description:
** calculate len of an int
*/

#include "my.h"

int my_intlen(int num)
{
    int len = 0;

    if (num < 0)
        num *= -1;
    for (; num > 0; len++) {
        num /= 10;
    }
    if (len == 0)
        return 1;
    return len;
}
