/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** linked_list.c
*/

#include "linked_list.h"
#include <stdlib.h>

path_t *add_element(path_t *path, int y, int x)
{
    path_t *elem = malloc(sizeof(path_t));

    elem->pos_y = y;
    elem->pos_x = x;
    elem->next = path;
    return elem;
}

path_t *pop_element(path_t *path)
{
    path_t *tmp = path;

    path = path->next;
    free(tmp);
    return path;
}
