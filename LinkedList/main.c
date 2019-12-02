#include <stdio.h>

#include "linkedlist.h"

int main() {
    linked_list * notes = new_linked_list();

    add(notes, 4);
    add(notes, 5);
    add(notes, 10);
    add(notes, 100);

    // Taille de la liste.
    printf("Size of the list: %d\n", get_size(notes));

    // Choix de l'élément à la position donnée.
    printf("Element 2 must be equal to 10 & we find: %d\n", get(notes, 2));
    printf("Element 3 must be equal to 100 & we find: %d\n", get(notes, 3));
    printf("Element 4 doit must be equal to -1 & we find: %d\n", get(notes, 4));
    print_list(notes); puts("");

    insert_at(notes, 0, 35);
    insert_at(notes, 2, 40);
    insert_at(notes, 6, 87);
    insert_at(notes, 10, 35);
    printf("Size of the list: %d\n", get_size(notes));
    printf("Element 2 must be equal to 40 & we find: %d\n", get(notes, 2));

    print_list(notes); puts("");
    remove_at(notes, 5);
    print_list(notes);

    free_list(notes);
    return 0;
}
