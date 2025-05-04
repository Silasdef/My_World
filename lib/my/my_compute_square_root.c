/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** racine carre de nb
*/
#include "my.h"
int my_compute_square_root(int nb)
{
    int i = 0;

    while (nb > (i * i)){
        i++;
    }
    if ((i * i) == nb)
        return i;
    return 0;
}
