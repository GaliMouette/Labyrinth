/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** linked_list.c
*/
#include "linked_list.h"
#include "stdlib.h"

backup_t *create_element(backup_t *backup, int i, int j)
{
    backup_t *elem = malloc(sizeof(backup_t));

    elem->pos_x = i;
    elem->pos_y = j;
    elem->next = backup;
    return elem;
}
