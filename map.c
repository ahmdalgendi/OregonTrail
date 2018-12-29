#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "map_struct.h"

struct Node *node(){
        struct Node * x;
        x  = malloc(sizeof (struct Node) );
        x->d = x->u = x->l = x->r  = NULL;
        x->discoverd = 0;
        return x;
}
void visit(struct Node * x) // mark the node as visited
{
    x->discoverd=1;
}


int my_case (char c, struct game_map *my_mab ) // function that takes char paramter where the cell i am in and returns an int
{                                  // if 0 is returned , then i shall return to the last cell ,   2  means that the player won
  if (c == 'O')                                  // if 0 then the user choosed to move to the new cell
    {
       printf("Cannot pass ocean tiles\n" );
        return 0 ; // user return to the cell

    }

    if(c  == 'G')
    {
        printf( "You have encountered a Grizzly bear, would you choose to hunt (h) or retreat (r)\n");
        char x;
        scanf(" %c", &x);
        if(x=='h')
        {
           my_mab ->food-=15;
            return 1;
        }
        printf( "Retreating .... \n");
         return 0;
    }
    if(c == 'E')
    {
        printf( "You have encountered an Elk, would you choose to hunt (h) or retreat(r)\n");
        char x;

        scanf(" %c", &x);
        if (x== 'h')
        return 1;

        printf( "Retreating .... \n");
        return 0;
    }
     if(c == 'B')
    {
        printf( "You have encountered a Boar, would you choose to hunt (h) or retreat(r)\n");
        char x;

        scanf(" %c", &x);
        if (x== 'h')
        {
            my_mab->food -=5;
            return 1;
        }
        printf( "Retreating .... \n");
        return 0;
    }
     if(c == 'H')
    {
       printf("You have encountered a Hare, would you choose to hunt (h) or retreat(r)\n");
        char x;

        scanf(" %c", &x);
        if (x== 'h')
        {
            my_mab->food+=5;
            return 1;
        }


      printf( "Retreating .... \n");
        return 0;
    }

    if (c == 'C')
    {
        printf ("You have contracted the common cold, your food storage drops by 5 as you take a day off to recuperate\n");
        my_mab->food -=5;
        return 1;
    }
    if(c== 'R')
    {
       printf("You are attempting to ford a river; you may either choose to ford (f) or retreat(r)\n");
        char x ;
        scanf(" %c", &x);
        if(x == 'f')
        {
            my_mab->food-=20;
            return 1;
        }

       printf( "Retreating .... \n");
        return 0;
    }
    if (c == 'T' )
    {
    printf( "You have contracted the Thunderstorm, your food storage drops by 10 as you take a day off to recuperate\n");

    my_mab->food-=10;
        return 1;

    }
    if(c == 'D')
    {
    printf( "You have contracted the Dysentery, your food storage drops by 15 as you take a day off to recuperate\n");
        my_mab->food-=15;
        return 1;
    }
    if(c=='Z') /// reached the distination
        return 2;
    if(c=='N') // already visited node
    {
       printf( "returning to to prevoisly visited \n");
        return 1;
    }
    return -1 ;
}


bool is_win(struct game_map * my_mab)
{
    return my_mab->win_;
}
int to_int(char * s)
{   int sz = strlen(s), ans = 0 , pw =1;
    for(int i = sz-1; i >=0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9'){
        ans+= (s[i] - '0' ) * pw;
        pw*=10;}

    }

    s = NULL ;
    return ans;

}
struct game_map Game_map (){
        struct game_map my_mab ;
        my_mab.map_size = 0;
        my_mab.view_port = 0;
        my_mab.  food = 0;
        my_mab.head =NULL;
        my_mab.win_ = 0;
        return my_mab;
    }

void load_map(struct game_map * my_mab)
{
    FILE * fb = (FILE*) malloc(sizeof (FILE) );
    fb =fopen("hw3Input.txt", "r"); // open the file and return a pointer to it in fb
    char *a , *b , *c , *t;
    //dynamicly allocating the chars
     a = malloc(100* sizeof(char));
     b=malloc(100* sizeof(char));
      c =malloc(100* sizeof(char));
       t= malloc(100* sizeof(char));
    // read the first 3 lines
    fgets(a,100, fb);
    fgets(b,100, fb);
    fgets(c,100, fb);
    bool f =0;
    // saving sizes of the strings
    int asz = strlen(a) , bsz = strlen(b), csz = strlen(c);
    int idx = 0;
    // input is in the form "mapsize:#X" as x is the intger value
    // in this loop I'm savin only #X in t to convert it into an int
    for(int i=0;i<asz;i++) // iterating the whole string
    {

        if (f) // start saving the int value from the string in char
            t[idx]=a[i] , idx++;
        if (a[i]==':')  //  if : is read then the next char is the beging of the int
            f=1; // mark flag as true
    }
    //
    my_mab->map_size = to_int(t);

    f =0;
    idx = 0;
    for(int i=0;i<bsz;i++)
    {
        if (f)
            t[idx]=b[i], idx++;
        if (b[i]==':')
            f=1;
    }

    my_mab->view_port = to_int(t);
    f =0;
    idx = 0;
    for(int i=0;i<csz;i++)
    {
        if (f)
            t[idx]=c[i], idx++;
        if (c[i]==':')
            f=1;
    }
    my_mab->food = to_int(t);
    // dynamiclly  allocating 2d array of char to read the file
    int **curr = malloc(100 * sizeof(char *));
    for (int i=0; i<100; i++)
         curr[i] = malloc(100 * sizeof(char));

    // reading a useless string from file "map"
     fgets(t,100, fb);
     fgets(t,100, fb);
     char tmp ;
     bool more = 1;
     int q=0 , w=0;
     while(more)  { // loop to read the whole file , (q, w) are the indices
           tmp= fgetc(fb);
            if (feof(fb)) // checking if EOF is reached
                {
                    more = 0 ;
                    break;
                }
           // printf("%c", tmp);
            if(tmp != ' ' && tmp != '\n') // if the read char is not '\n' then keep reading the row
                curr[q][w]= tmp, w++;       // else go to the next row
            else q++, w= 0;

        }

    int n = q-1;
     struct Node*** array2d = malloc(sizeof(struct Node **) * 100);
     for(int i=0;i<100;i++)
        array2d[i] = malloc(sizeof(struct Node *) * 100);
    for(int i=0;i<n+10;i++)
        for(int j=0;j<n+10;j++)
        array2d[i][j] = NULL;
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++)
        array2d[i][j] = malloc(sizeof(struct Node)); // allocate every node to a memory location
    for(int i =n; i>=1; i--)
    {
        for(int j =n;j>=1;j--)
        {
            // building each node
            // ocean nodes are null nodes
            array2d[i][j] ->data = curr[i][j];
            array2d[i][j] -> l = array2d[i][j-1];
            array2d[i][j] -> r = array2d[i][j+1];
            array2d[i][j] -> u = array2d[i-1][j];
            array2d[i][j] -> d = array2d[i+1][j];
            array2d[i][j]->x  = j;
            array2d[i][j]->y = i;

        }
    }
    my_mab->head  = array2d[8][8];
    visit(my_mab->head);
    /*
    freeing the memory
    */
   free(a);
   free(b);
   free(c);
   free(t);
   for(int i=0;i<100;i++)
   {
       free(array2d[i]);
       free(curr[i]);
   }
   free(array2d);
   free(curr);
}

///******************************************************************************************************************
        // moving functions , for up , down , left, right
void moveLeft(struct game_map *my_head)
{
    if(my_head->head->l)
    {
  visit(  my_head->head->l);
     int ret = my_case(my_head->head->l->data, my_head);
     if(ret==1)
     {
        my_head->head->data = 'N';
        my_head->head= my_head->head->l;
       my_head-> head->data = 'X';

     }
     else if (ret==2)
       my_head-> win_ =true;
    }
    else{
        my_case('O', my_head);
    }
}

void moveUp(struct game_map *my_head)
{
    if(my_head->head->u) // node is not null
    {
                visit(my_head->head->u);// mark as visited
     int ret = my_case(my_head->head->u->data, my_head);
     if(ret==1)
     {
       my_head-> head->data = 'N';
       my_head-> head=my_head-> head->u;
        my_head->head->data = 'X';

     }
     else if (ret==2)
        my_head->win_ =true;
    }
    else{
        my_case('O', my_head); // null node
    }
}

void moveRight(struct game_map * my_head)
{
    if(my_head->head->r)
    {
    visit(my_head->head->r);
     int ret = my_case(my_head-> head->r->data, my_head);
     if(ret==1)
     {
        my_head->head->data = 'N';
        my_head->head=my_head-> head->r;
        my_head->head->data = 'X';

     }
     else if (ret==2)
        my_head->win_ =true;
    }
    else{
        my_case('O', my_head);
    }
}

void moveDown(struct game_map *my_head)
{
    if(my_head->head->d)
    {
    visit(my_head->head->d);
     int ret = my_case(my_head->head->d->data, my_head);
     if(ret==1)
     {
        my_head->head->data = 'N';
        my_head->head=my_head-> head->d;
        my_head->head->data = 'X';

     }
     else if (ret==2)
        my_head->win_ =true;
    }
    else{
        my_case('O', my_head);
    }
}

void print_view(struct game_map * my_head) // function to print the port
{
    /*

    to print the view port  i have to find a new node to  start printing from
    for example if this was the view port
       123
       456
       789
    then my location is at node 5
    i have to find node 1 to start printing form it
    so i go up for (view port /2) node and go left for (view_port/2) node
    --------------------------------------------------------------------.
    but there are some corner cases
    can be summerised in the following example
     0 is a null "ocean" node

->   0  0  0   0  0
     0  7  8   9  0
     0  12 13 14  0
     0  0  0  0   0
     0  0  0  0   0
     the current node is 13 but i cant go to the top left node as its null
     going right also we have some null nodes , left and down we have the same

    */
    printf("Food:%d\n" , my_head->food);
   struct Node * view_start = node() ;
    view_start = my_head->head;
    int tmp = my_head->view_port/2;
    int moreUp= tmp, moreLeft = tmp; // are two variables that indicates if the top and the left are reached
    for(int i= 0;i< tmp; i++) // go up
    {
        if(view_start->u)
            view_start = view_start->u , moreUp--;
        else break;
    }

    for(int i= 0;i < tmp; i++) // go left
       {

        if(view_start->l)
            view_start = view_start->l, moreLeft --;
        else break;
       }
    // print areas outside the map as ocean form up
    for(int i=0;i<moreUp;i++)
    {
        for(int j=0;j<my_head->view_port;j++)
            printf("O");
        puts("");   // newline
    }

    // printing the view port row by row
    for(int i=0; i< my_head->view_port - moreUp; i++)
    {
       struct Node * tmp_node = view_start;
        if(tmp_node) // checking if the current row has a node or a null
            {
                for(int j=0;j<moreLeft; j++)
                {
                    printf("O");
                }
                for(int j = moreLeft; j< my_head->view_port; j++)
                {
                    if(tmp_node)
                    {
                        if( tmp_node->discoverd || tmp_node-> data == 'R') // checking if the node is discoverd or not
                            printf("%c", tmp_node->data);
                        else printf("U");
                    tmp_node = tmp_node->r;
                    }
                    else printf( "O"); // node is null , ie it s an ocean node


                }
        }
        else { // if null then its ocean nodes
            for(int j=0;j<my_head->view_port;j++)
                printf("O");
        }
       puts("");
       if(view_start)// going down
        view_start= view_start->d;
    }
    // freeing memory
    free( view_start);

}

