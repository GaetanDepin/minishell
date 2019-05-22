/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_arg
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

int command_size(char const *str, int start)
{
    int x = start;

    for ( ; str[x] != '\0' && str[x] != '\n' && str[x] != '|'
    && str[x] != '<' && str[x] != '>'  ; x++)
        if (only_space(str, x) == 0)
            break;
    return (x - start);
}

static int count_command(char const *str)
{
    int  word = 1;

    for (int i = 0 ; str[i] != '\0' && str[i] != '\n' ; i++) {
        if (str[i] == '|' ||  str[i] == '<' || str[i] == '>') {
            word += 2;
            str[i + 1] == '<' ? i++ : i;
            str[i + 1] == '>' ? i++ : i;
        }
        if (str[i] == '\0')
            break;
    }
    return (word);
}

static char *get_command(char const *src, int *index)
{
    char *temp = NULL;
    int x = *index;
    int size = command_size(src, x);

    temp = malloc(sizeof(char) * (size + 1));
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i < size ; i++) {
        temp[i] = src[x];
        x += 1;
    }
    temp[size] = '\0';
    *index = x;
    return (temp);
}

static int get_operation(char *src, int i, int *index, char **temp)
{
    if (src[i] == '>' || src[i] == '<' || src[i] == '|') {
        temp[*index] = malloc(sizeof(char) * 2);
        if (temp[*index] == NULL)
            return (84);
        temp[*index][0] = src[i];
        temp[*index][1] = '\0';
        *index += 1;
    }
    return (0);
}

char **get_arg(char *input)
{
    int word_nb = count_command(input);
    char **temp = NULL;
    int index = 0;

    temp = malloc(sizeof(char *) * (word_nb + 1));
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; input[i] != '\0' && input[i] != '\n' ; i += 1) {
        if (input[i] != '>' && input[i] != '<' && input[i] != '|'
        && input[i] != ' ' && input[i] != '\t') {
            temp[index] = get_command(input, &i);
            index += 1;
        }
        get_operation(input, i, &index, temp);
        if (input[i] == '\0')
            break;
    }
    temp[index] = NULL;
    return (temp);
}