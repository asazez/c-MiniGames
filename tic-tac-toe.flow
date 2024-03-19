#define _CRT_SECURE_NO_WARNINGS
#include "morrisboard.h"
#include <stdio.h>

int main(void) {
    // TO DO

    int pos;                                                                 /*initialization of position*/
    pos = 0;

    int board;                                                                /*the empty board*/
    board = 0;


    printBoard(0);                                                            /*print an empty board*/

    int nextpos;
    nextpos = 0;                                                              /*to avoid player calls a same position (step 1)*/

    int round;
    round = 0;

    int tmp2;                                                                  /*store board of phase 1 for phase 2*/
    int tmp3;                                                                  /*store board of phase 1 for phase 2*/

    do {

        int tmp;                                                                      /*store board of phase 1 for phase 2*/
        tmp = 0;

            int p;                                                                    /*control the players'name (step 1)*/
            p = 1;
            while (p < 3 && formLine(board) == 0) {                                   /*control the players'name (step 2)*/


                printf("Player %d (1-9): ", p);
                int t = scanf_s("%d", &pos);

                while (pos < 1 || pos > 9 || pos == nextpos) {                    /*to avoid player calls a same position (step 2) or invalid call*/
                    printf("Invalid. Tyr again!\n");
                    printf("Player %d (1-9): ",p);
                    int t = scanf_s("%d", &pos);
                }

                printBoard(placePiece(board, pos, p));

                board = placePiece(board, pos, p);

                nextpos = pos;                                                 /*to avoid next player calls a same position (step 3)*/

                p++;                                                           /*control players' name(step 3)*/
                round++;

                tmp = board;                                                    /*store board of phase 1 for phase 2*/

            }     

            tmp2 = tmp;                                                         /*store board of phase 1 for phase 2*/

    } while (round < 6 && formLine(board) == 0);                                /*control phase 1*/

    tmp3 = tmp2;                                                                /*store board of phase 1 for phase 2*/
    board = tmp3;                                                               /*transfer storage of phase 1 board to the board variable*/

    if (formLine(board) == 1 || formLine(board) == 2)
        printf("Player %d wins!\n", formLine(board));




    if (formLine(board) == 0)                                                  /*phase 2 starts*/

        do {

            int p;
            p = 1;
            while (p < 3 && formLine(board) == 0) {                                         /*control players' name*/

                int from;
                from = 0;
                int to;
                to = 0;

                int t;
                do{

                    printf("Player %d (from to): ", p);                                   
                    t = scanf("%d%d",&from, &to);                                 
                   while(t != 2 || from == to || movecheckfrom(board, from, p) == 1 || movecheckto(board, to) == 1){ 
                   
                      printf("Invalid. Try again!\n");
                      printf("Player %d (from to): ", p);                                  
                      t = scanf("%d%d", &from, &to);
                    
                   }

                } while (t != 2 || from == to || movecheckfrom(board, from, p) == 1 || movecheckto(board, to) == 1);

                printBoard(movePiece(board, from, to, p));

                board = (movePiece(board, from, to, p));

                p++;                                                                        /*control players' name*/

            }

        } while (formLine(board) == 0);

    if (formLine(board) == 1 || formLine(board) == 2)
        printf("Player %d wins!\n", formLine(board));
  
    return 0;

}
