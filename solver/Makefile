##
## EPITECH PROJECT, 2020
## CPE_dante_2019 [SSH: 192.168.159.130]
## File description:
## Makefile
##

#CC	=	gcc

CFLAGS	=	-I ./include
CFLAGS	+=	-Wall -Wextra

OBJS	=	$(patsubst %.c,%.o,$(wildcard *.c))

all:	$(OBJS)

$(OBJS):	./include/linked_list.h
