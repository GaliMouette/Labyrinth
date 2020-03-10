/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [SSH: 192.168.159.130]
** File description:
** main
*/

#include <stdio.h>

int parse_arguments(int argc, char const *argv[], FILE **file)
{
    if (2 != argc)
        return 1;
    *file = fopen(argv[1], "r");
    if (!*file)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    FILE *file;

    if (parse_arguments(argc, argv, &file))
        return 84;
    while (1);
    return 0;
}
