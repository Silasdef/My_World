/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** renvoie le nb donne
*/
#include "my.h"

int my_put_nbr(int n)
{
    if (n == -2147483648){
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
    }
    if (n != -2147483648){
        if (n <= -1){
            n = n * -1;
            my_putchar('-');
        }
        if (n > 9)
            my_put_nbr(n / 10);
        my_putchar((n % 10) + 48);
    }
}
