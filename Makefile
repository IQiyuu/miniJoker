NAME = minijoker

LIB = minilib.a

FILES = listener \
		parser \
		signals \
		mini_free \
		exec \
		mini_exec \
		mini/mini_echo \
		mini/mini_env \
		mini/mini_export \
		mini/mini_unset \
		mini/mini_cd \
		quote_manager \
		quote_managerbis

SRC = $(foreach f, $(FILES), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

FS = -fsanitize=address -g

CFLAGS = -Iheaders -I/Users/dgoubin/.brew/opt/readline/include/ -Werror -Wextra -Wall

GFLAGS = -Iheaders $(LIB) -lreadline -I/Users/dgoubin/.brew/opt/readline/include/readline/ -L/Users/dgoubin/.brew/opt/readline/lib -Werror -Wextra -Wall

all: $(NAME)
r: re
	./minijoker

$(NAME): $(LIB) $(OBJ)
	@printf "> \x1b[32mAll objects compiled\x1b[0m\n"
	@gcc -o $(NAME) srcs/main.c $(OBJ) $(GFLAGS) $(FS)
	@printf "> \x1b[32mExecutable compiled\x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $< $(FS)

$(LIB):
	@make -C minilib
	@cp minilib/minilib.a ./

clean:
	@make -C minilib clean
	@printf ">  \x1b[31mAll minilib objects cleaned\x1b[0m\n"
	@rm -rf $(OBJ)
	@printf "> \x1b[31mAll objects cleaned\x1b[0m\n"

fclean: clean
	@make -C minilib fclean
	@rm -rf $(NAME) $(LIB)
	@printf "> \x1b[31m$(NAME) cleaned\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re