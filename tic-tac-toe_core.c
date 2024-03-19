#include "morrisboard.h"
#include <stdio.h>

int boardState(int board, int pos) {
    for (int i = 0; i < 9 - pos; i++)
        board /= 10;
    return board % 10;
}

/* Prints the board to the screen. DO NOT MODIFY! */
void printBoard(int board) {
    printf("%d-%d-%d\n",
        boardState(board, 1), boardState(board, 2), boardState(board, 3));
    printf("|\\|/|\n");
    printf("%d-%d-%d\n",
        boardState(board, 4), boardState(board, 5), boardState(board, 6));
    printf("|/|\\|\n");
    printf("%d-%d-%d\n",
        boardState(board, 7), boardState(board, 8), boardState(board, 9));
}

/* Perform the task of player p placing a piece to position pos of board. */
int placePiece(int board, int pos, int p) {
    // TO DO; add a return statement in order to compile
    if (pos == 1 && p == 1)
        board = board + 100000000;
    if (pos == 2 && p == 1)
        board = board + 10000000;
    if (pos == 3 && p == 1)
        board = board + 1000000;
    if (pos == 4 && p == 1)
        board = board + 100000;
    if (pos == 5 && p == 1)
        board = board + 10000;
    if (pos == 6 && p == 1)
        board = board + 1000;
    if (pos == 7 && p == 1)
        board = board + 100;
    if (pos == 8 && p == 1)
        board = board + 10;
    if (pos == 9 && p == 1)
        board = board + 1;

    if (pos == 1 && p == 2)
        board = board + 200000000;
    if (pos == 2 && p == 2)
        board = board + 20000000;
    if (pos == 3 && p == 2)
        board = board + 2000000;
    if (pos == 4 && p == 2)
        board = board + 200000;
    if (pos == 5 && p == 2)
        board = board + 20000;
    if (pos == 6 && p == 2)
        board = board + 2000;
    if (pos == 7 && p == 2)
        board = board + 200;
    if (pos == 8 && p == 2)
        board = board + 20;
    if (pos == 9 && p == 2)
        board = board + 2;

    return board;

}

/* Perform the task of player p moving a piece from position from to position
   to of board. */
int movePiece(int board, int from, int to, int p) {
    // TO DO; add a return statement in order to compile

    if (p == 1) {
        if (from == 1 && to == 2)
            board = board - 100000000 + 10000000;
        if (from == 1 && to == 3)
            board = board - 100000000 + 1000000;
        if (from == 1 && to == 4)
            board = board - 100000000 + 100000;
        if (from == 1 && to == 5)
            board = board - 100000000 + 10000;
        if (from == 1 && to == 6)
            board = board - 100000000 + 1000;
        if (from == 1 && to == 7)
            board = board - 100000000 + 100;
        if (from == 1 && to == 8)
            board = board - 100000000 + 10;
        if (from == 1 && to == 9)
            board = board - 100000000 + 1;

        if (from == 2 && to == 1)
            board = board - 10000000 + 100000000;
        if (from == 2 && to == 3)
            board = board - 10000000 + 1000000;
        if (from == 2 && to == 4)
            board = board - 10000000 + 100000;
        if (from == 2 && to == 5)
            board = board - 10000000 + 10000;
        if (from == 2 && to == 6)
            board = board - 10000000 + 1000;
        if (from == 2 && to == 7)
            board = board - 10000000 + 100;
        if (from == 2 && to == 8)
            board = board - 10000000 + 10;
        if (from == 2 && to == 9)
            board = board - 10000000 + 1;

        if (from == 3 && to == 1)
            board = board - 1000000 + 100000000;
        if (from == 3 && to == 2)
            board = board - 1000000 + 10000000;
        if (from == 3 && to == 4)
            board = board - 1000000 + 100000;
        if (from == 3 && to == 5)
            board = board - 1000000 + 10000;
        if (from == 3 && to == 6)
            board = board - 1000000 + 1000;
        if (from == 3 && to == 7)
            board = board - 1000000 + 100;
        if (from == 3 && to == 8)
            board = board - 1000000 + 10;
        if (from == 3 && to == 9)
            board = board - 1000000 + 1;

        if (from == 4 && to == 1)
            board = board - 100000 + 100000000;
        if (from == 4 && to == 2)
            board = board - 100000 + 10000000;
        if (from == 4 && to == 3)
            board = board - 100000 + 1000000;
        if (from == 4 && to == 5)
            board = board - 100000 + 10000;
        if (from == 4 && to == 6)
            board = board - 100000 + 1000;
        if (from == 4 && to == 7)
            board = board - 100000 + 100;
        if (from == 4 && to == 8)
            board = board - 100000 + 10;
        if (from == 4 && to == 9)
            board = board - 100000 + 1;

        if (from == 5 && to == 1)
            board = board - 10000 + 100000000;
        if (from == 5 && to == 2)
            board = board - 10000 + 10000000;
        if (from == 5 && to == 3)
            board = board - 10000 + 1000000;
        if (from == 5 && to == 4)
            board = board - 10000 + 100000;
        if (from == 5 && to == 6)
            board = board - 10000 + 1000;
        if (from == 5 && to == 7)
            board = board - 10000 + 100;
        if (from == 5 && to == 8)
            board = board - 10000 + 10;
        if (from == 5 && to == 9)
            board = board - 10000 + 1;

        if (from == 6 && to == 1)
            board = board - 1000 + 100000000;
        if (from == 6 && to == 2)
            board = board - 1000 + 10000000;
        if (from == 6 && to == 3)
            board = board - 1000 + 1000000;
        if (from == 6 && to == 4)
            board = board - 1000 + 100000;
        if (from == 6 && to == 5)
            board = board - 1000 + 10000;
        if (from == 6 && to == 7)
            board = board - 1000 + 100;
        if (from == 6 && to == 8)
            board = board - 1000 + 10;
        if (from == 6 && to == 9)
            board = board - 1000 + 1;

        if (from == 7 && to == 1)
            board = board - 100 + 100000000;
        if (from == 7 && to == 2)
            board = board - 100 + 10000000;
        if (from == 7 && to == 3)
            board = board - 100 + 1000000;
        if (from == 7 && to == 4)
            board = board - 100 + 100000;
        if (from == 7 && to == 5)
            board = board - 100 + 10000;
        if (from == 7 && to == 6)
            board = board - 100 + 1000;
        if (from == 7 && to == 8)
            board = board - 100 + 10;
        if (from == 7 && to == 9)
            board = board - 100 + 1;

        if (from == 8 && to == 1)
            board = board - 10 + 100000000;
        if (from == 8 && to == 2)
            board = board - 10 + 10000000;
        if (from == 8 && to == 3)
            board = board - 10 + 1000000;
        if (from == 8 && to == 4)
            board = board - 10 + 100000;
        if (from == 8 && to == 5)
            board = board - 10 + 10000;
        if (from == 8 && to == 6)
            board = board - 10 + 1000;
        if (from == 8 && to == 7)
            board = board - 10 + 100;
        if (from == 8 && to == 9)
            board = board - 10 + 1;

        if (from == 9 && to == 1)
            board = board - 1 + 100000000;
        if (from == 9 && to == 2)
            board = board - 1 + 10000000;
        if (from == 9 && to == 3)
            board = board - 1 + 1000000;
        if (from == 9 && to == 4)
            board = board - 1 + 100000;
        if (from == 9 && to == 5)
            board = board - 1 + 10000;
        if (from == 9 && to == 6)
            board = board - 1 + 1000;
        if (from == 9 && to == 7)
            board = board - 1 + 100;
        if (from == 9 && to == 8)
            board = board - 1 + 10;

    }

    if (p == 2) {
        if (from == 1 && to == 2)
            board = board - 200000000 + 20000000;
        if (from == 1 && to == 3)
            board = board - 200000000 + 2000000;
        if (from == 1 && to == 4)
            board = board - 200000000 + 200000;
        if (from == 1 && to == 5)
            board = board - 200000000 + 20000;
        if (from == 1 && to == 6)
            board = board - 200000000 + 2000;
        if (from == 1 && to == 7)
            board = board - 200000000 + 200;
        if (from == 1 && to == 8)
            board = board - 200000000 + 20;
        if (from == 1 && to == 9)
            board = board - 200000000 + 2;

        if (from == 2 && to == 1)
            board = board - 20000000 + 200000000;
        if (from == 2 && to == 3)
            board = board - 20000000 + 2000000;
        if (from == 2 && to == 4)
            board = board - 20000000 + 200000;
        if (from == 2 && to == 5)
            board = board - 20000000 + 20000;
        if (from == 2 && to == 6)
            board = board - 20000000 + 2000;
        if (from == 2 && to == 7)
            board = board - 20000000 + 200;
        if (from == 2 && to == 8)
            board = board - 20000000 + 20;
        if (from == 2 && to == 9)
            board = board - 20000000 + 2;

        if (from == 3 && to == 1)
            board = board - 2000000 + 200000000;
        if (from == 3 && to == 2)
            board = board - 2000000 + 20000000;
        if (from == 3 && to == 4)
            board = board - 2000000 + 200000;
        if (from == 3 && to == 5)
            board = board - 2000000 + 20000;
        if (from == 3 && to == 6)
            board = board - 2000000 + 2000;
        if (from == 3 && to == 7)
            board = board - 2000000 + 200;
        if (from == 3 && to == 8)
            board = board - 2000000 + 20;
        if (from == 3 && to == 9)
            board = board - 2000000 + 2;

        if (from == 4 && to == 1)
            board = board - 200000 + 200000000;
        if (from == 4 && to == 2)
            board = board - 200000 + 20000000;
        if (from == 4 && to == 3)
            board = board - 200000 + 2000000;
        if (from == 4 && to == 5)
            board = board - 200000 + 20000;
        if (from == 4 && to == 6)
            board = board - 200000 + 2000;
        if (from == 4 && to == 7)
            board = board - 200000 + 200;
        if (from == 4 && to == 8)
            board = board - 200000 + 20;
        if (from == 4 && to == 9)
            board = board - 200000 + 2;

        if (from == 5 && to == 1)
            board = board - 20000 + 200000000;
        if (from == 5 && to == 2)
            board = board - 20000 + 20000000;
        if (from == 5 && to == 3)
            board = board - 20000 + 2000000;
        if (from == 5 && to == 4)
            board = board - 20000 + 200000;
        if (from == 5 && to == 6)
            board = board - 20000 + 2000;
        if (from == 5 && to == 7)
            board = board - 20000 + 200;
        if (from == 5 && to == 8)
            board = board - 20000 + 20;
        if (from == 5 && to == 9)
            board = board - 20000 + 2;

        if (from == 6 && to == 1)
            board = board - 2000 + 200000000;
        if (from == 6 && to == 2)
            board = board - 2000 + 20000000;
        if (from == 6 && to == 3)
            board = board - 2000 + 2000000;
        if (from == 6 && to == 4)
            board = board - 2000 + 200000;
        if (from == 6 && to == 5)
            board = board - 2000 + 20000;
        if (from == 6 && to == 7)
            board = board - 2000 + 200;
        if (from == 6 && to == 8)
            board = board - 2000 + 20;
        if (from == 6 && to == 9)
            board = board - 2000 + 2;

        if (from == 7 && to == 1)
            board = board - 200 + 200000000;
        if (from == 7 && to == 2)
            board = board - 200 + 20000000;
        if (from == 7 && to == 3)
            board = board - 200 + 2000000;
        if (from == 7 && to == 4)
            board = board - 200 + 200000;
        if (from == 7 && to == 5)
            board = board - 200 + 20000;
        if (from == 7 && to == 6)
            board = board - 200 + 2000;
        if (from == 7 && to == 8)
            board = board - 200 + 20;
        if (from == 7 && to == 9)
            board = board - 200 + 2;

        if (from == 8 && to == 1)
            board = board - 20 + 200000000;
        if (from == 8 && to == 2)
            board = board - 20 + 20000000;
        if (from == 8 && to == 3)
            board = board - 20 + 2000000;
        if (from == 8 && to == 4)
            board = board - 20 + 200000;
        if (from == 8 && to == 5)
            board = board - 20 + 20000;
        if (from == 8 && to == 6)
            board = board - 20 + 2000;
        if (from == 8 && to == 7)
            board = board - 20 + 200;
        if (from == 8 && to == 9)
            board = board - 20 + 2;

        if (from == 9 && to == 1)
            board = board - 2 + 200000000;
        if (from == 9 && to == 2)
            board = board - 2 + 20000000;
        if (from == 9 && to == 3)
            board = board - 2 + 2000000;
        if (from == 9 && to == 4)
            board = board - 2 + 200000;
        if (from == 9 && to == 5)
            board = board - 2 + 20000;
        if (from == 9 && to == 6)
            board = board - 2 + 2000;
        if (from == 9 && to == 7)
            board = board - 2 + 200;
        if (from == 9 && to == 8)
            board = board - 2 + 20;

    }

    return board;

}

/* Checks if any player has formed a line horizontally, vertically, or
   diagonally in board. */
int formLine(int board) {
    // TO DO; add a return statement in order to compile
    int winner = 0;

    if (((boardState(board, 1)) == 1 && (boardState(board, 4)) == 1 && (boardState(board, 7)) == 1) ||
        ((boardState(board, 2)) == 1 && (boardState(board, 5)) == 1 && (boardState(board, 8)) == 1) ||
        ((boardState(board, 3)) == 1 && (boardState(board, 6)) == 1 && (boardState(board, 9)) == 1) ||
        ((boardState(board, 1)) == 1 && (boardState(board, 2)) == 1 && (boardState(board, 3)) == 1) ||
        ((boardState(board, 4)) == 1 && (boardState(board, 5)) == 1 && (boardState(board, 6)) == 1) ||
        ((boardState(board, 7)) == 1 && (boardState(board, 8)) == 1 && (boardState(board, 9)) == 1) ||
        ((boardState(board, 1)) == 1 && (boardState(board, 5)) == 1 && (boardState(board, 9)) == 1) ||
        ((boardState(board, 3)) == 1 && (boardState(board, 5)) == 1 && (boardState(board, 7)) == 1))
        winner = 1;

    if (((boardState(board, 1)) == 2 && (boardState(board, 4)) == 2 && (boardState(board, 7)) == 2) ||
        ((boardState(board, 2)) == 2 && (boardState(board, 5)) == 2 && (boardState(board, 8)) == 2) ||
        ((boardState(board, 3)) == 2 && (boardState(board, 6)) == 2 && (boardState(board, 9)) == 2) ||
        ((boardState(board, 1)) == 2 && (boardState(board, 2)) == 2 && (boardState(board, 3)) == 2) ||
        ((boardState(board, 4)) == 2 && (boardState(board, 5)) == 2 && (boardState(board, 6)) == 2) ||
        ((boardState(board, 7)) == 2 && (boardState(board, 8)) == 2 && (boardState(board, 9)) == 2) ||
        ((boardState(board, 1)) == 2 && (boardState(board, 5)) == 2 && (boardState(board, 9)) == 2) ||
        ((boardState(board, 3)) == 2 && (boardState(board, 5)) == 2 && (boardState(board, 7)) == 2))
        winner = 2;

    return winner;
    
}

int movecheckfrom(int board,int from,int p) {
    int checkfrom ;
    checkfrom = 0;

    for (int i = 0; i < 9 - from; i++) {                    /*check for from part*/
        board /= 10;
    }
    board = board % 10;

        if (board == 0)                                     /*nothing can be moved or */
            checkfrom = 1;                                      /*invalid*/
        else if (board != p && board != 0)                       /*move a piece that in not players' own*/
            checkfrom = 1;
      
    return checkfrom;
}

int movecheckto(int board, int to) {
    int checkto ;
    checkto = 0;

    for (int i = 0; i < 9 - to; i++) {                      /*check for destination has piece or not*/
        board /= 10;       
    }

    board = board % 10;

    if (board == 1 || board == 2)
        checkto = 1;                                             /*invalid*/

    return checkto;
}
