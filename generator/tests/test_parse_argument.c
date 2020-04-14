/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** test_parse_argument.c
*/

#include <criterion/criterion.h>
#include "../include/settings.h"

int parse_arguments(int argc, char const *argv[], settings_t *settings);

Test(parse_arguments, bad_Argc)
{
    int argc = 2;
    char const *argv[] = {"./generator", "10"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}

Test(parse_arguments, not_Digits_Second_Arg)
{
    int argc = 3;
    char const *argv[] = {"./generator", "10", "g"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}

Test(parse_arguments, not_Digits_First_Arg)
{
    int argc = 3;
    char const *argv[] = {"./generator", "g", "10"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}

Test(parse_arguments, not_Perfect_In_Arg)
{
    int argc = 4;
    char const *argv[] = {"./generator", "10", "10", "test"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}

Test(parse_arguments, size_x_Exist)
{
    int argc = 3;
    char const *argv[] = {"./generator", "0", "10"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}