//
// Created by Hassane SOW on 02/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "node.h"

linked_list * new_linked_list(void) {
    linked_list * l = malloc(sizeof * l);
    l->head = NULL;
    l->length = 0;
    return l;
}

void add(linked_list * l, const int value) {
    node_t * node = malloc(sizeof * node), * current_node;

    node->next = NULL;
    node->value = value;

    if(l->head == NULL) {
        l->head = node;
    } else {
        current_node = l->head;
        while(current_node->next !=  NULL) current_node = current_node->next;
        current_node->next = node;
    }

    l->length++;
}

void insert_at(linked_list * l, const int index, const int value) {
    node_t * current_node = NULL, * new_node = NULL;

    new_node = malloc(sizeof * new_node);
    new_node->value = value;
    new_node->next = NULL;


    current_node = _get_node(l, index, 1);
    if(current_node == NULL) {
        if(index == 0) {
            new_node->next = l->head;
            l->head = new_node;
            l->length++;
        } else
            free(new_node);
        return;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
    l->length++;
}

void remove_at(linked_list * l, const int index) {
    node_t * current_node = NULL, * next_node = NULL;
    current_node = _get_node(l, index, 1);
    l->length--;

    if(current_node == NULL) {
        if(index == 0) {
            next_node = l->head->next;
            free(l->head);
            l->head = next_node;
        }
        return;
    }

    next_node = current_node->next->next;
    free(current_node->next);
    current_node->next = next_node;

}

node_t * _get_node(linked_list * l, int index, char previous) {
    node_t * current_node = l->head;
    /*
     * Si on veut récuperer l'élément à l'index [index-2],
     * ceci sera utile pour l'ajout d'un noeud ou pour la
     * suppréssion d'un noeud à un certain index.
     */
    if(previous == 1)
        index--;

    int i = 0;
    while(current_node->next != NULL && i < index) {
        current_node = current_node->next;
        i++;
    }
    if(i != index) current_node = NULL;
    return current_node;
}

int get(linked_list * l, int index) {
    node_t * node = NULL;
    node = _get_node(l, index, 0);

    if(node == NULL)
        return -1;
    return node->value;
}

int get_size(const linked_list * l) {
    return l->length;
}

void print_list(const linked_list * l) {
    node_t * current_node = l->head;
    while(current_node != NULL) {
        printf(" %d ", current_node->value);
        current_node = current_node->next;
    }
}

void free_list(linked_list * l) {
    node_t * current_node = l->head, * next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(l);
}