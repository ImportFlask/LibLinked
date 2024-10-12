#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>
#include <stdlib.h>

#include "linked_defs.h"

/**
 * @brief Represents a node in a singly linked list.
 *
 * @param object pointer to the data stored in the node
 * @param next_object pointer to the next node in the list
 */
typedef struct Node {
    void* object;
    struct Node* next_object;
} Node;

/**
 * @brief Represents the main object of the linked list
 *
 * @param node pointer to the first node in the list
 * @param n_count the amount of nodes in the list
 */
typedef struct LinkedList {
    unsigned n_count;
    struct Node* node;
} LinkedList;

/**
 * @brief Initializes the given linked list object
 * 
 * @param list double pointer to the head structure
 * 
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 * @retval `LL_FAIL_ALLOC` [5] - failed to allocate memory for the object
 * @note if an already initialized object is passed, this will result in a data loss
 */
uint8_t linked_init(LinkedList** list);

/**
 * @brief Deinitializes the given linked list object
 * 
 * @param list double pointer to the head structure
 * 
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 * @note this function will remove all the nodes and render the given object `NULL`
 */
uint8_t linked_deinit(LinkedList** list);

/**
 * @brief Wipes all the nodes in the given head struct.
 * 
 * @param top pointer to the LinkedList object
 * 
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 */
uint8_t wipe_nodes(LinkedList* top);

/**
 * @brief Counts the number of active nodes in the list.
 * 
 * @param top pointer to the head struct
 */
void recount_nodes(LinkedList* top);

/**
 * @brief Creates a new node object
 * 
 * @param object the pointer to the object which will reside in the node
 * @returns a pointer to the newly created node or `NULL`
 * @note the user is responsible for freeing the inner object
*/
Node* create_node(void* object);

/**
 * @brief Adds a node to the end of a linked list
 * 
 * @param top pointer to the head struct
 * @param object pointer to the object
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
*/
uint8_t add_node(LinkedList* top, Node* object);

/**
 * @brief Adds a node to the beginning of a linked list
 * 
 * @param top pointer to the head struct
 * @param object pointer to the object
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head struct is invalid
*/
uint8_t add_node_beg(LinkedList* top, Node* object);

/**
 * @brief Removes a node by the given position
 * 
 * @param top pointer to the head structure
 * @param pos position index
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 * @retval `LL_NEN_NODES` [2] - not enough nodes for this action
 * @retval `LL_BAD_INDEX` [3] - index is out of bounds
*/
uint8_t remove_node(LinkedList* top, unsigned int pos);

/**
 * @brief Removes a node at the beginning of a linked list
 * 
 * @param top pointer to the head structure
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 * @retval `LL_NEN_NODES` [2] - not enough nodes for this action
*/
uint8_t remove_node_beg(LinkedList* top);

/**
 * @brief Inserts a node into the given position
 * 
 * @param top pointer to the head structure
 * @param object pointer to the object which will be inserted
 * @param pos position index
 * @returns an integer
 * @retval `LL_OK` [0] - OK
 * @retval `LL_BAD_STRUCT` [1] - the head structure is invalid
 * @retval `LL_NEN_NODES` [2] - not enough nodes for this action
*/
uint8_t insert_node(LinkedList* top, Node* object, unsigned int pos);

/**
 * @brief Fetches a node at a specific index
 * 
 * @param top pointer to the head structure
 * @param pos position index
 * @returns `Node` pointer or `NULL`
 */
Node* get_node_at(LinkedList* top, int pos);

#endif // LINKEDLIST_H
