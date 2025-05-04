/*
** EPITECH PROJECT, 2025
** button_in_game
** File description:
** functions handling the button in game
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

void add_button_info(init_window_t *window)
{
    sfSprite_setTexture(window->btnPlus, window->btnPlusTexture, sfTrue);
    sfSprite_setPosition(window->btnPlus, (sfVector2f){110, 20});
    sfSprite_setScale(window->btnPlus, (sfVector2f){4.5f, 4.5f});
    window->btnLessTexture = sfTexture_createFromFile
    ("./include/src/less_button.png", NULL);
    window->btnLess = sfSprite_create();
    sfSprite_setTexture(window->btnLess, window->btnLessTexture, sfTrue);
    sfSprite_setPosition(window->btnLess, (sfVector2f){30, 20});
    sfSprite_setScale(window->btnLess, (sfVector2f){4.5f, 4.5f});
    window->btnResTexture = sfTexture_createFromFile
    ("./include/src/reset_button.png", NULL);
    window->btnRes = sfSprite_create();
    sfSprite_setTexture(window->btnRes, window->btnResTexture, sfTrue);
    sfSprite_setPosition(window->btnRes, (sfVector2f){20, 1000});
    sfSprite_setScale(window->btnRes, (sfVector2f){4.5f, 4.5f});
}

void add_info_window(init_window_t *window)
{
    window->view_ui = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setFramerateLimit(window->window, 60);
    window->texture =
    sfTexture_createFromFile("./include/src/background.png", NULL);
    window->sprite = sfSprite_create();
    sfSprite_setTexture(window->sprite, window->texture, sfTrue);
    window->back_menu_texture = sfTexture_createFromFile(
    "./include/src/background_menu.jpg", NULL);
    window->back_menu_sprite = sfSprite_create();
    sfSprite_setTexture(window->back_menu_sprite, window->back_menu_texture,
    sfTrue);
    sfSprite_setScale(window->back_menu_sprite, (sfVector2f){0.96f, 0.96f});
    window->btnPlusTexture = sfTexture_createFromFile
    ("./include/src/plus_button.png", NULL);
    window->btnPlus = sfSprite_create();
    add_button_info(window);
    window->zoom = 0;
    window->x = 0;
    window->y = 0;
    window->music = 0;
}

void reset_map(game_t *game)
{
    for (int i = 0; i < game->map->MAX_X; i++) {
        for (int j = 0; j < game->map->MAX_Y; j++)
            game->map->map[i][j] = 0.0;
    }
}

void in_game_button(game_t *game, sfEvent event)
{
    sfVector2f mousePos = sfRenderWindow_mapPixelToCoords(game->window->window,
        sfMouse_getPositionRenderWindow(game->window->window), NULL);
    sfTime time;

    if (game->button->state == 1 && is_mouse_over
        (mousePos, game->window->btnPlus)) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if ((sfTime_asSeconds(time) > 0.4) && game->map->radius < 20) {
            sfClock_restart(game->window->global_clock);
            game->map->radius += 1;
        }
    }
    if (game->button->state == 1 && is_mouse_over
        (mousePos, game->window->btnLess)) {
        time = sfClock_getElapsedTime(game->window->global_clock);
        if ((sfTime_asSeconds(time) > 0.4) && game->map->radius > 1) {
            sfClock_restart(game->window->global_clock);
            game->map->radius -= 1;
        }
    }
}
