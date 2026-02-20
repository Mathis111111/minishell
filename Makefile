CC = clang
NAME = mysh
A.OUT = a.out
SRC = \
	main.c \
	lib/my/my_strcat_malloc.c \
	lib/my/my_str_to_word_array.c \
	lib/my/my_strcmp.c \
	lib/my/my_strcmp_modif.c \
	lib/my/my_strdup.c \
	lib/my/my_strlen.c \
	lib/my/my_putstr.c \
	lib/my/my_putstr_error.c \
	lib/my/my_getnbr.c \
	lib/my/is_alpha_num_for_setenv.c \
	lib/my/my_strndup.c \
	cd_functions.c \
	command_exec.c \
	free_function.c \
	construct_env.c \
	error_handling.c \
	env_functions.c \
	stdout_msg.c \
	initialize_cd.c \
	exit_and_ctrl.c \
	signaux_function.c \
	setenv.c \
	minishell.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(A.OUT)

re: fclean all

.PHONY: all clean fclean re