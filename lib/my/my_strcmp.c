/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare str
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int lens2 = my_strlen(s2);
    int lens1 = my_strlen(s1);
    int variable = lens1;
    int reponse;

    if (lens2 > lens1)
        variable = lens2;
    if (lens1 > lens2)
        variable = lens1;
    for (int i = 0; i < variable; i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
