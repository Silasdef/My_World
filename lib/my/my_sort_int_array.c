/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** my_sort_int_array.c
*/
#include "my.h"

static int minim(int *array, int size, int *ptr, int index)
{
    int min = array[index];

    *ptr = index;
    for (index; index <= size - 1; index++){
        if (array[index] < min){
            min = array[index];
            *ptr = index;
        }
    }
    return min;
}

void my_sort_int_array(int *array, int size)
{
    int indexmini = 0;
    int *ptr = &indexmini;
    int temp;
    int mini;

    for (int index = 0; index <= size - 1; index++){
        mini = minim(array, size, &indexmini, index);
        my_swap(&array[index], &array[indexmini]);
    }
}
