/*
** EPITECH PROJECT, 2025
** get_size
** File description:
** function to get the size opf the map
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

static void handle_text_event(sfEvent event, char *input)
{
    if (event.text.unicode >= '0'
        && event.text.unicode <= '9'
        && strlen(input) < 2) {
        strncat(input, (char[]){event.text.unicode, '\0'}, 1);
    } else if (event.text.unicode == 8 && strlen(input) > 0) {
        input[strlen(input) - 1] = '\0';
    }
}

static int handle_key_event(sfEvent event, char *input)
{
    int map_size = 0;

    if (event.key.code == sfKeyEnter) {
        map_size = atoi(input);
        if (map_size >= 1 && map_size <= 100) {
            return map_size;
        } else {
            strcpy(input, "");
        }
    }
    return 0;
}

static void add_text(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./include/src/font.ttf");

    sfText_setString(text, "Bienvenue dans le livre de\nla creation\n\nEnt"
    "rer la taille de \nvotre monde (1-99) :");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f){330, 100});
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void update_prompt_window(sfRenderWindow *prompt_window,
    sfSprite *background_sprite, sfText *text, char *input)
{
    sfText_setString(text, input);
    sfRenderWindow_clear(prompt_window, sfBlack);
    sfRenderWindow_drawSprite(prompt_window, background_sprite, NULL);
    add_text(prompt_window);
    sfRenderWindow_drawText(prompt_window, text, NULL);
    sfRenderWindow_display(prompt_window);
}

static void setup_prompt_window(sfRenderWindow **prompt_window,
    sfSprite **background_sprite, sfText **text, sfFont **font)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfTexture *background_texture =
    sfTexture_createFromFile("./include/src/bible.jpg", NULL);

    *prompt_window =
    sfRenderWindow_create(video_mode, "Map Size Input", sfDefaultStyle, NULL);
    *font = sfFont_createFromFile("./include/src/font.ttf");
    *text = sfText_create();
    *background_sprite = sfSprite_create();
    sfSprite_setTexture(*background_sprite, background_texture, sfTrue);
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 100);
    sfText_setPosition(*text, (sfVector2f){550, 400});
    sfText_setColor(*text, sfBlack);
}

static void destroy_prompt_window(sfRenderWindow *prompt_window,
    sfSprite *background_sprite, sfText *text, sfFont *font)
{
    sfText_destroy(text);
    sfFont_destroy(font);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(background_sprite));
    sfSprite_destroy(background_sprite);
    sfRenderWindow_destroy(prompt_window);
}

static int event_cond(sfEvent *event,
    sfRenderWindow *prompt_window, int *map_size, char *input)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(prompt_window);
    if (event->type == sfEvtTextEntered)
        handle_text_event(*event, input);
    if (event->type == sfEvtKeyPressed) {
        *map_size = handle_key_event(*event, input);
        if (*map_size > 0)
            sfRenderWindow_close(prompt_window);
    }
}

int prompt_for_map_size(sfRenderWindow *window)
{
    char input[3] = "";
    int map_size = 0;
    sfRenderWindow *prompt_window;
    sfSprite *background_sprite;
    sfText *text;
    sfFont *font;
    sfEvent event;

    setup_prompt_window(&prompt_window, &background_sprite, &text, &font);
    while (sfRenderWindow_isOpen(prompt_window)) {
        while (sfRenderWindow_pollEvent(prompt_window, &event))
            event_cond(&event, prompt_window, &map_size, input);
        update_prompt_window(prompt_window, background_sprite, text, input);
    }
    destroy_prompt_window(prompt_window, background_sprite, text, font);
    return map_size;
}
