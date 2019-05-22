/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minishell.h"

char *get_input(void)
{
    char *temp = NULL;
    size_t len = 0;

    if (isatty(0) == 1)
        mputstr("$>");
    if (getline(&temp, &len, stdin) == -1) {
        if (isatty(0) == 1)
            mputstr("exit\n");
        free(temp);
        return (NULL);
    }
    return (temp);
}

void handler1(int sig)
{
    (void)sig;
    if (isatty(0) == 1)
        mputstr("\n$>");
}

int minishell(char **envp)
{
    char *input = NULL;
    char **my_env = NULL;

    my_env = copy_table(envp);
    signal(SIGINT, handler1);
    if (my_env == NULL)
        return (84);
    while ((input = get_input()) != NULL) {
        if (split_command(input, &my_env) == -1)
            break;
        free(input);
    }
    for (int i = 0 ; my_env[i] != NULL ; i += 1)
        free(my_env[i]);
    free(my_env);
    return (0);
}
