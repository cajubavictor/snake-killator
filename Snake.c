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

Int main (void)
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
   Int a, b,c,d;
     while(1)
     {
        for(a = 0; a < 6;a++)
          mvprintw(a,5,"1");
        
     }
 return 0;
   usleep(166667);
    endwin();
}
