##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

NAMEGEN	=	generator
NAMESOLV	=	solver

all: gen solv

gen:
	$(MAKE) -s -C ./generator/

solv:
	$(MAKE) -s -C ./solver/

clean:
	find -name "*.o" -delete

fclean: clean
	rm -fr ./generator/$(NAMEGEN) ./solver/$(NAMESOLV)

re: fclean all

.PHONY: all clean fclean re gen solv
