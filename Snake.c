/*########################
#                      #
#   killator program   #
#                      #
#                      #
########################*/
/* *************************************************************************
 *   To contact the author, please write to:                               *
 *   Victor Cajubá,Rafael Santos e Daniel                                  *
 *   Email: victorcajuba@gmail.com                                         *
 *   Phone: +55 (86) 995236214                                             *
 ***************************************************************************/

#include<stdio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <ncurses.h> 
#include <getopt.h> 
#include <string.h> 
#include <assert.h> 
#include <unistd.h> 
#define LABL 50 // 23
#define LABC 50 // 21  

int main (void)
{
  
const  char labmodel[LABL][LABC]=
{
    
    /*012345678901234567890123456789012345678*/                         
    {"#######################################"},    /* 0*/
    {"#                                     #"},    /* 1*/
    {"#                                     #"},    /* 2*/
    {"#                                     #"},    /* 3*/
    {"#                                     #"},    /* 4*/
    {"#                                     #"},    /* 5*/
    {"#                                     #"},    /* 6*/
    {"#                                     #"},    /* 7*/
    {"#                                     #"},    /* 8*/
    {"#                                     #"},    /* 9*/
    {"#                                     #"},    /*10*/
    {"#                                     #"},    /*11*/
    {"#                                     #"},    /*12*/
    {"#######################################"}     /*13*/ 
};
    int a, b,c,d;
    
    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

     while(1)
     {
        leitura=getch;
        for(a = 0; a < 6;a++)
        {
          mvprintw(a,5,".");
          mvchgat(a, 5, 1, A_BOLD, 6, NULL);
        }
     }
 return 0;
   usleep(166667);
    endwin();
}
int movimentacao(int leitutra, int a)
{
  

  switch(leitura)
  {
    case KEY_RIGHT :
     a = a +1 ;
    break ;
    case KEY_LEFT :
     a = a -1 ;
    break ;
  }
  return a;
}
