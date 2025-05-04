/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** strs biduke
*/
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int my_str_isalphanum(char str)
{
    return ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z') ||
        (str >= '0' && str <= '9'));
}

static int nbr_mots(char *str2)
{
    int i = 0;
    int nbmots = 0;

    while (str2[i] != '\0') {
        if (my_str_isalphanum(str2[i]) &&
            (i == 0 || !my_str_isalphanum(str2[i - 1]))) {
            nbmots++;
        }
        i++;
    }
    return nbmots;
}

static void free_tab(char **tab, int count)
{
    for (int i = 0; i < count; i++) {
        if (tab[i]) {
            free(tab[i]);
        }
    }
    free(tab);
}

static int str_to_word_part3(int i, int **params, char **tab, char *str2)
{
    int *data = *params;

    if (my_str_isalphanum(str2[i])) {
        if (i == 0 || !my_str_isalphanum(str2[i - 1]))
            data[0] = i;
        data[1]++;
    }
    if ((!my_str_isalphanum(str2[i]) && data[1] > 0) ||
        (str2[i + 1] == '\0' && data[1] > 0)) {
        tab[data[2]] = malloc((data[1] + 1) * sizeof(char));
        if (!tab[data[2]])
            return -1;
        my_strncpy(tab[data[2]], str2 + data[0], data[1]);
        tab[data[2]][data[1]] = '\0';
        data[2]++;
        data[1] = 0;
    }
    return 0;
}

static char **str_to_word_part2(char *str2, char **tab)
{
    int i = 0;
    int *params = malloc(3 * sizeof(int));

    if (!params)
        return NULL;
    params[0] = 0;
    params[1] = 0;
    params[2] = 0;
    while (str2[i] != '\0') {
        if (str_to_word_part3(i, &params, tab, str2) < 0) {
            free_tab(tab, params[2]);
            free(params);
            return NULL;
        }
        i++;
    }
    tab[params[2]] = NULL;
    free(params);
    return tab;
}

char **my_str_to_word_array(char *str)
{
    int len = my_strlen(str);
    char **tab = NULL;
    char *str2 = malloc((len + 2) * sizeof(char));
    int word_count;

    if (!str2)
        return NULL;
    my_strcpy(str2, str);
    my_strcat(str2, " ");
    word_count = nbr_mots(str2);
    tab = malloc((word_count + 1) * sizeof(char *));
    if (!tab) {
        free(str2);
        return NULL;
    }
    tab = str_to_word_part2(str2, tab);
    free(str2);
    return tab;
}
