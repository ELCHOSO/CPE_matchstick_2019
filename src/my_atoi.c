/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (str[i] < 32)
        i++;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] < 58 && str[i] > 47) {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * sign);
}

int my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] <= '9' & str[i] >= '0') || (str[i] == '\n'))
            i++;
        else
            return (0);
    }
    return (1);
}