/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** my_getnbr
*/
#include "my.h"

static int suite2(long reponse, int nega)
{
    if (nega % 2 != 0) {
        return (int)(- reponse);
    } else {
        return (int)(reponse);
    }
}

static int suite1(int index, int nega, char const *str)
{
    long reponse = 0;
    int has_number = 0;

    while (str[index] >= '0' && str[index] <= '9') {
        reponse = reponse * 10 + (str[index] - '0');
        has_number = 1;
        index++;
        if (reponse > 2147483647 && !(reponse == 2147483648 && nega % 2 != 0))
            return 0;
    }
    if (has_number == 0)
        return -1;
    return suite2(reponse, nega);
}

int my_getnbr(char const *str)
{
    int index = 0;
    int nega = 0;

    while (str[index] && (str[index] < '0' || str[index] > '9')) {
        if (str[index] != '-' && str[index] != '+') {
            return 0;
        }
        if (str[index] == '-') {
            nega++;
        }
        index++;
    }
    return suite1(index, nega, str);
}
