/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** test_parse_arguments.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int parse_arguments(int argc, char const *argv[], FILE **file);

Test(parse_arguments, bad_Nbr_Arg)
{
    int argc = 3;
    char const *argv[] = {"./solver", "maze", "oui"};
    FILE *file;

    cr_assert_eq(parse_arguments(argc, argv, &file), 1);
}

Test(parse_arguments, bad_file)
{
    int argc = 2;
    char const *argv[] = {"./solver", "test"};
    FILE *file;

    cr_assert_eq(parse_arguments(argc, argv, &file), 1);
}

Test(parse_arguments, all_Test_Good)
{
    int argc = 2;
    char const *argv[] = {"./solver", "./tests/maze"};
    FILE *file;

    cr_assert_eq(parse_arguments(argc, argv, &file), 0);
}