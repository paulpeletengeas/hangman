##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A good Makefile
##

SRC		=	src/main.c					\
			src/get_words.c					\
			src/game.c					\
			src/word.c					\
			src/my_strcpy.c					\

NAME	=	hangman

CC	=	gcc

RM      =   rm -f

CFLAGS	=	-Wall 							\
		-Wextra							\
		-I include						\

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
