##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

NAME	=	solver

TESTS_NAME	=	unit_tests

CC	=	gcc

RM	=	rm	-f

SRCS	=	./check_arg_and_display.c	\
			./find_path.c				\
			./linked_list.c				\
			./main.c

TESTS_SRCS	=	./check_arg_and_display.c		\
				./find_path.c					\
				./linked_list.c					\
				./tests/test_get_maze.c			\
				./tests/test_is_maze_correct.c	\
				./tests/test_parse_arguments.c

OBJS	=	$(SRCS:.c=.o)

TESTS_OBJS	=	$(TESTS_SRCS:.c=.o)

CFLAGS	=	-I	./include/
CFLAGS	+=	-g3
CFLAGS	+=	-Wall	-Wextra

LDFLAGS	=

ifeq ($(MAKECMDGOALS),	tests_run)
CFLAGS	+=	--coverage
LDFLAGS	+=	-lcriterion
endif

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC)	$(OBJS)	-o	$(NAME)	$(LDFLAGS)

tests_run:	$(TESTS_OBJS)
	$(CC)	$(TESTS_OBJS)	-o	$(TESTS_NAME)	$(LDFLAGS)	$(CFLAGS)
	./$(TESTS_NAME)

tests_clean:
	$(RM)	$(TESTS_NAME)
	$(RM)	$(TESTS_OBJS)
	$(RM)	$(wildcard	*.gc*)	$(wildcard	*/*.gc*)

clean:	tests_clean
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	all

.PHONY:	all	tests_run	tests_clean	clean	fclean	re
