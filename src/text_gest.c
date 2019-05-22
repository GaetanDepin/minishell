/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** text_gest
*/

#include <stdlib.h>
#include "minishell.h"

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    for (i = 0 ; src[i] != '\0' ; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *create_dirpath(char *start, char *end)
{
    int size = my_strlen(start) + my_strlen(end) + 2;
    char *path = NULL;
    int index = 0;

    if ((path = malloc(sizeof(char) * size)) == NULL)
        return (NULL);
    for (index = 0 ; start[index] != '\0' ; index += 1)
        path[index] = start[index];
    if (path[index - 1] != '/') {
        path[index] = '/';
        index += 1;
    }
    for (int i = 0 ; end[i] != '\0' ; i += 1, index += 1)
        path[index] = end[i];
    path[index] = '\0';
    return (path);
}