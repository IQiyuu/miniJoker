NAME = miniJoker

FILES = listener \
		parser \
		utils \
		signals \
		ft_free \
		env \
		utils2 \
		exec \
		ft_exec \
		ft_echo \
		ft_env \
		utils3

SRC = $(foreach f, $(FILES), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

CFLAGS = -Iheaders -I/Users/dgoubin/.brew/opt/readline/include/ -fsanitize=address -g -Werror -Wextra -Wall

GFLAGS += -Iheaders -lreadline -I/Users/dgoubin/.brew/opt/readline/include/readline/ -L/Users/dgoubin/.brew/opt/readline/lib -fsanitize=address -g -Werror -Wextra -Wall

all: $(NAME)
r: re
	./miniJoker

$(NAME): $(OBJ)
	@printf "\x1b[32mAll objects compiled\x1b[0m\n"
	@gcc -o $(NAME) srcs/main.c $(OBJ) $(GFLAGS)
	@printf "\x1b[32mExecutable compiled\x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@printf "\x1b[32mAll objects cleaned\x1b[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "\x1b[32mExecutable cleaned\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re