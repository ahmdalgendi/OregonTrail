#ifndef NODE_H
#define NODE_H
#include<stdbool.h>

typedef struct Node{
    enum Threat {DISEASE_WEATHER, ANIMAL}threat;

    bool discoverd  ; //A Boolean value as to whether or not the node has been discovered
    int x ; //x location in the map
    int y ;// y location in the map
    char data;
   struct Node *r, *l , *u, *d;
} node_type;
#endif // NODE_H
