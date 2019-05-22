/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_exec_path
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char *get_one_path_line(char *line, int *index)
{
    int i = *index;
    char *temp = NULL;
    int size = 0;

    if (line[i] == ':' || line[i] == '=')
        i++;
    for (int x = i ; line[x] != ':' && line[x] != '\0' ; x++, size++);
    if ((temp = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    temp[size] = '\0';
    for (int x = 0 ; line[i] != ':' && line[i] != '\0' ; x++, i++)
        temp[x] = line[i];
    *index = i;
    return (temp);
}

char **get_all_path(char **envp, char *name)
{
    char **temp = NULL;
    int i = 0;
    int path_nb = 0;
    int start = 0;

    (void)name;
    for ( ; envp[i] != NULL && compare_var(envp[i], "PATH") ; i += 1);
    if (envp[i] == NULL)
        return (NULL);
    for (int x = 0 ; envp[i][x] != '\0' ; x += 1)
        if (envp[i][x] == ':' || envp[i][x] == '=')
            path_nb++;
    if ((temp = malloc(sizeof(char *) * (path_nb + 1))) == NULL)
        return (NULL);
    for (int g = 0 ; g <= path_nb ; g += 1)
        temp[g] = NULL;
    for ( ; envp[i][start] != '=' && envp[i][start] != '\0' ; start += 1);
    start++;
    for (int index = 0 ; envp[i][start] != '\0' ; index += 1)
        temp[index] = get_one_path_line(envp[i], &start);
    return (temp);
}

char *get_exec_path(char *prog_name, char **envp)
{
    struct stat sb;
    char *temp_path = NULL;
    int i = 0;
    char **all_path = get_all_path(envp, prog_name);

    if (stat(prog_name, &sb) != -1)
            return (my_strcpy(prog_name));
    for ( ; all_path[i] != NULL ; i++) {
        temp_path = create_dirpath(all_path[i], prog_name);
        if (stat(temp_path, &sb) != -1)
            return (temp_path);
        free(temp_path);
    }
    mputerror(prog_name);
    mputerror(": Command not found.\n");
    return (NULL);
}

int get_path(char ***arg, char **env)
{
    char *prog_name = NULL;

    prog_name = get_exec_path((*arg)[0], env);
    free((*arg)[0]);
    (*arg)[0] = prog_name;
    return (0);
}