#ifndef KLOVE_EXTEND_LIST
#define KLOVE_EXTEND_LIST

#include <stddef.h> 
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
struct list_arry {
    struct list_arry *next , *prev;
};
extern void list_add_arry(struct list_arry *new_list_node , struct list_arry* main_head);
extern void list_del_arry(struct list_arry *delet_node);
#ifdef __cplusplus
    }
#endif
#define new_list_arry(_arry__) \
    struct list_arry _arry__ = {&_arry__ , &_arry__}
#ifdef __cplusplus
    template<typename T, typename M>
        inline T* container_of(M* ptr, M T::*member) {
            return reinterpret_cast<T*>(reinterpret_cast<char*>(ptr) - 
            reinterpret_cast<char*>(&(static_cast<T*>(nullptr)->*member)));
        }
    #else
        #define container_of(ptr , type , member) ({\
            const typeof( ((type *)0)-> member) *__Mptr = (ptr);\
            (type *)( (char *)__Mptr - offsetof(type , member));\
        })
    #endif
#endif