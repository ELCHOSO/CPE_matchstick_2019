/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my write functions
*/

#include "header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    write(1, str, i);
}

void my_putnbr(int nb)
{
    long n = nb;

    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n > 9) {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    }
    if (n < 10)
        my_putchar(n + '0');
}