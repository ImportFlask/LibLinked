#include "linked_list.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t linked_init(LinkedList** list) {
    if (list == NULL)
        return LL_BAD_STRUCT;

    if (*list == NULL) {
        *list = (LinkedList*) malloc(sizeof(LinkedList));
        if (*list == NULL)
            return LL_FAIL_ALLOC;
    }
    (*list)->n_count = 0;
    (*list)->node = NULL;
    return LL_OK;
}

uint8_t linked_deinit(LinkedList** list) {
    if (list == NULL || *list == NULL)
        return LL_BAD_STRUCT;
    
    if ((*list)->n_count > 0)
        wipe_nodes(*list);
    
    free(*list);
    (*list) = NULL;
    return LL_OK;
}

uint8_t wipe_nodes(LinkedList* top) {
    if (top == NULL) 
        return LL_BAD_STRUCT;
    
    if (top->n_count == 0)
        return LL_NEN_NODES;

    Node* tmp = NULL;
    Node* current = top->node;
    while (current != NULL) {
        tmp = current;
        current = current->next_object;
        free(tmp);
    }
    top->node = NULL;
    top->n_count = 0;
    return LL_OK;
}

void recount_nodes(LinkedList* top) {
    unsigned nodes = 0;
    Node* initial = top->node;
    while (initial != NULL) {
        initial = initial->next_object;
        nodes++;
    }
    top->n_count = nodes;
}

Node* create_node(void* object) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL)
        return NULL;

    new_node->object = object;
    new_node->next_object = NULL;
    return new_node;
}

uint8_t add_node(LinkedList* top, Node* object) {
    if (top == NULL)
        return LL_BAD_STRUCT;
    
    if (object == NULL) 
        return LL_BAD_NODE;

    if (top->node == NULL) {
        top->node = object;
        top->n_count++;
        return LL_OK;
    }

    Node* tmp = top->node;
    while (tmp->next_object != NULL)
        tmp = tmp->next_object;
    
    tmp->next_object = object;
    top->n_count++;
    return LL_OK;
}

uint8_t add_node_beg(LinkedList* top, Node* object) {
    if (top == NULL)
        return LL_BAD_STRUCT;
    
    if (object == NULL)
        return LL_BAD_NODE;

    if (top->node == NULL) {
        top->node->object = object;
        top->n_count++;
        return LL_OK;
    }

    object->next_object = top->node;
    top->node = object;
    top->n_count++;
    return LL_OK;
}

uint8_t remove_node(LinkedList* top, unsigned int pos) {
    if (top == NULL)
        return LL_BAD_STRUCT;

    if (top->n_count < pos)
        return LL_BAD_INDEX;

    if (pos == 0)
        return remove_node_beg(top);

    Node* tmp = top->node;
    for (int n = 0; n < pos-1; n++) {
        tmp = tmp->next_object;
    }

    Node* rem = tmp->next_object;
    tmp->next_object = rem->next_object;
    top->n_count--;
    free(rem);
    return LL_OK;
}

uint8_t remove_node_beg(LinkedList* top) {
    if (top == NULL)
        return LL_BAD_STRUCT;

    if (top->n_count == 0)
        return LL_NEN_NODES;

    Node* tmp = top->node;
    top->node = top->node->next_object;
    top->n_count--;
    free(tmp);
    return LL_OK;
}

uint8_t insert_node(LinkedList* top, Node* object, unsigned int pos) {
    if (top == NULL)
        return LL_BAD_STRUCT;

    if (object == NULL)
        return LL_BAD_NODE;
    
    if (top->n_count < pos)
        return LL_BAD_INDEX;

    if (pos == 0)
        return add_node_beg(top, object);

    unsigned index = 0;
    Node* current = top->node;
    Node* previous = NULL;
    while (current != NULL) {
        if (index == pos) {
            previous->next_object = object;
            object->next_object = current;
            top->n_count++;
            break;
        }
        previous = current;
        current = current->next_object;
        index++;
    }
    return LL_OK;
}

Node* get_node_at(LinkedList* top, int pos) {
    if (top == NULL || top->n_count < pos)
        return NULL;

    int index = 0;
    Node* tmp = top->node;
    while (tmp != NULL) {
        if (index == pos)
            return tmp;
        tmp = tmp->next_object;
        index++;
    }

    return NULL;
}

#ifdef __cplusplus
}
#endif