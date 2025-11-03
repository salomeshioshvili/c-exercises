#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
} Data;

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

typedef void (*LinkedListOp)(Data*);

LinkedList* linked_list_create(void);
int linked_list_insert(LinkedList* list, Node* prev_node, Data data);
void linked_list_print(LinkedList* list);
int linked_list_delete(LinkedList* list, Node* target);
void linked_list_free(LinkedList** list);

void linked_list_traverse(LinkedList* list, LinkedListOp op);

int linked_list_sum(LinkedList* list);

#endif
