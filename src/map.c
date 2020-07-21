/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** map
*/

#include "header.h"

char **create_map(int size)
{
    char **map = malloc(sizeof(char *) * (size + 2));
    int x = 0;

    for (int y = 0; y != size + 2; y++)
        map[y] = malloc(sizeof(char) * size * 2 + 1);
    for (int y = 0; y != size + 2; y++) {
        for (; x != size * 2 + 1; x++) {
            map[y][x] = ' ';
            if (y == 0 || x == 0 || y == size + 1 || x == size * 2)
                map[y][x] = '*';
        }
        x = 0;
    }
    return (map);
}

char **fill_map(int size)
{
    char **map = create_map(size);
    int matchnbr = 1;
    int x = size;

    for (int y = 1; y != size + 1; y++) {
        for (int i = 0; i != matchnbr; i++, x++)
            map[y][x] = '|';
        x = x - (matchnbr + 1);
        matchnbr += 2;
    }
    return (map);
}

int is_gameover(char **map, char *av1)
{
    int size = my_atoi(av1);
    int x = 1;

    for (int y = 1; y != size + 1; y++) {
        for (; x != size * 2 - 1; x++) {
            if (map[y][x] == '|')
                return (0);
        }
        x = 0;
    }
    return (1);
}