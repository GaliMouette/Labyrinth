##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

SRC =	main.c	\
		linked_list.c

OBJ =	$(SRC:.c=.o)

NAME =	solver

CFLAGS = -I./include

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re
