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
#define LABL  50 //23
#define LABC  50 //21  

int impressao(void);
int movimentacao(int leitura, int a, int b);



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
    int i, d, leitura, cobra[10];

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK);  
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK); 
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); 

    for(i=0; i<10; i++)
    {
        cobra[i] = i+10;
    }

    while(1)
    {
        leitura=getch();

        if(leitura == 'q')
            break;

        usleep(60000);
        clear();
                                    
        for(d=0 ; d<=13; d++)/*impressao do cenario*/
            printw("%s\n", labmodel[d]);

        for(i=0; i<10; i++)/*  impressao da cobra*/
        {
            mvprintw(7, cobra[i],"O");
            mvchgat(7, cobra[i], 1, A_BOLD, 6, NULL);
        }
        refresh();

    }
    return 0;
    usleep(166667);
    endwin();
}
int impressao(void)
        clear();
                                    
        for(d=0 ; d<=13; d++)/*impressao do cenario*/
            printw("%s\n", labmodel[d]);

        for(i=0; i<10; i++)/*  impressao da cobra*/
        {
            mvprintw(7, cobra[i],"O");
            mvchgat(7, cobra[i], 1, A_BOLD, 6, NULL);
        }
        refresh();
{

}



int movimentacao(int leitura, int a, int b)
{


    switch(leitura)
    {
        case KEY_RIGHT :
            a = a +1 ;
            break ;
        case KEY_LEFT :
            a = a -1 ;
            break ;
        case KEY_UP :/*aqui teremos que criar uma struct pra  retornar  o x e y ou usar ponteiro*/
            b = b - 1 ;
            break ;
        case KEY_DOWN :
            b = b + 1 ;
            break ;
    }
    return a;
}

