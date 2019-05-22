/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** get_number
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    if (str[i] == '-') {
        i += 1;
        neg *= -1;
    }
    for ( ; str[i] >= '0' && str[i] <= '9' ; i += 1) {
        nb += str[i] - '0';
        if (str[i + 1] != '\0' && str[i + 1] != '\n')
            nb *= 10;
    }
    nb *= neg;
    return (nb);
}

int is_number(char *str)
{
    for (int i = 0 ; str[i] != '\0' && str[i] != '\n' ; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    }
    return (0);
}