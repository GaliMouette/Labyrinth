/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** make_way.c
*/

#include "linked_list.h"

void display_maze(char **maze, int size_y, int size_x)
{
    for (int a = 0; a < size_y; a++) {
        write(1, maze[a], size_x);
        if (a != size_y - 1)
            write(1, "\n", 1);
    }
}

void replace_char(char **maze, path_t *path, int size_y, int size_x)
{
    path_t *tmp;

    while (path) {
        maze[path->y][path->x] = 'o';
        tmp = path;
        path = path->next;
        free(tmp);
    }
    for (int i = 0; i < size_y; i++)
        for (int j = 0; j < size_x; j++)
            if (' ' == maze[i][j])
                maze[i][j] = '*';
}

void find_path(char **maze, path_t **path, int y, int x)
{
    while ((*path) && ((*path)->y < y && (*path)->x < x)) {
        maze[(*path)->y][(*path)->x] = ' ';
        if ((*path)->y == y - 1 && (*path)->x == x - 1) return;
        if ((*path)->y < y - 1 && maze[(*path)->y + 1][(*path)->x] == '*') {
            (*path) = add_element((*path), (*path)->y + 1, (*path)->x);
            continue;
        }
        if ((*path)->x < x - 1 && maze[(*path)->y][(*path)->x + 1] == '*') {
            (*path) = add_element((*path), (*path)->y, (*path)->x + 1);
            continue;
        }
        if ((*path)->y && maze[(*path)->y - 1][(*path)->x] == '*') {
            (*path) = add_element((*path), (*path)->y - 1, (*path)->x);
            continue;
        }
        if ((*path)->x && maze[(*path)->y][(*path)->x - 1] == '*') {
            (*path) = add_element((*path), (*path)->y, (*path)->x - 1);
            continue;
        }
        (*path) = pop_element((*path));
    }
}
