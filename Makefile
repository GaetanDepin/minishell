##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	mysh

SRC	=	src/main.c\
		src/minishell.c\
		src/print.c\
		src/str_cmp.c\
		src/get_first_word.c\
		src/my_str_to_word_array.c\
		src/array_gest.c\
		src/str_conc.c\
		src/array_remove.c\
		src/get_number.c\
		src/text_gest.c\
		src/command/make_env.c\
		src/command/make_cd.c\
		src/command/edit_env.c\
		src/command/make_default.c\
		src/command/make_exec.c\
		src/command/make_exit.c\
		src/command/command_handler.c\
		src/command/split_command.c\
		src/command/exec_pipe.c\
		src/command/verif_arg.c\
		src/get_arg.c\
		src/tool/only_space.c\
		src/tool/get_exec_path.c

TEST_SRC =  src/minishell.c\
			src/print.c\
			src/str_cmp.c\
			src/get_first_word.c\
			src/my_str_to_word_array.c\
			src/array_gest.c\
			src/str_conc.c\
			src/array_remove.c\
			src/get_number.c\
			src/text_gest.c\
			src/command/make_env.c\
			src/command/make_cd.c\
			src/command/edit_env.c\
			src/command/make_default.c\
			src/command/make_exec.c\
			src/command/make_exit.c\
			src/command/command_handler.c\
			src/command/split_command.c\
			src/command/exec_pipe.c\
			src/command/verif_arg.c\
			src/get_arg.c\
			src/tool/only_space.c\
			src/tool/get_exec_path.c\
			tests/main_criterion.c\
			tests/gene_env.c\
			tests/print_test.c

OBJ		=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-I./include -g3 -Wall -Wextra -Werror

CRITERION = --coverage -lcriterion

TEST_BIN = test_mysh

all:			$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

tests_run:
		$(CC) $(TEST_SRC) -o $(TEST_BIN) $(CFLAGS) $(CRITERION)
		./$(TEST_BIN)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
