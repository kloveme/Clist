cmake_minimum_required(VERSION 3.10)
project(ListProject C CXX)

if(WIN32)
    add_definitions(-D_WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

include_directories(include)

set(LIB_SOURCES
    lib/list_lib.c
)

add_library(clist SHARED ${LIB_SOURCES})
add_executable(my_list main.c)
target_link_libraries(my_list clist)

install(TARGETS clist
    RUNTIME DESTINATION bin  
    LIBRARY DESTINATION lib      
    ARCHIVE DESTINATION lib      
)

install(FILES include/list.h DESTINATION include)