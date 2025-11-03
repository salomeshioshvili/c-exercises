#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct {
    int value;
} Data;

typedef struct DNode {
    Data data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct {
    DNode* head;
    DNode* tail;
} DoublyLinkedList;

typedef void (*DoublyLinkedListOp)(Data*);

DoublyLinkedList* doubly_linked_list_create(void);
int doubly_linked_list_insert(DoublyLinkedList* list, DNode* prev_node, Data data);
void doubly_linked_list_print_forward(DoublyLinkedList* list);
void doubly_linked_list_print_backward(DoublyLinkedList* list);
int doubly_linked_list_delete(DoublyLinkedList* list, DNode* target);
void doubly_linked_list_free(DoublyLinkedList** list);

void doubly_linked_list_traverse(DoublyLinkedList* list, DoublyLinkedListOp op);
void doubly_linked_list_traverse_backward(DoublyLinkedList* list, DoublyLinkedListOp op);

int doubly_linked_list_sum(DoublyLinkedList* list);

#endif
