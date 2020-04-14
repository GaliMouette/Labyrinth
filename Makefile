##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

NAME = dante

all:	$(NAME)

$(NAME):
	$(MAKE)	-C	generator/
	$(MAKE)	-C	solver/

clean:
	$(MAKE)	clean	-C	generator/
	$(MAKE)	clean	-C	solver/

fclean:
	$(MAKE)	fclean	-C	generator/
	$(MAKE)	fclean	-C	solver/

re:	fclean	all

tests_run:
	$(MAKE)	tests_run	-C	generator/
	$(MAKE)	tests_run	-C	solver/

tests_clean:
	$(MAKE)	tests_clean	-C	generator/
	$(MAKE)	tests_clean	-C	solver/

.PHONY: all $(NAME) clean fclean re tests_run
