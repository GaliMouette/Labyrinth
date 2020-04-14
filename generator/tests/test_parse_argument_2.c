/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** test_parse_argument_2.c
*/

#include <criterion/criterion.h>
#include "../include/settings.h"

int parse_arguments(int argc, char const *argv[], settings_t *settings);

Test(parse_arguments, size_y_Exist)
{
    int argc = 3;
    char const *argv[] = {"./generator", "10", "0"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 1);
}

Test(parse_arguments, evrithing_OK)
{
    int argc = 3;
    char const *argv[] = {"./generator", "10", "10"};
    settings_t settings;

    cr_assert_eq(parse_arguments(argc, argv, &settings), 0);
}