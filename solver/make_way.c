/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** make_way.c
*/

#include "linked_list.h"

void display_maze(char **maze, int size_y, int size_x)
{
    for (int a = 0; a != size_y; a++) {
        for (int b = 0; b != size_x; b++)
            printf("%c", maze[a][b]);
        printf("%s", "\n");
    }
}

int make_way(char **maze, int **maze_int, int size_y, int size_x)
{
    int j = size_y - 1;
    int i = size_x - 1;

    if (maze_int[j][i] == 0 || maze_int[j][i] == -1)
        return 1;
    maze[j][i] = 'o';
    while (i || j) {
        if (i && (maze_int[j][i - 1] == (maze_int[j][i] - 1))) {
            i--;
            maze[j][i] = 'o';
        }
        if (j && (maze_int[j - 1][i] == (maze_int[j][i] - 1))) {
            j--;
            maze[j][i] = 'o';
        }
        if (i && (maze_int[j][i + 1] == (maze_int[j][i] - 1))) {
            i++;
            maze[j][i] = 'o';
        }
        if (j && (maze_int[j + 1][i] == (maze_int[j][i] - 1))) {
            j++;
            maze[j][i] = 'o';
        }
    }
    display_maze(maze, size_y, size_x);
    return 0;
}