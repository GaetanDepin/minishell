/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_default
*/

#include <stdlib.h>
#include "minishell.h"

int make_default(char *arg, char ***envp)
{
    make_exec(arg, envp);
    return (0);
}