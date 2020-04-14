/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** test_get_maze.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int get_maze(FILE *file, char ***maze, int *size_x, int *size_y);

Test(get_maze, all_Is_OK)
{
    FILE *file = fopen("./tests/maze", "r");
    char **maze;
    int size_x, size_y;
    
    fseek(file, 0, SEEK_END);
    cr_assert_eq(get_maze(file, &maze, &size_x, &size_y), 0);
    fclose(file);
}