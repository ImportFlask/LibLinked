# LibLinked - Library for Singly Linked List Data Structure

LibLinked offers a straightforward implementation of singly linked lists in C, ideal for educational purposes or for integration into larger projects.

## Features

This library provides functions to perform various operations on a singly linked list, including:

1. Creating new nodes
2. Inserting nodes at the beginning, end, or a specific position
3. Removing nodes from the beginning or from a specific position
4. Retrieving nodes by their indexes
5. Counting the number of nodes in the linked list
6. Cleaning up the entire linked list

## Getting Started
1. Clone this repository: `git clone https://github.com/ImportFlask/LibLinked`
2. Navigate to the project directory: `cd LibLinked`
3. Compile the library: `make`
4. Install the library: `sudo make install`

Voila! Installation is complete.

## Usage

Using LibLinked is straightforward: include the library, declare the head reference and start managing your linked list.

```c
#include <linked_list.h>

int main() {
    // declare the head reference pointer
    LinkedList* top = NULL;

    // initialize the list structure via a function call
    linked_init(&top);
    
    // let's add 5 integers to the linked list as an example
    for (int i = 0; i < 5; i++) {
        int* val = malloc(sizeof(int)); // allocate memory for the data
        *val = i; // set the value

        Node* new_node = create_node(val); // create a node object
        add_node(top, new_node); // add the object to the list
    }

    // * other code goes here *

    // clean up the data contained in the nodes
    for (Node* tmp = top->node; tmp != NULL; tmp = tmp->next_object) {
        free(tmp->object);
    }

    // perform the final cleanup of the structure itself
    linked_deinit(&top);
    
    return 0;
}
```

To see how everything is placed in memory, you can print the memory addresses of the nodes in the linked list:

```c
void print_pointer_seq(LinkedList* top) {
    Node* current = top->node; // point to the first node
    while (current != NULL) {
        printf("%p -> ", current); // print out the memory address
        current = current->next_object; // take a step
    }
    printf("NULL\n"); // the end node always points to NULL
}
```