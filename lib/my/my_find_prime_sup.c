/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** my_find_prime_sup.c
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    long i = nb;
    int rep = 0;

    if (nb < 0)
        return 2;
    while (my_is_prime(i) == 0) {
        if (i > 2147483647)
            return 0;
        i++;
    }
    rep = i;
    return rep;
}
