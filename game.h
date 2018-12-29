/**
Game header
header file that controls movements
and have functions to print the game messages

**/

#ifndef game_header
#define game_header
void instructions (); // function  that prints the game instructions
void splash(); // function to print the splash screen
void win(); //function  to print win message
void lose (); // function to print lose messsage
///**********************************///
// function that takes 2 parameters , the game map and the move direction
// u, d , l , r
// function for moving , takes map , and a char
// and returns an int
// if 1 is returned, then game is still on ,
// 0 is returned game over and player lost
// 2 is returned game over and player won
// -1 is returned , INVALID INPUT
int game_move(struct game_map * my_map , char my_move);

#endif // game_header
