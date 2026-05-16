#include "../include/list.h"

void list_add_arry(struct list_arry *new_list_node, struct list_arry *main_head) {
    new_list_node->next = main_head->next;
    new_list_node->prev = main_head;
    main_head->next->prev = new_list_node;
    main_head->next = new_list_node;
    return;
}