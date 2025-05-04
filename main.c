/*
** EPITECH PROJECT, 2025
** main
** File description:
** my_world
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

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point;
    float angle_x = M_PI / 4;
    float angle_y = M_PI / 5.14;

    point.x = (cos(angle_x) * x - cos(angle_x) * y) * SCALE + 800;
    point.y = (sin(angle_y) * y + sin(angle_y) * x - z) * SCALE + 200;
    point.y = point.y * cos(angle_y) - z * sin(angle_y);
    return point;
}

sfVector2f **create_2d_map(game_t *game)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * game->map->MAX_X);

    for (int i = 0; i < game->map->MAX_X; i++) {
        map_2d[i] = malloc(sizeof(sfVector2f) * game->map->MAX_Y);
        for (int j = 0; j < game->map->MAX_Y; j++)
            map_2d[i][j] = project_iso_point(i, j, game->map->map[i][j]);
    }
    return map_2d;
}

void handle_event(game_t *game)
{
    sfEvent event;
    sfVector2f mousePos = sfRenderWindow_mapPixelToCoords(game->window->window,
    sfMouse_getPositionRenderWindow(game->window->window), NULL);

    while (sfRenderWindow_pollEvent(game->window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            sfRenderWindow_close(game->window->window);
        if (event.type == sfEvtMouseButtonPressed) {
            clic_menu(game->window->window, game, event, mousePos);
        }
        clic_event(game->window->window, game, event);
    }
}

static void displaying(game_t *game)
{
    sfVector2f **map_2d;

    handle_event(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_setView(game->window->window, game->window->view_ui);
    sfRenderWindow_drawSprite(game->window->window,
        game->window->sprite, NULL);
    sfRenderWindow_setView(game->window->window, game->window->view_map);
    map_2d = create_2d_map(game);
    draw_2d_map(game, map_2d);
    sfRenderWindow_setView(game->window->window, game->window->view_ui);
    sfRenderWindow_drawSprite(game->window->window,
    game->button->btnExit, NULL);
    sfRenderWindow_drawSprite(game->window->window,
    game->window->btnPlus, NULL);
    sfRenderWindow_drawSprite(game->window->window,
    game->window->btnLess, NULL);
    sfRenderWindow_drawSprite(game->window->window,
    game->window->btnRes, NULL);
    sfRenderWindow_display(game->window->window);
}

static void add_info_map(init_map_t *map)
{
    map->MAX_X = 100;
    map->MAX_Y = 100;
    map->radius = 5;
    map->texture_stone =
    sfTexture_createFromFile("./include/src/stone.png", NULL);
    map->ground_texture =
    sfTexture_createFromFile("./include/src/grass.png", NULL);
    map->texture_water =
    sfTexture_createFromFile("./include/src/water.jpg", NULL);
    map->texture_snow =
    sfTexture_createFromFile("./include/src/snow.png", NULL);
    map->easter_egg =
    sfTexture_createFromFile("./include/src/easter_egg.png", NULL);
    map->texture_dirt =
    sfTexture_createFromFile("./include/src/dirt.png", NULL);
    map->global_clock = sfClock_create();
    map->map = malloc(sizeof(double *) * map->MAX_X);
}

static init_map_t *init_map(void)
{
    init_map_t *map = malloc(sizeof(init_map_t));

    if (map == NULL)
        return NULL;
    add_info_map(map);
    if (!map->map) {
        free(map);
        return NULL;
    }
    for (int i = 0; i < map->MAX_X; i++) {
        map->map[i] = malloc(sizeof(double) * map->MAX_Y);
        if (!map->map[i]) {
            free_map(map);
            return NULL;
        }
        for (int j = 0; j < map->MAX_Y; j++)
            map->map[i][j] = 0.0;
    }
    return map;
}

static init_window_t *init_window(void)
{
    init_window_t *window = malloc(sizeof(init_window_t));

    if (!window)
        return NULL;
    window->global_clock = sfClock_create();
    window->video_mode = (sfVideoMode){1920, 1080, 32};
    window->window = sfRenderWindow_create(window->video_mode,
        "My world", sfResize | sfClose, NULL);
    add_info_window(window);
    window->view_map = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (!window->window || !window->view_map || !window->global_clock) {
        sfClock_destroy(window->global_clock);
        sfView_destroy(window->view_map);
        sfRenderWindow_destroy(window->window);
        free(window);
        return NULL;
    }
    return window;
}

static game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->window = init_window();
    game->map = init_map();
    game->button = init_button();
    if (!game->window || !game->map) {
        free(game->window);
        free_map(game->map);
        free(game);
        return NULL;
    }
    return game;
}

static void launch_game(game_t *game, sfMusic *music)
{
    while (sfRenderWindow_isOpen(game->window->window)) {
        if (game->button->state == 0)
            displaying_menu(game);
        if (game->button->state == 1)
            displaying(game);
        if (game->window->music == 1) {
            play_music(&music, "./include/src/easter_egg.ogg");
            game->window->music = 0;
        }
    }
}

int main(int argc, char **argv, char **env)
{
    game_t *game = NULL;
    sfMusic *music = NULL;
    int max_map_size = 0;

    if (argc == 2 && message(argv[1]) == 0)
        return 0;
    if (is_tty(env) == 84 || is_launchable(argc, argv, env) == 84)
        return 84;
    game = init_game();
    max_map_size = prompt_for_map_size(game->window->window);
    game->map->MAX_X = max_map_size;
    game->map->MAX_Y = max_map_size;
    play_music(&music, "./include/src/silas_laume.ogg");
    launch_game(game, music);
    destroy_game(game);
    return 0;
}
