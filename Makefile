##
## EPITECH PROJECT, 2019
## my_sokoban_2019
## File description:
## Project makefile
##

SRC	=	main.c		\
		file.c		\
		run.c		\
		my_sokoban.c	\
		game_function.c

SRC_UT	=	file.c	\
		run.c	\
		my_sokoban.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lncurses
	make clean

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o $(NAME) $(SRC_UT) tests/test_sokoban.c -I./include -L./lib/my -lmy -lcriterion && ./$(NAME)
	make fclean

.PHONY :        clean fclean re
