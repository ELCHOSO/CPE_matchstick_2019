/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** invalid value check
*/

#include "header.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    while (s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int invalid_line(int m, int size, char **map, linematch_t lm)
{
    if (my_str_isnum(lm.line) == 0 || my_strcmp(lm.line, "\n") == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_atoi(lm.line) <= 0 || my_atoi(lm.line) > size) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int invalid_match_end(int max, int size, char **map, linematch_t lm)
{
    if (my_atoi(lm.match) == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (my_atoi(lm.match) > max) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(max);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (match_nbr(map, my_atoi(lm.line)) < my_atoi(lm.match)) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int invalid_match(int max, int size, char **map, linematch_t lm)
{
    if (my_strcmp(lm.match, "\n") == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_atoi(lm.match) < 0 || my_str_isnum(lm.match) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (invalid_match_end(max, size, map, lm) == 1)
        return (1);
    return (0);
}
