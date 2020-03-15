/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** maze_int.c
*/

#include "linked_list.h"

int alloc_int_maze(int ***maze_int, char **maze, int size_x, int size_y)
{
    *maze_int = malloc(sizeof(int *) * (size_y));
    if (!*maze_int)
        return 1;
    for (int i = 0; i < size_y; i++) {
        (*maze_int)[i] = malloc(sizeof(int) * (size_x));
        if (!(*maze_int)[i])
            return 1;
        for (int j = 0; j < size_x; j++)
            (*maze_int)[i][j] = -('X' == maze[i][j]);
    }
    return 0;
}

int multiple_paths(int **maze_int, int pos[2], int size[2])
{
    int paths = 0;

    paths += (pos[0]) ? !maze_int[pos[0] - 1][pos[1]] \
    || maze_int[pos[0]][pos[1]] + 1 < maze_int[pos[0] - 1][pos[1]] : 0;
    paths += (pos[1]) ? !maze_int[pos[0]][pos[1] - 1] \
    || maze_int[pos[0]][pos[1]] + 1 < maze_int[pos[0]][pos[1] - 1] : 0;
    paths += (pos[0] < size[0] - 1) ? !maze_int[pos[0] + 1][pos[1]] \
    || maze_int[pos[0]][pos[1]] + 1 < maze_int[pos[0] + 1][pos[1]] : 0;
    paths += (pos[1] < size[1] - 1) ? !maze_int[pos[0]][pos[1] + 1] \
    || maze_int[pos[0]][pos[1]] + 1 < maze_int[pos[0]][pos[1] + 1] : 0;
    return paths > 1;
}

void fill_int_maze_next(int ***maze_int, int size[2], int *i, int *j)
{
    if ((*j) < size[0] - 1 && (!(*maze_int)[(*i)][(*j) + 1]
    || (*maze_int)[(*i)][(*j)] + 1 < (*maze_int)[(*i)][(*j) + 1])) {
        (*maze_int)[(*i)][(*j) + 1] = (*maze_int)[(*i)][(*j)] + 1;
        (*j) = (*j) + 1;
        return;
    }
    if ((*i) < size[1] - 1 && (!(*maze_int)[(*i) + 1][(*j)]
    || (*maze_int)[(*i)][(*j)] + 1 < (*maze_int)[(*i) + 1][(*j)])) {
        (*maze_int)[(*i) + 1][(*j)] = (*maze_int)[(*i)][(*j)] + 1;
        (*i) = (*i) + 1;
        return;
    }
    if ((*j) && (!(*maze_int)[(*i)][(*j) - 1]
    || (*maze_int)[(*i)][(*j)] + 1 < (*maze_int)[(*i)][(*j) - 1])) {
        (*maze_int)[(*i)][(*j) - 1] = (*maze_int)[(*i)][(*j)] + 1;
        (*j) = (*j) - 1;
        return;
    }
}

int **fill_int_maze(int **maze_int, int size_y, int size_x)
{
    int i = 0;
    int j = 0;
    backup_t *backup = add_element(NULL, 0, 0);

    if (-1 == maze_int[i][j])
        return;
    maze_int[0][0] = 1;
    while (backup) {
        if (multiple_paths(maze_int, (int[2]){i, j}, (int[2]){size_y, size_x}))
            backup = add_element(backup, i, j);
        if (i && (!maze_int[i - 1][j]
        || maze_int[i][j] + 1 < maze_int[i - 1][j])) {
            maze_int[i - 1][j] = maze_int[i][j] + 1;
            i--;
            continue;
        }
        if (j < size_x - 1 && (!maze_int[i][j + 1]
        || maze_int[i][j] + 1 < maze_int[i][j + 1])) {
            maze_int[i][j + 1] = maze_int[i][j] + 1;
            j++;
            continue;
        }
        if (i < size_y - 1 && (!maze_int[i + 1][j]
        || maze_int[i][j] + 1 < maze_int[i + 1][j])) {
            maze_int[i + 1][j] = maze_int[i][j] + 1;
            i++;
            continue;
        }
        if (j && (!maze_int[i][j - 1]
        || maze_int[i][j] + 1 < maze_int[i][j - 1])) {
            maze_int[i][j - 1] = maze_int[i][j] + 1;
            j--;
            continue;
        }
        //fill_int_maze_next(&maze_int, (int[2]){size_x, size_y}, &i, &j);
        backup = pop_element(backup, &i, &j);
    }
    // for (int a = 0; a != size_y; a++) {
    //     for (int b = 0; b != size_x; b++)
    //         printf("%i ", maze_int[a][b]);
    //     printf("%s", "\n");
    // }
    return (maze_int);
}