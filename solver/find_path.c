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
        maze[path->pos_y][path->pos_x] = 'o';
        tmp = path;
        path = path->next;
        free(tmp);
    }
    for (int i = 0; i < size_y; i++)
        for (int j = 0; j < size_x; j++)
            if (' ' == maze[i][j])
                maze[i][j] = '*';
}

void find_path(char **maze, path_t **path, int size_y, int size_x)
{
    while ((*path) && ((*path)->pos_y < size_y && (*path)->pos_x < size_x)) {
        maze[(*path)->pos_y][(*path)->pos_x] = ' ';
        if ((*path)->pos_y == size_y - 1 && (*path)->pos_x == size_x - 1) return;
        if ((*path)->pos_y < size_y - 1 && maze[(*path)->pos_y + 1][(*path)->pos_x] == '*') {
            (*path) = add_element((*path), (*path)->pos_y + 1, (*path)->pos_x);
            continue;
        }
        if ((*path)->pos_x < size_x - 1 && maze[(*path)->pos_y][(*path)->pos_x + 1] == '*') {
            (*path) = add_element((*path), (*path)->pos_y, (*path)->pos_x + 1);
            continue;
        }
        if ((*path)->pos_y && maze[(*path)->pos_y - 1][(*path)->pos_x] == '*') {
            (*path) = add_element((*path), (*path)->pos_y - 1, (*path)->pos_x);
            continue;
        }
        if ((*path)->pos_x && maze[(*path)->pos_y][(*path)->pos_x - 1] == '*') {
            (*path) = add_element((*path), (*path)->pos_y, (*path)->pos_x - 1);
            continue;
        }
        (*path) = pop_element((*path));
    }
}