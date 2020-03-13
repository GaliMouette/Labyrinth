/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [SSH: 192.168.159.130]
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int parse_arguments(int argc, char const *argv[], FILE **file)
{
    if (2 != argc)
        return 1;
    *file = fopen(argv[1], "r");
    if (!*file)
        return 1;
    fseek(*file, 0, SEEK_END);
    return 0;
}

int get_maze(FILE *file, char ***maze, int *size_x, int *size_y)
{
    int file_len = ftell(file);
    char *file_content = malloc(sizeof(char) * (file_len + 1));

    if (!file_content)
        return 1;
    file_content[file_len] = 0;
    rewind(file);
    fread(file_content, file_len, 1, file);
    for (*size_x = 0; '\n' != file_content[*size_x]; (*size_x)++);
    (*size_y) = file_len / (*size_x);
    (*maze) = malloc(sizeof(char *) * (*size_y));
    if (!*maze)
        return 1;
    for (int i = 0; i < (*size_y); i++) {
        for (int j = 0; j < (*size_x); j++)
            if (!j)
                (*maze)[i] = file_content + (i * (*size_x + 1));
        (*maze)[i][(*size_x)] = 0;
    }
    return 0;
}

int is_maze_correct(char **maze, int size_x, int size_y)
{
    for (int i = 0; i < size_y; i++)
        for (int j = 0; j < size_x; j++)
            if ('*' != maze[i][j] && 'X' != maze[i][j])
                return 0;
    return 1;
}

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

void fill_int_maze(int **maze_int, int size_y, int size_x)
{
    int i = 0;
    int j = 0;
    backup_t backup;

    int tmp = 50;
    while (tmp--) {
        if (!i && !j)
            maze_int[i][j] = 0;
        if (i < size_y - 1 && (!maze_int[i + 1][j] || maze_int[i][j] + 1 < maze_int[i + 1][j])) {
            maze_int[i + 1][j] = maze_int[i][j] + 1;
            i++;
            continue;
        }
        if (j < size_x - 1 && (!maze_int[i][j + 1] || maze_int[i][j] + 1 < maze_int[i][j + 1])) {
            maze_int[i][j + 1] = maze_int[i][j] + 1;
            j++;
            continue;
        }
        if (i && (!maze_int[i - 1][j] || maze_int[i][j] + 1 < maze_int[i - 1][j])) {
            maze_int[i - 1][j] = maze_int[i][j] + 1;
            i--;
            continue;
        }
        if (j && (!maze_int[i][j - 1] || maze_int[i][j] + 1 < maze_int[i][j - 1])) {
            maze_int[i][j - 1] = maze_int[i][j] + 1;
            j--;
            continue;
        }
        create_element(&backup, i, j);
    }
}

int main(int argc, char const *argv[])
{
    FILE *file;
    char **maze;
    int **maze_int;
    int size_x, size_y;

    if (parse_arguments(argc, argv, &file))
        return 84;
    if (get_maze(file, &maze, &size_x, &size_y))
        return 84;
    fclose(file);
    if (!is_maze_correct(maze, size_x, size_y))
        return 84;
    if (alloc_int_maze(&maze_int, maze, size_x, size_y))
        return 84;
    fill_int_maze(maze_int, size_y, size_x);
    for (int i = 0; i < size_y; i++) {
        for(int j = 0; j < size_x; j++)
            printf("% d", maze_int[i][j]);
        printf("\n");
    }
    free(*maze);
    free(maze);
    return 0;
}
