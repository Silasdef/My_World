/*
** EPITECH PROJECT, 2025
** make sound
** File description:
** sounds functions
*/

#include <SFML/System.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "functions_world.h"
#include "struct_my_world.h"

void play_music(sfMusic **music, char *path)
{
    if (*music != NULL) {
        sfMusic_stop(*music);
        sfMusic_destroy(*music);
    }
    *music = sfMusic_createFromFile(path);
    sfMusic_setLoop(*music, sfTrue);
    sfMusic_play(*music);
}
