/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** str_conc
*/

#include <stdlib.h>
#include "minishell.h"

char *conc_env_name(char *part1, char *part2)
{
    char *temp = NULL;
    int size1 = 0;
    int size2 = 0;
    int index = 0;

    size1 = my_strlen(part1);
    if (part2 != NULL)
        size2 = my_strlen(part2);
    temp = malloc(sizeof(char) * (size1 + size2 + 2));
    if (temp == NULL)
        return (NULL);
    temp[size1 + size2 + 1] = '\0';
    for ( ; part1[index] != '\0' ; index += 1)
        temp[index] = part1[index];
    temp[index] = '=';
    index += 1;
    if (part2 != NULL) {
        for (int i = 0 ; part2[i] != '\0' ; i += 1, index += 1)
            temp[index] = part2[i];
    }
    return (temp);
}