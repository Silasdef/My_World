/*
** EPITECH PROJECT, 2023
** B-CPE-110 : organized
** File description:
** bootstrap.h
*/

#ifndef RADAR_H
    #define RADAR_H
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef struct init_window_s {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture* background_texture;
    sfClock *global_clock;
    sfSprite *background_sprite;
    sfView *view_map;
    sfView *view_ui;
    sfTexture* back_menu_texture;
    sfSprite *back_menu_sprite;
    sfTexture *btnPlusTexture;
    sfSprite *btnPlus;
    sfTexture *btnLessTexture;
    sfSprite *btnLess;
    sfTexture *btnResTexture;
    sfSprite *btnRes;
    int zoom;
    int x;
    int y;
    int loop_music;
    int music;
} init_window_t;

typedef struct init_map_s {
    int MAX_X;
    int MAX_Y;
    int radius;
    sfClock *global_clock;
    sfTexture *ground_texture;
    sfTexture *texture_stone;
    sfTexture *texture_water;
    sfTexture *texture_snow;
    sfTexture *texture_dirt;
    sfTexture *easter_egg;
    double **map;
} init_map_t;

typedef struct init_button_s {
    int state;
    int show_credits;
    sfTexture *btnTexture;
    sfSprite *btnStart;
    sfTexture *btnExitTexture;
    sfSprite *btnExit;
    sfTexture *btnCredTexture;
    sfSprite *btnCred;
    sfTexture *btnLeaveTexture;
    sfSprite *btnLeave;
} init_button_t;

typedef struct games_s {
    init_window_t *window;
    init_map_t *map;
    init_button_t *button;
} game_t;


#endif
