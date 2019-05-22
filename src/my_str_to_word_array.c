/*
** EPITECH PROJECT, 2018
** make an array
** File description:
** create an array with string
*/

#include <stdlib.h>

int word_size(char const *str, int start)
{
    int x = start;

    for ( ; str[x] != ' ' && str[x] != '\0' && str[x] != '\n'
    && str[x] != '\t' ; x++);
    return (x - start);
}

int count_word(char const *str)
{
    int  word = 0;

    for (int i = 0 ; str[i] != '\0' && str[i] != '\n' ; i += 1) {
        if (str[i] != ' ' &&  str[i] != '\t') {
            word += 1;
            i += word_size(str, i);
        }
        if (str[i] == '\0')
            break;
    }
    return (word);
}

char *my_strcopy(char const *src, int *index)
{
    char *temp = NULL;
    int i = 0;
    int x = *index;

    temp = malloc(sizeof(char) * (word_size(src, x) + 1));
    if (temp == NULL)
        return (NULL);
    for ( ; src[x] != '\n' && src[x] != ' ' && src[x] != '\0'
    && src[x] != '\t'; i++) {
        temp[i] = src[x];
        x += 1;
    }
    temp[i] = '\0';
    *index = x;
    return (temp);
}

char **my_str_to_word_array(char const *str)
{
    int word_nb = count_word(str);
    char **temp = NULL;
    int index = 0;

    temp = malloc(sizeof(char *) * (word_nb + 1));
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; str[i] != '\0' && str[i] != '\n' ; i += 1) {
        if (str[i] != ' ' && str[i] != '\t') {
            temp[index] = my_strcopy(str, &i);
            index += 1;
        }
        if (str[i] == '\0')
            break;
    }
    temp[index] = NULL;
    return (temp);
}