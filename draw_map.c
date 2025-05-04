/*
** EPITECH PROJECT, 2025
** draw map
** File description:
** draw the map for my world
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

static sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 = {.position = *p1, .color = sfWhite};
    sfVertex v2 = {.position = *p2, .color = sfWhite};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    return vertex_array;
}

static void draw_vertical_lines(game_t *game, sfVector2f **map)
{
    sfVertexArray *line;

    for (int y = 0; y < game->map->MAX_Y - 1; y++) {
        for (int x = 0; x < game->map->MAX_X; x++) {
            line = create_line(&map[y][x], &map[y + 1][x]);
            sfRenderWindow_drawVertexArray(game->window->window, line, NULL);
            sfVertexArray_destroy(line);
        }
    }
}

static void draw_horizontal_lines(game_t *game, sfVector2f **map)
{
    sfVertexArray *line;

    for (int y = 0; y < game->map->MAX_Y; y++) {
        for (int x = 0; x < game->map->MAX_X - 1; x++) {
            line = create_line(&map[y][x], &map[y][x + 1]);
            sfRenderWindow_drawVertexArray(game->window->window, line, NULL);
            sfVertexArray_destroy(line);
        }
    }
}

static sfVertexArray *add_square_texture(sfVector2f **array,
    sfTexture *texture)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2u size_texture = sfTexture_getSize(texture);
    sfVertex vertex1 = {.position = *array[0], .color = sfWhite,
        .texCoords = {0, 0}};
    sfVertex vertex2 = {.position = *array[1], .color = sfWhite,
        .texCoords = {0, size_texture.y}};
    sfVertex vertex3 = {.position = *array[2], .color = sfWhite,
        .texCoords = {size_texture.x, size_texture.y}};
    sfVertex vertex4 = {.position = *array[3], .color = sfWhite,
        .texCoords = {size_texture.x, 0}};

    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    return vertex_array;
}

static sfTexture *chose_texture(game_t *game,
    sfVector2f **map, int x, int y)
{
    if (game->map->map[x][y] > 50) {
        if (game->window->loop_music == 1)
            return game->map->easter_egg;
        game->window->loop_music = 1;
        game->window->music = 1;
        return game->map->easter_egg;
    }
    if (game->map->map[x][y] > 8)
        return game->map->texture_snow;
    if (game->map->map[x][y] > 0.75)
        return game->map->texture_stone;
    if (game->map->map[x][y] < -3)
        return game->map->texture_water;
    if (game->map->map[x][y] < 0)
        return game->map->texture_dirt;
    return game->map->ground_texture;
}

static void draw_colored_lines(game_t *game,
    sfVector2f **map, int x, int y)
{
    sfTexture *texture = chose_texture(game, map, x, y);
    sfRenderStates state = {sfBlendAlpha, sfTransform_Identity, texture, NULL};
    sfVector2f **array = malloc(sizeof(sfVector2f *) * 4);
    sfVertexArray *square = NULL;

    if (x < game->map->MAX_X - 1) {
        array[0] = &map[x][y];
        array[1] = &map[x][y + 1];
        array[2] = &map[x + 1][y + 1];
        array[3] = &map[x + 1][y];
        square = add_square_texture(array, texture);
        sfRenderWindow_drawVertexArray(game->window->window, square, &state);
        sfVertexArray_destroy(square);
    }
}

void display_world(game_t *game, sfVector2f **map)
{
    for (int i = 0; i < game->map->MAX_X; i++) {
        for (int y = 0; y < game->map->MAX_Y - 1; y++)
            draw_colored_lines(game, map, i, y);
    }
}

void draw_2d_map(game_t *game, sfVector2f **map)
{
    draw_horizontal_lines(game, map);
    draw_vertical_lines(game, map);
    display_world(game, map);
}
