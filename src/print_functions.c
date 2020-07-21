/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** print map functions
*/

#include <unistd.h>
#include "header.h"

void print_map(char **map, int line, int game_status)
{
    int x = 0;

    for (int y = 0; y != line + 2; y++) {
        for (; x != line * 2 + 1; x++) {
            my_putchar(map[y][x]);
        }
        my_putchar('\n');
        x = 0;
    }
    if (game_status == 0)
        my_putchar('\n');
}

void print_removed_match(linematch_t lm)
{
    my_putstr("Player removed ");
    my_putnbr(my_atoi(lm.match));
    my_putstr(" match(es) from line ");
    my_putnbr(my_atoi(lm.line));
    my_putchar('\n');
}

int player_turn(int size, int const max, char **map, int *turn)
{
    linematch_t lm = {NULL, NULL};
    size_t sizeuh;

    if (*turn == 1)
        my_putstr("Your turn:\n");
    my_putstr("Line: ");
    if (getline(&lm.line, &sizeuh, stdin) == -1)
        return (84);
    if (invalid_line(max, size, map, lm) == 1) {
        *turn = -1;
        return (1);
    }
    my_putstr("Matches: ");
    if (getline(&lm.match, &sizeuh, stdin) == -1)
        return (84);
    if (invalid_match(max, size, map, lm) == 1) {
        *turn = -1;
        return (1);
    }
    print_removed_match(lm);
    remove_match(map, my_atoi(lm.line), my_atoi(lm.match));
    *turn = 2;
    return (0);
}