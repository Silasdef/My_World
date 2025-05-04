/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** concat params
*/

#include "my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    char *str;
    int len = argc;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]);
    str = malloc(len);
    for (int a = 0; a < argc - 1; a++) {
        my_strcat(str, argv[a]);
        my_strcat(str, "\n");
    }
    my_strcat(str, argv[argc - 1]);
    my_strcat(str, "\0");
    return str;
}
