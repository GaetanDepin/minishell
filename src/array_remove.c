/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** array_remove
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

int verif_line(char **dest, char *src, char *to_rm)
{
    char *temp = NULL;

    if (compare_var(src, to_rm) == -1) {
        temp = generate_row(src);
        if (temp == NULL)
            return (84);
        *dest = temp;
        return (0);
    } else {
        return (-1);
    }
}

char **remove_from_array(char *str, char **array)
{
    char **temp = NULL;
    int i = 0;

    for ( ; array[i] != NULL && compare_var(array[i], str) == -1 ; i += 1);
    temp = remove_at_index(array, i);
    return (temp);
}

char **remove_at_index(char **array, int index_rm)
{
    char **temp = NULL;
    int size = count_size_array(array) - 1;
    int index = 0;

    temp = malloc(sizeof(char *) * (size + 1));
    if (temp == NULL)
        return (NULL);
    temp[size] = NULL;
    for (int i = 0 ; array[i] != NULL ; i += 1) {
        if (i != index_rm) {
            temp[index] = array[i];
            index += 1;
        }
    }
    free(array[index_rm]);
    free(array);
    return (temp);
}