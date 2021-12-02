NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iincludes/ 

SRC := srcs/*.c
GNL := gnl/*.c
LIB := -L minilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) $(GNL) $(LIB) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
