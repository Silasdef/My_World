/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** my_is_prime.c
*/
#include "my.h"
int my_is_prime(int nb)
{
    int i = 2;

    if (nb > 2147483647)
        return 0;
    if (nb <= 1)
        return 0;
    while (nb > i){
        if ((nb % i) == 0)
            return 0;
        i++;
    }
    return 1;
}
