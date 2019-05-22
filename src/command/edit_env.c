/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** edit_env
*/

#include <stdlib.h>
#include "minishell.h"

char *get_env(char *var_name, char **envp)
{
    int index = 0;
    char *temp = NULL;
    int size = 0, start = 0;

    for ( ; envp[index] != NULL ; index += 1)
        if (compare_var(envp[index], var_name) == 0)
            break;
    if (envp[index] == NULL)
        return (NULL);
    for ( ; envp[index][start] != '=' ; start += 1);
    start += 1;
    for ( ; envp[index][size] != '\0' ; size += 1);
    temp = malloc(sizeof(char) * (size + 1));
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i <= size ; i += 1)
        temp[i] = '\0';
    for (int i = 0 ; envp[index][start] != '\0' ; i += 1, start += 1)
        temp[i] = envp[index][start];
    return (temp);
}

int replace_env(char *var_name, char *value, char **envp)
{
    int index = 0;
    int size = my_strlen(var_name) + my_strlen(value) + 1;

    for ( ; envp[index] != NULL ; index += 1)
        if (compare_var(envp[index], var_name) == 0)
            break;
    if (envp[index] == NULL)
        return (84);
    free(envp[index]);
    envp[index] = NULL;
    envp[index] = malloc(sizeof(char) * (size + 1));
    if (envp[index] == NULL)
        return (84);
    envp[index] = conc_env_name(var_name, value);
    return (0);
}