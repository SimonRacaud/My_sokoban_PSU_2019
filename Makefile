##
## EPITECH PROJECT, 2019
## my_sokoban_2019
## File description:
## Project makefile
##

DSRC	= ./src/

SRC	=	$(DSRC)main.c			\
		$(DSRC)file.c			\
		$(DSRC)run.c			\
		$(DSRC)my_sokoban.c		\
		$(DSRC)game_function.c		\
		$(DSRC)player.c			\
		$(DSRC)box.c			\
		$(DSRC)eval_game.c

SRC_UT	=	$(DSRC)file.c			\
		$(DSRC)run.c			\
		$(DSRC)player.c			\
		$(DSRC)my_sokoban.c		\
		$(DSRC)game_function.c		\
		$(DSRC)box.c			\
		$(DSRC)eval_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lncurses

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	#rm -f  *.gcda
	#rm -f  *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o $(NAME) $(SRC_UT) tests/test_sokoban.c -I./include -L./lib/my -lmy -lcriterion --coverage -lncurses && ./$(NAME)

.PHONY :        clean fclean re
