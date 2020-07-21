/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "header.h"

void bot(int *turn, char **map, int size)
{
    int line = 1;

    while (line != size + 1) {
        if (match_nbr(map, line) > 0) {
            remove_match(map, line, 1);
            break;
        }
        line++;
    }
    *turn = 1;
    my_putstr("AI's turn...\nAI removed 1 match(es) from line ");
    my_putnbr(line);
    my_putchar('\n');
}

int winner_announcement(int turn)
{
    if (turn == 2) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    if (turn == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (1);
    if (my_atoi(av[1]) < 2 || my_atoi(av[1]) > 99)
        return (1);
    if (my_atoi(av[2]) < 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    char **map = fill_map(my_atoi(av[1]));
    int turn = 1;
    int rtn_turn;

    if (error(ac, av) == 1)
        return (84);
    print_map(map, my_atoi(av[1]), 0);
    while (is_gameover(map, av[1]) == 0) {
        if (turn == 1 || turn == -1) {
            if ((rtn_turn =
                player_turn(my_atoi(av[1]), my_atoi(av[2]), map, &turn)) == 84)
                return (0);
            else if (rtn_turn != 1)
                print_map(map, my_atoi(av[1]), is_gameover(map, av[1]));
            if (is_gameover(map, av[1]) == 1)
                break;
        }
        if (turn == 2) {
            bot(&turn, map, my_atoi(av[1]));
            print_map(map, my_atoi(av[1]), is_gameover(map, av[1]));
        }
    }
    return (winner_announcement(turn));
}