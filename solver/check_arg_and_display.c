/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** check_arg_and_display.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/linked_list.h"

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

void display_solution(char **maze, int size_y, int size_x)
{
    if ('o' == maze[size_y - 1][size_x - 1])
        display_maze(maze, size_y, size_x);
    else
        write(1, "no solution found", 17);
}

int main_solveur(int argc, char const *argv[])
{
    FILE *file;
    char **maze;
    int size_x, size_y;
    path_t *path = add_element(NULL, 0, 0);

    if (parse_arguments(argc, argv, &file))
        return 84;
    if (get_maze(file, &maze, &size_x, &size_y))
        return 84;
    fclose(file);
    if (!is_maze_correct(maze, size_x, size_y))
        return 84;
    if ('*' == maze[0][0])
        find_path(maze, &path, size_y, size_x);
    replace_char(maze, path, size_y, size_x);
    display_solution(maze, size_y, size_x);
    free(*maze);
    free(maze);
    return 0;
}