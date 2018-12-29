/**
Map header
Header that controls the game map
built on two structs {map_struct, node.h}
**/
#ifndef MAP_AH
#define MAP_AH
#include<stdbool.h>
#include "map_struct.h"
void visit(); // mark the node as visited to be seen in the view port
struct Node *node(); // node struct initialiser
// function that takes char paramter where the cell i am in and returns an int
// if 0 is returned , then i shall return to the last cell ,   2  means that the player won
// if 0 then the user choosed to move to the new cell

int my_case (char c, struct game_map *my_mab ); //
// returns the bool win which indicates the case of the player
bool is_win(struct game_map * my_mab);
//function that takes an array of chars converts it into an int and return the answer
int to_int(char * s);
// constructor for the game map struct
struct game_map Game_map ();
// load the map from the file and stores it in a linked list
void load_map(struct game_map * my_mab);
// function that prints the view port
void print_view(struct game_map * my_head);

///******************************************************************************************************************
        // moving functions , for up , down , left, right
void moveLeft(struct game_map *my_head);
void moveUp(struct game_map *my_head);
void moveRight(struct game_map * my_head);
void moveDown(struct game_map *my_head);


#endif // MAP_H



