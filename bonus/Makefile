##
## EPITECH PROJECT, 2019
## my_sokoban_2019
## File description:
## Project makefile
##

DSRC	= ./src/

SRC	=	$(DSRC)main.c			\
		$(DSRC)file.c			\
		$(DSRC)display.c		\
		$(DSRC)menu.c		\
		$(DSRC)run.c			\
		$(DSRC)my_sokoban.c		\
		$(DSRC)game_function.c	\
		$(DSRC)player.c			\
		$(DSRC)box.c			\
		$(DSRC)eval_game.c

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

.PHONY :        clean fclean re
