# Documentation

Hi! This is the first documentation I've ever written so sorry if I forget some details.


# Files

The LinkedList project has two main files and doesn't require any other library other than **<stdlib.h>** and **<stdio.h>** libraries that you should have if you're using C or C++.
1. node.h
2. linkedlist.h
Their implementations are available in the <i>node.c</i> and <i>linkedlist.c</i> files.

## Creating a new linked list

If you look at the <i>linkedlist.h</i> file, you'll notice that their is a **linked_list * new_linked_list(void)** function that create a new **linked_list** with malloc and returns a pointer of the new created list.

## Destroying the list

As the list is created using **malloc**, it's safer to destroy it when we don't need it anymore.
The **void free_list(linked_list \*)** is there to help. It also destroys all the nodes added in the list by looping through each one.

## Adding a new value to the end

To add a new value at the the end of the list, you can use the **void add(linked_list \*, int)** function that create a new <i>node</i> and pushes it to the last element of the list.

## Inserting a new value at a certain position
To insert a new value at a certain position, you can use the **void insert_at(linked_list\* l, const inst position, const int value)** function that loops till it finds the element at the position <i>position - 1</i> then update its <i>next</i> element with a new node with the value <i>value</i>.

## Removing an element

To remove an element from the list, you can use the **void remove_at(linked_list \* l, int position)** function that remove the element at the position specified.

## Example

    

`int main() {`

		linked_list * notes = new_linked_list(void);`

		add(notes, 4);
		add(notes, 10);

		// Printing the list
		print_list(notes);

		remove_at(notes, 1);
		// Destroying the list at the end
		free_list(notes);
		
		return 0;
}
