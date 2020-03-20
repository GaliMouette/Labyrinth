/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct path{
    int pos_x;
    int pos_y;
    struct path *next;
} path_t;

//file / linked_list.c
path_t *add_element(path_t *path, int y, int x);
path_t *pop_element(path_t *path);

//file / make_way.c
void display_maze(char **maze, int size_y, int size_x);
void find_path(char **maze, path_t **path, int size_y, int size_x);

#endif
