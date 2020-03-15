/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** linked_list.c
*/

#include "linked_list.h"
#include <stdlib.h>

backup_t *add_element(backup_t *backup, int i, int j)
{
    backup_t *elem = malloc(sizeof(backup_t));

    elem->pos_y = i;
    elem->pos_x = j;
    elem->next = backup;
    return elem;
}

backup_t *pop_element(backup_t *backup, int *i, int *j)
{
    backup_t *tmp = backup;

    *i = backup->pos_y;
    *j = backup->pos_x;
    backup = backup->next;
    free(tmp);
    return backup;
}
