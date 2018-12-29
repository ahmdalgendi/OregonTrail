#ifndef MAP_STRUCT
#define MAP_STRUCT
#include "node.h"
#include<stdbool.h>

struct game_map{
        int map_size, view_port,food;
        bool win_;
        struct  Node *head ;

};

#endif // MAP_STRUCT
