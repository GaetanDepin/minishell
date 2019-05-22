/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_pipe
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include "minishell.h"

void exec_current(int index, char **cmd, char **env, int output[2]);

static void set_input(char **cmd, int index)
{
    int fd = 0;
    char buff[51];
    size_t size = 0;

    if (cmd[index + 1] != NULL && cmd[index + 2] != NULL) {
        if (cmd[index + 1][0] != '<')
            return;
        fd = open(cmd[index + 2], O_RDONLY);
        if (fd < 0) {
            mputerror(cmd[index + 2]);
            mputerror(": No such file or directory.\n");
            exit(84);
        }
        while ((size = read(fd, buff, 50)) > 0)
            write(0, buff, size);
    }
}

static void exec_current_pipe(pid_t cpid, char **cmd, int index, char **env)
{
    char **prog = my_str_to_word_array(cmd[index]);
    int status = 0;
    pid_t w;

    verif_cat(prog);
    if (prog == NULL)
        exit(84);
    get_path(&prog, env);
    if (prog[0] == NULL)
        exit (84);
    if (cpid > -1) {
        w = waitpid(cpid, &status, 0);
        if (w == -1) {
            perror("waitpid");
            exit(84);
        }
        display_status(status);
    }
    set_input(cmd, index);
    execve(prog[0], prog, env);
    exit(84);
}

/*
Double char with array of all the command and index contains the index of the
last element index decrease progressively and reach 0 when they are no command
reaming
*/
static void exec_with_pipe(int index, char **cmd, char **env)
{
    int input[2];
    pid_t cpid = -1;

    if (index < 0) {
        exit (0);
    } else if (index > 1) {
        if (pipe(input) != 0)
            perror("pipe");
        cpid = fork();
        if (cpid < 0)
            perror("fork");
        if (cpid == 0)
            exec_current(index - 2, cmd, env, input);
        dup2(input[0], 0);
        close(input[0]);
        close(input[1]);
    }
    if (index - 1 > 0)
        if (cmd[index - 1][0] == '>' || cmd[index - 1][0] == '<')
            exit(0);
    exec_current_pipe(cpid, cmd, index, env);
}

void exec_current(int index, char **cmd, char **env, int output[2])
{
    int fd = 0;

    if (index < 0)
        exit (84);
    if (index + 1 > 0 && cmd[index + 1][0] == '>') {
        fd = open(cmd[index + 2], O_WRONLY | O_CREAT, 0644);
        dup2(fd, 1);
    } else {
        dup2(output[1], 1);
    }
    close(output[0]);
    close(output[1]);
    exec_with_pipe(index, cmd, env);
}

/*
Duplicate main process to keep prog load
*/
int exec_pipe(char **argv, char **envp)
{
    int status = 0;
    pid_t cpid;
    pid_t w;
    int size = 0;

    verif_arg(argv, &envp);
    cpid = fork();
    if (cpid == -1)
        return (84);
    if (cpid == 0) {
        size = count_size_array(argv);
        if (size % 2 != 1 || size > 100)
            exit(84);
        exec_with_pipe(size - 1, argv, envp);
    } else {
        w = waitpid(cpid, &status,0);
        if (w == -1)
            return (84);
        display_status(status);
    }
    return (0);
}