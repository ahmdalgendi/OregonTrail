#include <stdio.h>
#include<stdlib.h>
#include "map.h"
#include "game.h"
#include "map_struct.h"
#include "node.h"

char in;
int main()
{
    char  _move;
    struct   game_map my_map = Game_map();


    //printf("head********* %c\n\n", my_map.head->l-> data);
   while(1)//main game loop
   {
       load_map(&my_map);
        my_map.win_ = 0;
       splash();
       scanf(" %c",&_move);
       _move|= (1<<5); // making the letter in lower case , thug life way
       while(_move != 's' &&_move != 'e' &&_move != 'i'   ) // making sure the user entered a proper input
       {
          puts("INVALIDE INPUT, TRY AGAIN...\n\n");
       scanf(" %c",&_move);
            _move|= (1<<5);
       }
       if(_move=='s')
        {
            while(1)
            {
               print_view(&my_map);
                printf("DIRECTION: ");
                scanf(" %c",&_move);
                _move &= ~(1<<5) ; // making the letter in upper case, thug life way |B
              int result = game_move(&my_map , _move);
                puts( "\n\n");
              if(result == 2)
              {
                  win();
                  break;
              }
              if(result == 0)
              {
                  lose();
                  break;
              }
              if(result == -1)
                puts( "INVALID INPUT");

            }
        }
        else if (_move == 'i')
        {
            instructions();
        }
        else {
           puts( "*************GOOD BYE*************\n\n");
            exit(0);
        }
   }

    return 0;
}
