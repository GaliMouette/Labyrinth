/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct backup{
    int pos_x;
    int pos_y;
    struct backup *next;
} backup_t;

backup_t *create_element(backup_t *backup, int i, int j);

#endif