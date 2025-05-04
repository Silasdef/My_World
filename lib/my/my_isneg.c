/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** posi o negative ?
*/
#include "my.h"

int my_isneg(int i)
{
    if (i < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
