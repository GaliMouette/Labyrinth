##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

CC	=	gcc

all: gen solv

gen:
	$(MAKE) -C ./generator/ -o generator
	$(CC) -o ./generator/generator $(patsubst %.c, %.o, $(wildcard ./generator/*.c))

solv:
	$(MAKE) -C ./solver/ -o solver
	$(CC) -o ./solver/solver $(patsubst %.c, %.o, $(wildcard ./solver/*.c))

clean:
	find -name "*.o" -delete

fclean: clean
	rm -fr ./generator/generator ./solver/solver

re: fclean all

.PHONY: all clean fclean re gen solv
