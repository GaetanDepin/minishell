/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** print
*/

#include <unistd.h>

int is_alpha(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (str[i] < '0' || (str[i] > '9' && str[i] < 'A'))
            return (-1);
        if ((str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (-1);
    }
    return (0);
}

int my_strlen(char *str)
{
    int size = 0;

    for ( ; str[size] != '\0' ; size += 1);
    return (size);
}

void mputstr(char *str)
{
    write(1, str, my_strlen(str));
}

void mputchar(char c)
{
    write(1, &c, 1);
}

void mputerror(char *str)
{
    write(2, str, my_strlen(str));
}