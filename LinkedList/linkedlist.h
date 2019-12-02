//
// Created by Utilisateur on 02/12/2019.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "node.h"

typedef struct {
    int length;
    node_t * head;
} linked_list;

linked_list * new_linked_list(void);

void free_list(linked_list *);

int get_size(const linked_list *);

node_t * _get_node(linked_list *, int, char);

int get(linked_list *, int);

void add(linked_list *, const int);

void insert_at(linked_list * , const int, const int);

void remove_at(linked_list *, const int);

void print_list(const linked_list *);


#endif //LINKEDLIST_LINKEDLIST_H
