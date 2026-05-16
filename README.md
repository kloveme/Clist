# Clist
An intrusive list implementation for learning cross-compilation and studying the Linux kernel
## Introducion
Supports development on GNU/LINUX and Win32, mainly addressing array issues in C and supporting C/C++ development. Later, if this project attracts attention, I will add array deletion methods and use Pybind11 to accelerate moving arrays for Python
## Salute
This project mainly imitates the implementation scheme of C arrays in UNIX/LINUX systems. Thanks to the open source code of predecessors for learning 

## Usage plan C/C++ General
``` c
#include "list.h"
#include <cstdio>
#include <string>

int main () {
    struct list_arry new_arry = {&new_arry , &new_arry}; //Create an array structure

    //Create your array content structure
    struct data { 
        std::string name;
        int age;
        list_arry list_head;
    };

    //Put in your data, make sure the space before and after the initial hook is empty, otherwise it will cause garbage values and program crashes
    data newd {.name = "JUSTIN" , .age = 12 , .list_head = {nullptr , nullptr}};
     //Add the array structure to your main list
    list_add_arry(&newd.list_head, &new_arry);
    
    struct list_arry *cur = new_arry.next;
    /** 
    Traverse your list. If 'cur = new_arry.next' is not equal to the start of the main list, it proves
    that the data has not been
    fully traversed, so this loop condition is set
    because the list is a closed loop. The following structure proves it:
      
      d <- a <-> b <-> c <-> d -> a

      In a doubly linked list, each node has two pointers, one pointing to the previous
        node and onepointing to the next node. The
        next pointer of the last node points to the head node, forming a closed loop.

      So if '.next' = start 'a', it backtracks to the starting point, thereby ending the list traversal.
    */
    while (cur != &new_arry) {
        struct data *p = container_of(cur, struct my_data, list_head);
        /**
            C: struct my_data *p = container_of(cur, struct my_data, list_head);
            C++: struct data *p = container_of(cur, &data::list_head);
        */
        printf("%s|%d\n" , p->name.c_str() , p->age);
        /** 
        Updating .next is the next linked list structure  
          a.next = b!  
          b != a (start)  
          b.next = c  
          c.next = b then ends  
          
          If not updated, it will end directly because  
          a.next = a (start)  
          will immediately end the traversal!
        */
        cur = cur->next;
    }
    return 0;
}
```
