/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_env
*/

#include <stdlib.h>
#include "minishell.h"

static int make_default_setenv(char **envp)
{
    char **temp = NULL;

    temp = malloc(sizeof(char*) * 2);
    if (temp == NULL)
        return (84);
    temp[0] = my_strcpy("/bin/env");
    temp[1] = NULL;
    exec_with_arg(temp, envp);
    free(temp[0]);
    free(temp);
    return (0);
}

int set_my_var(char **s, char ***envp)
{
    char *temp = NULL;

    if (is_alpha(s[1]) == -1) {
        mputerror("setenv: Variable name must ");
        mputerror("contain alphanumeric characters.\n");
        return (84);
    }
    temp = conc_env_name(s[1], s[2]);
    if (temp == NULL)
        return (84);
    *envp = add_to_array(*envp, temp);
    return (0);
}

int make_set_env(char *arg, char ***envp)
{
    char **s = my_str_to_word_array(arg);
    int size = 0;
    int result = 0;

    if (s == NULL)
        return (84);
    for (int i = 0 ; s[i] != NULL ; i += 1, size += 1);
    if (size == 1) {
        make_default_setenv(*envp);
        return (0);
    }
    if (s[1][0] < 'A' || (s[1][0] > 'Z' && s[1][0] < 'a') || s[1][0] > 'z') {
        mputerror("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    result = set_my_var(s, envp);
    for (int i = 0 ; s[i] != NULL ; i += 1)
        free(s[i]);
    free(s);
    return (result);
}

int make_unset_env(char *arg, char ***envp)
{
    char **str = my_str_to_word_array(arg);
    int size = 0;

    (void)arg;
    if (str == NULL)
        return (84);
    for (int i = 0 ; str[i] != NULL ; i +=1, size += 1);
    if (size == 1) {
        mputerror("unsetenv: Too few arguments.\n");
        return (0);
    }
    *envp = remove_from_array(str[1], *envp);
    for (int i = 0 ; str[i] != NULL ; i += 1)
        free(str[i]);
    free(str);
    return (0);
}