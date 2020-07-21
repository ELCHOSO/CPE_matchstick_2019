/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** header
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef HEADER_H_
#define HEADER_H_

typedef struct linematch
{
    char *line;
    char *match;
}linematch_t;

void print_map(char **map, int line, int game_status);
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nb);
char **create_map(int size);
char **fill_map(int size);
void remove_match(char **map, int line, int nbr);
int match_nbr(char **map, int line);
int my_atoi(char *str);
int is_gameover(char **map, char *av1);
char *get_next_line(int fd);
void remove_match(char **map, int line, int nbr);
int player_turn(int size, int max, char **map, int *turn);
int my_str_isnum(char *str);
int invalid_line(int m, int size, char **map, linematch_t lm);
int invalid_match(int max, int size, char **map, linematch_t lm);


#endif
