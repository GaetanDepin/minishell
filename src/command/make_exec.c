/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_launch
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "minishell.h"

void display_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8) {
            mputerror("Floating exception\n");
        } else {
            mputerror(strsignal(WTERMSIG(status)));
            mputerror("\n");
        }
    }
}

int exec_with_arg(char **argv, char **envp)
{
    int status = 0;
    pid_t cpid;
    pid_t w;

    cpid = fork();
    if (cpid == -1)
        return (84);
    if (cpid == 0) {
        if (execve(argv[0], argv, envp) == -1) {
            mputerror(argv[0]);
            mputerror(": Permission denied.\n");
        }
        exit (127);
    } else {
        w = waitpid(cpid, &status,0);
        if (w == -1)
            return (84);
        display_status(status);
    }
    return (0);
}

int make_exec(char *arg, char ***envp)
{
    char **arguments = NULL;
    int r_value = 0;
    char **prog = NULL;

    arguments = get_arg(arg);
    if (arguments != NULL && arguments[1] != NULL) {
        r_value = exec_pipe(arguments, *envp);
    } else {
        prog = my_str_to_word_array(arguments[0]);
        get_path(&prog, *envp);
        if (prog[0] == NULL)
            return (84);
        r_value = exec_with_arg(prog, *envp);
    }
    return (r_value);
}