/*
** EPITECH PROJECT, 2025
** menu.c
** File description:
** c file for menu
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

int is_mouse_over(sfVector2f mousePos, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_contains(&bounds, mousePos.x, mousePos.y);
}

static void credit_text(game_t *game)
{
    sfFont *font;
    sfText *text;

    if (game->button->show_credits) {
        font = sfFont_createFromFile("./include/src/font.ttf");
        text = sfText_create();
        sfText_setPosition(text, (sfVector2f){50, 100});
        sfText_setFont(text, font);
        sfText_setColor(text, sfBlack);
        sfText_setString(text,
            "Made by :\n\n- Silas Defossez\n- Laume Laqueste");
        sfText_setCharacterSize(text, 50);
        sfRenderWindow_drawText(game->window->window, text, NULL);
        sfText_destroy(text);
        sfFont_destroy(font);
    }
    sfRenderWindow_display(game->window->window);
}

void clic_menu(sfRenderWindow *window, game_t *game, sfEvent event,
    sfVector2f mousePos)
{
    if (game->button->state == 0 && is_mouse_over
        (mousePos, game->button->btnCred))
        game->button->show_credits = !game->button->show_credits;
    if (game->button->state == 0 && is_mouse_over
    (mousePos, game->button->btnLeave))
        sfRenderWindow_close(game->window->window);
    if (game->button->state == 1 && is_mouse_over
    (mousePos, game->window->btnRes))
        reset_map(game);
    if (game->button->state == 0 && is_mouse_over
    (mousePos, game->button->btnStart)) {
        reset_map(game);
        game->button->state = 1;
    } else if (game->button->state == 1 && is_mouse_over
    (mousePos, game->button->btnExit)) {
        game->button->state = 0;
    }
}

static void init_menu_button(init_button_t *button)
{
    button->btnCredTexture = sfTexture_createFromFile
    ("./include/src/button_credits.png", NULL);
    button->btnCred = sfSprite_create();
    sfSprite_setTexture(button->btnCred, button->btnCredTexture, sfTrue);
    sfSprite_setPosition(button->btnCred, (sfVector2f){770, 400});
    sfSprite_setScale(button->btnCred, (sfVector2f){2.0f, 2.0f});
    button->btnLeaveTexture = sfTexture_createFromFile
    ("./include/src/button_leave.png", NULL);
    button->btnLeave = sfSprite_create();
    sfSprite_setTexture(button->btnLeave, button->btnLeaveTexture, sfTrue);
    sfSprite_setPosition(button->btnLeave, (sfVector2f){770, 550});
    sfSprite_setScale(button->btnLeave, (sfVector2f){2.0f, 2.0f});
    button->state = 0;
    button->show_credits = 0;
    return;
}

init_button_t *init_button(void)
{
    init_button_t *button = malloc(sizeof(init_button_t));

    if (!button)
        return NULL;
    button->btnTexture = sfTexture_createFromFile
    ("./include/src/button.png", NULL);
    button->btnStart = sfSprite_create();
    sfSprite_setTexture(button->btnStart, button->btnTexture, sfTrue);
    sfSprite_setPosition(button->btnStart, (sfVector2f){770, 250});
    sfSprite_setScale(button->btnStart, (sfVector2f){2.0f, 2.0f});
    button->btnExitTexture = sfTexture_createFromFile(
    "./include/src/button_exit.png", NULL);
    button->btnExit = sfSprite_create();
    sfSprite_setTexture(button->btnExit, button->btnExitTexture, sfTrue);
    sfSprite_setPosition(button->btnExit, (sfVector2f){1920 - 100, 15});
    init_menu_button(button);
    return button;
}

void displaying_menu(game_t *game)
{
    handle_event(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_setView(game->window->window, game->window->view_ui);
    sfRenderWindow_drawSprite(game->window->window,
    game->window->back_menu_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window, game->button->btnStart,
    NULL);
    sfRenderWindow_drawSprite(game->window->window, game->button->btnCred,
    NULL);
    sfRenderWindow_drawSprite(game->window->window, game->button->btnLeave,
    NULL);
    credit_text(game);
}
