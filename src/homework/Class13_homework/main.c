#include "linked_list.h"
#include <stdio.h>

void print_value(Data* data) {
    printf("%d -> ", data->value);
}

void print_value_newline(Data* data) {
    printf("%d\n", data->value);
}

int main(void) {
    LinkedList* list = linked_list_create();
    
    Data data1 = {10};
    Data data2 = {5};
    Data data3 = {25};
    
    linked_list_insert(list, NULL, data1);
    linked_list_insert(list, list->head, data2);
    linked_list_insert(list, list->head, data3);
    
    printf("List: ");
    linked_list_print(list);
    
    printf("Using traverse to print: ");
    linked_list_traverse(list, print_value);
    printf("NULL\n");
    
    printf("Sum of all values: %d\n", linked_list_sum(list));
    
    linked_list_free(&list);
    printf("List freed successfully\n");
    
    return 0;
}
