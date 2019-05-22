/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#define SIZE_FUNC 6

typedef struct my_func_s {
    int (* func_ptr)(char *arg, char ***envp);
    char name[100];
} my_func_t;

int minishell(char **envp);
char *get_input(void);
int str_compare(char *str1, char *str2);
int compare_var(char *str1, char *str2);
char *get_first_word(char *str);
char **my_str_to_word_array(char const *str);
int my_strlen(char *str);
char **add_to_array(char **array, char *str);
int is_alpha(char const *str);
char *conc_env_name(char *part1, char *part2);
char **copy_table(char **table);
char *generate_row(char *str);
int count_size_array(char **array);
char **remove_from_array(char *str, char **array);
char **remove_at_index(char **array, int index_rm);
int my_getnbr(char *str);
int is_number(char *str);
char *get_env(char *var_name, char **envp);
int replace_env(char *var_name, char *value, char **envp);
char *create_dirpath(char *start, char *end);
int exec_with_arg(char **argv, char **envp);
char *my_strcpy(char *src);
char **get_arg(char *input);

//Print
void mputstr(char *str);
void mputchar(char str);
void mputerror(char *str);

//Tool
int only_space(char const *str, int index);

//Exec path
char *get_exec_path(char *prog_name, char **envp);
int get_path(char ***arg, char **env);

//Command
int command_handler(char *input, char ***envp);
int split_command(char *input, char ***envp);
int make_cd(char *arg, char ***envp);
int make_set_env(char *arg, char ***envp);
int make_unset_env(char *arg, char ***envp);
int make_exec(char *arg, char ***envp);
int make_exit(char *arg, char ***envp);
int make_default(char *arg, char ***envp);
int exec_pipe(char **argv, char **envp);
void display_status(int status);

void verif_arg(char **arg, char ***envp);
void verif_cat(char **arg);

#endif
