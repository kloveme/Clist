#include "../include/list.h"
#include <string.h>

void list_add_arry(struct list_arry *new_list_node, struct list_arry *main_head) {
    new_list_node->next = main_head->next;
    new_list_node->prev = main_head;
    main_head->next->prev = new_list_node;
    main_head->next = new_list_node;
    return;
}

void list_del_arry(struct list_arry *delet_node) {
    delet_node->prev->next = delet_node->next;
    delet_node->next->prev = delet_node->prev;
    delet_node->next = NULL;
    delet_node->prev = NULL;
    return;
}
