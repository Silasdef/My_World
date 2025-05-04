/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap 2 int
*/
#include "my.h"
void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
