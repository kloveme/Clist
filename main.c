#include "include/list.h"
#include <stdio.h>

int main () {
    struct list_arry my_list = {&my_list , &my_list};

    struct my_data {
        char name[20];
        int age;
        struct list_arry list_head;
    };

    struct my_data md1 = {"Jack" , 20 , .list_head.next = md1.list_head.prev = NULL};
    list_add_arry(&md1.list_head, &my_list);

    struct my_data md2 = {"Justin" , 25 , .list_head.next = md1.list_head.prev = NULL};
    list_add_arry(&md2.list_head , &my_list);

    struct list_arry *cur = my_list.next;
    int x = 0;
    while (cur != &my_list) {
        x += 1;
        struct my_data *p = container_of(cur, struct my_data, list_head);
        printf("ITEM: %d; NAME:%s  ; AGE:%d ;\n" , x , p->name , p->age);
        cur = cur->next;
    }    
}