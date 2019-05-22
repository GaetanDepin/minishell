/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** verif_arg
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void verif_arg(char **arg, char ***envp)
{
    char **temp = NULL;

    for (int i = 0 ; arg[i] != NULL ; i++) {
        temp = my_str_to_word_array(arg[i]);
        if (temp == NULL)
            return;
        if (str_compare(temp[0], "exit") == 0)
            make_exit(arg[i], envp);
        for (int ii = 0 ; temp[ii] != NULL ; ii++)
            free(temp[ii]);
        free(temp);
    }
}

void verif_cat(char **arg)
{
    struct stat sb;

    if (count_size_array(arg) <= 1)
        return;
    if (str_compare(arg[0], "cat") == 0) {
        if (stat(arg[1], &sb) < 0)
            return;
        if (sb.st_size > 50000)
            exit(0);
    }
}