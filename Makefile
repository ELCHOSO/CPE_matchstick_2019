##
## EPITECH PROJECT, 2020
## matchstick
## File description:
## makefile
##

SRC	=	src/map.c	\
		src/print_functions.c	\
		src/my_atoi.c			\
		src/main.c	\
		src/remove_match.c	\
		src/invalid_value.c	\
		src/my.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include -Wall -Wextra

NAME	=	matchstick

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
