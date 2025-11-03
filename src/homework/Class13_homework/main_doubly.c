#include "doubly_linked_list.h"
#include <stdio.h>

void print_value(Data* data) {
    printf("%d <-> ", data->value);
}

int main(void) {
    DoublyLinkedList* list = doubly_linked_list_create();
    
    Data data1 = {5};
    Data data2 = {10};
    Data data3 = {25};

    doubly_linked_list_insert(list, NULL, data1);
    doubly_linked_list_insert(list, list->head, data2);
    doubly_linked_list_insert(list, list->head, data3);
    
    printf("Forward traversal: ");
    doubly_linked_list_print_forward(list);
    
    printf("Backward traversal: ");
    doubly_linked_list_print_backward(list);
    
    printf("Using traverse (forward): ");
    doubly_linked_list_traverse(list, print_value);
    printf("NULL\n");
    
    printf("Using traverse (backward): ");
    doubly_linked_list_traverse_backward(list, print_value);
    printf("NULL\n");
    
    printf("Sum of all values: %d\n", doubly_linked_list_sum(list));
    
    doubly_linked_list_free(&list);
    printf("List freed successfully\n");
    
    return 0;
}
