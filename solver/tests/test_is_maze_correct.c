/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** test_is_maze_correct.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_maze_correct(char **maze, int size_x, int size_y);
int get_maze(FILE *file, char ***maze, int *size_x, int *size_y);

Test(is_maze_correct, bad_Char_Maze)
{
    FILE *file = fopen("./tests/wrong_char_maze", "r");
    char **maze;
    int size_x, size_y;

    fseek(file, 0, SEEK_END);
    get_maze(file, &maze, &size_x, &size_y);
    cr_assert_eq(is_maze_correct(maze, size_x, size_y), 0);
    fclose(file);
}

Test(is_maze_correct, all_Is_OK)
{
    FILE *file = fopen("./tests/maze", "r");
    char **maze;
    int size_x, size_y;

    fseek(file, 0, SEEK_END);
    get_maze(file, &maze, &size_x, &size_y);
    cr_assert_eq(is_maze_correct(maze, size_x, size_y), 1);
    fclose(file);
}