#include "doubly_linked_list.h"
#include <stdio.h>

DoublyLinkedList* doubly_linked_list_create(void) {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int doubly_linked_list_insert(DoublyLinkedList* list, DNode* prev_node, Data data) {
    if (!list) {
        return -1;
    }
    
    DNode* new_node = (DNode*)malloc(sizeof(DNode));
    if (!new_node) {
        return -1;
    }
    
    new_node->data = data;
    
    if (!prev_node) {
        // Insert at head
        new_node->prev = NULL;
        new_node->next = list->head;
        if (list->head) {
            list->head->prev = new_node;
        } else {
            list->tail = new_node;
        }
        list->head = new_node;
    } else {
        // Insert after prev_node
        new_node->prev = prev_node;
        new_node->next = prev_node->next;
        if (prev_node->next) {
            prev_node->next->prev = new_node;
        } else {
            list->tail = new_node;
        }
        prev_node->next = new_node;
    }
    
    return 0;
}

void doubly_linked_list_print_forward(DoublyLinkedList* list) {
    if (!list) {
        printf("NULL\n");
        return;
    }
    
    DNode* current = list->head;
    while (current) {
        printf("%d <-> ", current->data.value);
        current = current->next;
    }
    printf("NULL\n");
}

void doubly_linked_list_print_backward(DoublyLinkedList* list) {
    if (!list) {
        printf("NULL\n");
        return;
    }
    
    DNode* current = list->tail;
    while (current) {
        printf("%d <-> ", current->data.value);
        current = current->prev;
    }
    printf("NULL\n");
}

int doubly_linked_list_delete(DoublyLinkedList* list, DNode* target) {
    if (!list || !target) {
        return -1;
    }
    
    if (target->prev) {
        target->prev->next = target->next;
    } else {
        list->head = target->next;
    }
    
    if (target->next) {
        target->next->prev = target->prev;
    } else {
        list->tail = target->prev;
    }
    
    free(target);
    return 0;
}

void doubly_linked_list_free(DoublyLinkedList** list) {
    if (!list || !*list) {
        return;
    }
    
    DNode* current = (*list)->head;
    while (current) {
        DNode* next = current->next;
        free(current);
        current = next;
    }
    
    free(*list);
    *list = NULL;
}

void doubly_linked_list_traverse(DoublyLinkedList* list, DoublyLinkedListOp op) {
    if (!list || !op) {
        return;
    }
    
    DNode* current = list->head;
    while (current) {
        op(&current->data);
        current = current->next;
    }
}

void doubly_linked_list_traverse_backward(DoublyLinkedList* list, DoublyLinkedListOp op) {
    if (!list || !op) {
        return;
    }
    
    DNode* current = list->tail;
    while (current) {
        op(&current->data);
        current = current->prev;
    }
}

int doubly_linked_list_sum(DoublyLinkedList* list) {
    if (!list) {
        return 0;
    }
    
    int sum = 0;
    DNode* current = list->head;
    while (current) {
        sum += current->data.value;
        current = current->next;
    }
    
    return sum;
}
