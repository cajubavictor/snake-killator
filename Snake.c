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

void impressao(void);
void init(void);
int movimentacao(int kin, int a, int b);

const char labmodel[LABL][LABC]=
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

typedef struct
{
    int cobra[10];
    //int 
    const char labmodel[LABL][LABC];
}t_game;

int main(void)
{

    int i, kin;
    t_game g;
 
    init();

    for(i=0; i<10; i++)
    {
        g.cobra[i] = i+10;
    }
    
    while(1)
    {
        mvprintw(7, 8,"Are you ready? y/n");
        kin=getch();
        if(kin == 'y')
            break;
        if(kin == 'n')
        {
            endwin();
            return 0;
        }
    }

    while(1)
    {
        kin=getch();

        if(kin == 'q')
            break;

        usleep(60000);
        impressao();
    }
    //usleep(166667);
    endwin();
    return 0;
}

void impressao(void)
{        
    int i;
    t_game g;
    
    clear();

    for(i=0 ; i<=13; i++)/*impressao do cenario*/
        printw("%s\n", g.labmodel[i]);

    for(i=0; i<10; i++)/*  impressao da cobra*/
    {
        mvprintw(7, g.cobra[i],"O");
        mvchgat(7, g.cobra[i], 1, A_BOLD, 6, NULL);
    }   
    refresh();
    return;
}

int movimentacao(int kin, int a, int b)
{
    switch(kin)
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

void init(void)
{
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

    return;
}
