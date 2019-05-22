/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** only_space
*/

int only_space(char const *str, int index)
{
    for (int i = index ; str[i] != '\n' && str[i] != '|' && str[i] != '\0'
    && str[i] != '<' && str[i] != '>' ; i++) {
        if (str[i] != '\t' && str[i] != ' ')
            return (84);
    }
    return (0);
}