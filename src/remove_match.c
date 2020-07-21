/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** remote matches
*/

#include "header.h"

int match_nbr(char **map, int line)
{
    int match = 0;

    for (int x = 1; map[line][x] != '*'; x++) {
        if (map[line][x] == '|')
            match += 1;
    }
    return (match);
}

void remove_match(char **map, int line, int nbr)
{
    int i = 0;
    if (match_nbr(map, line) >= nbr) {
        while (map[line][i] != '|')
        i++;
        while (map[line][i] == '|')
        i++;
        i--;
        for (int j = 0; j != nbr; j++, i--) {
            map[line][i] = ' ';
        }
    }
}