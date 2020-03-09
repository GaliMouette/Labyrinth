/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [SSH: 192.168.159.130]
** File description:
** main
*/

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "settings.h"

int parse_arguments(int argc, char const *argv[], settings_t *settings)
{
    if (3 == argc || 4 == argc) {
        for (int i = 0; argv[1][i]; i++)
            if (!isdigit(argv[1][i]))
                return 1;
        for (int i = 0; argv[2][i]; i++)
            if (!isdigit(argv[2][i]))
                return 1;
        if (4 == argc && strcmp(argv[3], "perfect"))
            return 1;
    } else
        return 1;
    settings->size_x = strtol(argv[1], NULL, 10);
    settings->size_y = strtol(argv[2], NULL, 10);
    if (!settings->size_x || !settings->size_y)
        return 1;
    settings->perfect = 4 == argc;
    return 0;
}

int alloc_maze(char ***maze, long size_x, long size_y)
{
    *maze = malloc(sizeof(char *) * (size_y + 1));
    if (!*maze)
        return 1;
    (*maze)[size_y] = NULL;
    for (int i = 0; i < size_y; i++) {
        (*maze)[i] = malloc(sizeof(char) * (size_x + 1));
        if (!(*maze)[i])
            return 1;
        (*maze)[i][size_x] = 0;
        for (int j = 0; j < size_x; j++)
            (*maze)[i][j] = 'X';
    }
    (*maze)[size_y - 1][size_x - 1] = '*';
    return 0;
}

void perfect_maze(char **maze, long size_x, long size_y)
{
    int random;

    for (int i = 0; i < size_y; i += 2) {
        for (int j = 0; j < size_x; j += 2) {
            maze[i][j] = '*';
            random = rand() % 2;
            if (0 == i || 0 == j)
                maze[(0 == i) ? i : i - 1][(0 == j) ? j : j - 1] = '*';
            else
                maze[(random) ? i : i - 1][(random) ? j - 1 : j] = '*';
        }
    }
    size_y--;
    size_x--;
    random = rand() % 2;
    maze[(random) ? size_y : size_y - 1][(random) ? size_x - 1 : size_x] = '*';
}

void imperfect_maze(char **maze, long size_x, long size_y)
{
    for (int i = 1; i < size_y; i += 2)
        for (int j = 0; j < size_x; j += 2)
            if ('X' == maze[i][j] && rand() % 2)
                maze[i][j] = '*';
}

int main(int argc, char const *argv[])
{
    settings_t settings;
    char **maze;

    srand(time(NULL));
    if (parse_arguments(argc, argv, &settings))
        return 84;
    if (alloc_maze(&maze, settings.size_x, settings.size_y))
        return 84;
    perfect_maze(maze, settings.size_x, settings.size_y);
    if (!settings.perfect)
        imperfect_maze(maze, settings.size_x, settings.size_y);
    for (int i = 0; i < settings.size_y; i++) {
        write(1, maze[i], settings.size_x);
        if (i != settings.size_y - 1)
            write(1, "\n", 1);
    }
    return 0;
}
