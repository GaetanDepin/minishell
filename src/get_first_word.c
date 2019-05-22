/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** get_first_word
*/

#include <stdlib.h>

char *get_first_word(char *str)
{
    char *temp = NULL;
    int s = 0;
    int d = 0;

    for ( ; str[d] == ' ' || str[d] == '\t' ; d += 1);
    for ( ; str[s + d] != ' ' && str[s + d] != '\0' && str[s + d] != '\n'
    && str[s + d] != '\t' ; )
        s += 1;
    temp = malloc(sizeof(char) * (s + 1));
    if (temp == NULL)
        return (NULL);
    temp[s] = '\0';
    for (int i = d ; i < s + d ; i += 1)
        temp[i - d] = str[i];
    return (temp);
}