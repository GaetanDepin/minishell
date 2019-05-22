/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** split_command
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

static int get_command_size(char *str, int start)
{
    int size = 0;
    int i = start;

    for ( ; str[i] != '\0' && str[i] != ';' ; i++, size++);
    return (size);
}

static int split(char *input, char ***command)
{
    int size = 1;
    int cmd_size = 0;
    int start = 0;

    for (int i = 0 ; input[i] != '\0' ; i++)
        if (input[i] == ';')
            size++;
    *command = malloc(sizeof(char*) * (size + 1));
    if (*command == NULL)
        return (84);
    (*command)[size] = NULL;
    for (int i = 0 ; i < size ; i++) {
        for ( ; input[start] == ' ' || input[start] == ';' ; start++);
        cmd_size = get_command_size(input, start);
        if (((*command)[i] = malloc(sizeof(char) * (cmd_size + 1))) == NULL) 
            return (84);
        for (int ii = 0 ; ii < cmd_size ; ii++, start++)
            (*command)[i][ii] = input[start];
        (*command)[i][cmd_size] = '\0';
    }
    return (0);
}

int split_command(char *input, char ***envp)
{
    char **command = NULL;

    if (split(input, &command) == 84)
        return (84);
    for (int i = 0 ; command[i] != NULL ; i++)
        if (command_handler(command[i], envp) == 84)
            return (84);
    for (int i = 0 ; command[i] != NULL ; i++)
        free(command[i]);
    free(command);
    return (0);
}