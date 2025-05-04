/*
** EPITECH PROJECT, 2025
** destroy
** File description:
** functions free and destroyyyyyyyyyy
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
#include "assets.h"

int message(char *c)
{
    if (strcmp(c, "-h") == 0) {
        write(1, "My World\n", 10);
        write(1, "USAGE\n", 6);
        write(1, "  ./My_world\n", 14);
        write(1, "Interactive 3D terrain editor in CSFML\n", 40);
        write(1, "OPTIONS\n", 8);
        write(1, " -h                 print the usage and quit.\n", 47);
        return 0;
    }
    return 84;
}

int is_tty(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strcmp(env[i], "DISPLAY=:0") == 0)
            return 0;
        if (strcmp(env[i], "DISPLAY=:1") == 0)
            return 0;
    }
    return 84;
}

int is_launchable(int argc, char **argv, char **env)
{
    for (int i = 0; pathfile[i] != NULL; i++) {
        if (access(pathfile[i], F_OK) == -1) {
            return 84;
        }
    }
    return 0;
}

void free_map(init_map_t *map)
{
    for (int i = 0; i < map->MAX_X; i++)
        free(map->map[i]);
    free(map->map);
}

void destroy_game(game_t *game)
{
    sfClock_destroy(game->window->global_clock);
    sfRenderWindow_destroy(game->window->window);
    sfView_destroy(game->window->view_ui);
    sfView_destroy(game->window->view_map);
    sfTexture_destroy(game->window->texture);
    sfTexture_destroy(game->window->back_menu_texture);
    sfSprite_destroy(game->window->sprite);
    sfSprite_destroy(game->window->back_menu_sprite);
    sfTexture_destroy(game->map->ground_texture);
    sfTexture_destroy(game->map->texture_stone);
    sfTexture_destroy(game->map->texture_water);
    sfTexture_destroy(game->map->texture_snow);
    sfTexture_destroy(game->map->texture_dirt);
    sfTexture_destroy(game->map->easter_egg);
    sfClock_destroy(game->map->global_clock);
    free(game->button);
    free(game->window);
    free_map(game->map);
    free(game);
}
