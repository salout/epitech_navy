##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task 01
##

SRCDIR	=	src/

SRC =   main.c \
		printf/*.c \
		get_map.c \
		my_getnbr.c \
		my_strdup.c	\
		file_parser.c \
		get_next_line.c \
		disp.c \
		comunication.c \
		connection.c \
		add_boat.c \
		in_game.c \
		get_input.c \
		win_condition.c

SRCS =  $(addprefix $(SRCDIR), $(SRC))

CFLAGS  +=  -I./include -W -Wextra

CC	=	gcc -g3 -o

NAME 	=  navy

all:	$(NAME)

LIB:	make -C lib/my

$(NAME):
	$(CC) $(NAME) $(SRCS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

auteur:
	echo $(USER) > auteur
