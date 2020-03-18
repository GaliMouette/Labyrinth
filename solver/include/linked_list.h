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

typedef struct backup{
    int pos_x;
    int pos_y;
    struct backup *next;
} backup_t;

//file / linked_list.c
backup_t *add_element(backup_t *backup, int i, int j);
backup_t *pop_element(backup_t *backup, int *i, int *j);

//file / make_way.c
void display_maze(char **maze, int size_y, int size_x);
char **make_way_next(char **maze, int **maze_int, int *i, int *j);
int make_way(char **maze, int **maze_int, int size_y, int size_x);

//file / maze_int.c
int alloc_int_maze(int ***maze_int, char **maze, int size_x, int size_y);
int multiple_paths(int **maze_int, int pos[2], int size[2]);
int fill_int_maze_next(int **maze_int, int size[2], int *i, int *j);
void fill_int_maze(int **maze_int, int size_y, int size_x);

#endif
