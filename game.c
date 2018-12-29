#include <stdio.h>
#include<stdlib.h>
#include "map.h"
#include "map_struct.h"
#include "node.h"
void instructions ()
{
    puts( "----------GAME INSTRUCTIONS-----------\n");
    puts( "You will begin at the bottom right of an NxN grid. \nAttempt to traverse to the top right without losing your entire food stockpile\n\n\n");

}
void splash(){

        FILE * fb= fopen("splash.txt",  "r");
        char x ;
        while(1)
        {
            x = fgetc(fb);
            if(feof(fb))
                break;
            printf("%c", x);
        }
       puts("\n \n \n \n \n \n");
}
void win()
{
     FILE * fb= fopen("win.txt",  "r");
        char x ;
        while(1)
        {
            x= fgetc(fb);
            if(feof(fb))
                break;
            printf("%c", x);
        }
        puts("\n\n\n\n");
}
void lose ()
{
        FILE * fb= fopen("lose.txt",  "r");
        char x ;
        while(1)
        {
            x= fgetc(fb);
            if(feof(fb))
                break;
            printf("%c", x);
        }
        puts("\n\n\n\n");
}

int game_move(struct game_map * my_map , char my_move) // function for moving , takes map , and a char
{                                                 // and returns an int
    if(my_move == 'U')                             // if 1 is returned, then game is still on ,
    {                                               // 0 is returned game over and player lost
        moveUp(my_map);                              // 2 is returned game over and player won
        if(my_map->win_)                           // -1 is returned , INVALID INPUT
            return 2 ;
        if(my_map-> food<=0)
            return 0;
        return 1;
    }
    else if(my_move== 'D')
    {
      moveDown(my_map);
        if(my_map->win_)
            return 2;

        if(my_map->food<=0)
            return 0;
        return 1;
    }
    else if(my_move== 'L')
    {
        moveLeft(my_map);
        if(my_map->win_)
            return 2;

        if(my_map->food<=0)
            return 0;
        return 1;
    }
    else if(my_move== 'R')
    {
        moveRight(my_map);
        if(my_map->win_)
            return 2;
        if(my_map->food<=0)
            return 0;

        return 1;
    }
    else return -1 ;
}
