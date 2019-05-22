/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** add_to_array
*/

#include <stdlib.h>
#include "minishell.h"

int count_size_array(char **array)
{
    int size = 0;

    for ( ; array[size] != NULL ; size += 1);
    return (size);
}

char *generate_row(char *str)
{
    int lenght = my_strlen(str);
    char *temp = malloc(sizeof(char) * (lenght + 1));

    if (temp == NULL)
        return (NULL);
    temp[lenght] = '\0';
    for (int ii = 0 ; str[ii] != '\0' ; ii += 1)
        temp[ii] = str[ii];
    return (temp);
}

char **copy_table(char **table)
{
    int size = 0;
    char **temp = NULL;

    for ( ; table[size] != NULL ; size += 1);
    temp = malloc(sizeof(char *) * (size + 1));
    if (temp == NULL)
        return (NULL);
    temp[size] = NULL;
    for (int i = 0 ; table[i] != NULL; i += 1) {
        temp[i] = generate_row(table[i]);
        if (temp[i] == NULL)
            return (NULL);
    }
    return (temp);
}

char **add_to_array(char **array, char *str)
{
    char **temp = NULL;
    int size = count_size_array(array) + 1;
    int i = 0;

    temp = malloc(sizeof(char *) * (size + 1));
    if (temp == NULL)
        return (NULL);
    temp[size] = NULL;
    for ( ; array[i] != NULL ; i += 1)
        temp[i] = array[i];
    temp[i] = generate_row(str);
    free(array);
    return (temp);
}