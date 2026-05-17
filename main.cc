#include "include/list.h"
#include "list.h"
#include <cstdio>
#include <string>

int main () {
    list_arry new_arry = {&new_arry , &new_arry};
    struct data {
        std::string name;
        int age;
        list_arry list_head;
    };
    data newd {.name = "JUSTIN" , .age = 12 , .list_head = {nullptr , nullptr}};
    list_add_arry(&newd.list_head, &new_arry);
    
    struct list_arry *cur = new_arry.next;
    while (cur != &new_arry) {
        struct data *p = container_of(cur, &data::list_head);
        printf("%s|%d\n" , p->name.c_str() , p->age);
        cur = cur->next;
    }

    return 0;
}