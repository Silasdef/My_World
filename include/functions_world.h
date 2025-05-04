/*
** EPITECH PROJECT, 2024
** functions_world
** File description:
** H files for functions of my_world
*/

#ifndef FUNCTIONS_WORLD_H_
    #define FUNCTIONS_WORLD_H_

    #define SCALE 50

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include "struct_my_world.h"

void free_word_array(char **array);
void clic_event(sfRenderWindow *window,
    game_t *game, sfEvent event);
void draw_2d_map(game_t *game, sfVector2f **map);
void destroy_game(game_t *game);
void free_map(init_map_t *map);
init_button_t *init_button(void);
void displaying_menu(game_t *game);
void clic_menu(sfRenderWindow *window, game_t *game, sfEvent event,
    sfVector2f mousePos);
void handle_event(game_t *game);
void play_music(sfMusic **music, char *path);
void add_button_info(init_window_t *window);
void in_game_button(game_t *game, sfEvent event);
int is_mouse_over(sfVector2f mousePos, sfSprite *sprite);
void reset_map(game_t *game);
int prompt_for_map_size(sfRenderWindow *window);
void add_info_window(init_window_t *window);
int is_tty(char **env);
int is_launchable(int argc, char **argv, char **env);
int message(char *c);

#endif
