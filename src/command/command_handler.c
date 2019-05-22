/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** command_handler
*/

#include <stdlib.h>
#include "minishell.h"

int is_empty(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (str[i] != ' ')
            return (-1);
    }
    return (0);
}

int select_operation(char ***envp, char *arg, my_func_t table[SIZE_FUNC])
{
    char *first_word = get_first_word(arg);
    int i = 0;
    int result = 0;

    if (first_word == NULL)
        return (84);
    if (is_empty(first_word) == 0)
        return (0);
    for ( ; i < SIZE_FUNC ; i += 1) {
        if (str_compare(first_word, table[i].name) == 0 || i == 5) {
            result = (table[i].func_ptr)(arg, envp);
            break;
        }
    }
    if (i == SIZE_FUNC && arg[0] != '\0') {
        mputerror(first_word);
        mputerror(": Command not found.\n");
    }
    free(first_word);
    return (result);
}

int command_handler(char *input, char ***envp)
{
    my_func_t table[SIZE_FUNC] = {{&make_cd, "cd"},
    {&make_set_env, "setenv"}, {&make_unset_env, "unsetenv"},
    {&make_exec, "./*"}, {&make_exit, "exit"}, {&make_default, ""}};

    return (select_operation(envp, input, table));
}