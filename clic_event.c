/*
** EPITECH PROJECT, 2025
** clic event
** File description:
** event clics
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
#include "struct_my_world.h"
#include "functions_world.h"

static void up_and_down(sfRenderWindow *window,
    game_t *game, sfEvent event)
{
    sfTime time;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_zoom(game->window->view_map, 0.9);
            sfClock_restart(game->window->global_clock);
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_zoom(game->window->view_map, 1.1);
            sfClock_restart(game->window->global_clock);
        }
    }
}

static void s_clic_and_z_clic(sfRenderWindow *window,
    game_t *game, sfEvent event)
{
    sfTime time;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_move(game->window->view_map, (sfVector2f){0, 30});
            sfClock_restart(game->window->global_clock);
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_move(game->window->view_map, (sfVector2f){0, -30});
            sfClock_restart(game->window->global_clock);
        }
    }
}

static void d_clic_and_q_clic(sfRenderWindow *window,
    game_t *game, sfEvent event)
{
    sfTime time;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_move(game->window->view_map, (sfVector2f){30, 0});
            sfClock_restart(game->window->global_clock);
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if (sfTime_asSeconds(time) > 0.01) {
            sfView_move(game->window->view_map, (sfVector2f){-30, 0});
            sfClock_restart(game->window->global_clock);
        }
    }
}

void screen_to_iso(sfVector2f world_pos, int *x, int *y)
{
    float angle_x = M_PI / 4;
    float angle_y = M_PI / 5.14;
    float iso_x = (world_pos.x - 800) / SCALE;
    float iso_y = (world_pos.y - 200) / SCALE;

    *x = (iso_x / cos(angle_x) + iso_y / sin(angle_y)) / 2;
    *y = (iso_y / sin(angle_y) - iso_x / cos(angle_x)) / 2;
}

static void check_add_map(int dx, int dy, game_t *game, int cond)
{
    int new_x = 0;
    int new_y = 0;
    float distance = 0;
    float height_increase = 0;

    new_x = game->window->x + dx;
    new_y = game->window->y + dy;
    if (new_x >= 0 && new_x < game->map->MAX_X && new_y >= 0
        && new_y < game->map->MAX_Y) {
        distance = sqrt(dx * dx + dy * dy);
        if (distance <= game->map->radius) {
            height_increase = (game->map->radius - distance)
            / game->map->radius;
            game->map->map[new_x][new_y] += height_increase * cond;
        }
    }
}

static void add_map_height(game_t *game, int cond)
{
    int new_x = 0;
    int new_y = 0;

    for (int dx = - game->map->radius; dx <= game->map->radius; dx++) {
        for (int dy = - game->map->radius; dy <= game->map->radius; dy++)
            check_add_map(dx, dy, game, cond);
    }
}

void handle_mouse_click(sfRenderWindow *window,
    game_t *game, sfEvent event)
{
    sfVector2i pixel_pos = {event.mouseButton.x, event.mouseButton.y};
    sfVector2f world_pos;

    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseRight) {
        world_pos = sfRenderWindow_mapPixelToCoords(window,
            pixel_pos, game->window->view_map);
        screen_to_iso(world_pos, &game->window->x, &game->window->y);
        add_map_height(game, -1);
    }
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
        world_pos = sfRenderWindow_mapPixelToCoords(window,
            pixel_pos, game->window->view_map);
        screen_to_iso(world_pos, &game->window->x, &game->window->y);
        add_map_height(game, 1);
    }
}

void clic_event(sfRenderWindow *window,
    game_t *game, sfEvent event)
{
    up_and_down(window, game, event);
    s_clic_and_z_clic(window, game, event);
    d_clic_and_q_clic(window, game, event);
    handle_mouse_click(window, game, event);
    in_game_button(game, event);
}
