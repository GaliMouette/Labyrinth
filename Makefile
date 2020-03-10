##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

CC	= gcc

all: gen solv

gen:
	$(MAKE) -C ./generator/
	$(CC) -o ./generator/generator ./generator/main.o

solv:
	$(MAKE) -C ./solver/
	$(CC) -o ./solver/solver ./solver/main.o

clean:
	find -name "*.o" -delete

fclean: clean
	rm -fr ./generator/generator ./solver/solver

re: fclean all

.PHONY: all clean fclean re gen
