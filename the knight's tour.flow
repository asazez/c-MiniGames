#define _CRT_SECURE_NO_WARNINGS
#include "lostking.h"
#include <stdio.h>
#include <string.h>

void initTour(LostKingTour* t, int r, int c, int m) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            t->board[i][j] = -10;       /*initialize all unvisited suqares to -10*/
        }
    }

    t->currentR = r;
    t->currentC = c;
    t->cross = 0;
    t->max = m;
    strcpy(t->lastDir, "---");
}

void printTour(const LostKingTour* t) {

    printf(" ");


    for (int i = 0; i < 8; i++) {                            /*print the rows*/
        printf("%3d", i);
    }

    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("%d", i);

        for (int j = 0; j < 8; j++) {
            if (i == t->currentR && j == t->currentC) {
                printf("  K");
            }
            else if (t->board[i][j] == -10) {
                printf("  .");
            }
            else if (t->board[i][j] < 10) {
                printf("  %d", t->board[i][j]);
            }
            else {
                printf(" %d", t->board[i][j]);
            }
        }
        printf("\n");
    }

    printf("Num of crossing: %d\n",t->cross);
    printf("Max crossings: %d\n", t->max);
    printf("Last Direction: %s\n", t->lastDir);

}

bool iscross(LostKingTour t, int r, int c, int currentR, int currentC) {
    if ((r - currentR == 1 && c - currentC == 1) ||
        (r - currentR == 1 && c - currentC == -1) ||
        (r - currentR == -1 && c - currentC == 1) ||
        (r - currentR == -1 && c - currentC == -1))
            if (abs(t.board[r][currentC] - t.board[currentR][c]) == 1)
            return true;
    return false;
}

bool isKingMoveValid(const LostKingTour* t, int r, int c) {
    // TO DO; add a return statement in order to compile
    if (r < 0 || r >= 8 || c < 0 || c >= 8) {  /*over the board*/
        return false;
    }
    if (t->board[r][c] != -10) {   /*the destination is occupied*/
        return false;
    }

     /*check the destination is not one square away the current position*/

    bool validmove = false;
    int distance_r = abs(r - t->currentR);
    int distance_c = abs(c - t->currentC);
    if ((distance_r == 1 && distance_c == 0) || (distance_r == 0 && distance_c == 1) || (distance_r == 1 && distance_c == 1)) {
        validmove = true;
    }
    if (!validmove) {
        return false;
    }
    
    /*check the destination is not the same direction as last time*/
    char direction[10] = "Undefined";

        if (r - t->currentR == 1 && c - t->currentC == 0) {
            strcpy(direction, "South");
        }
        else if (r - t->currentR == 0 && c - t->currentC == 1) {
            strcpy(direction, "East");
        }
        else if (r - t->currentR == -1 && c - t->currentC == 0) {
            strcpy(direction , "North");
        }
        else if (r - t->currentR == 0 && c - t->currentC == -1) {
            strcpy(direction, "West");
        }
        else if (r - t->currentR == 1 && c - t->currentC == 1) {
            strcpy(direction, "Southeast");
        }
        else if (r - t->currentR == 1 && c - t->currentC == -1) {
            strcpy(direction, "Southwest");
        }
        else if (r - t->currentR == -1 && c - t->currentC == 1) {
            strcpy(direction, "Northeast");
        }
        else if (r - t->currentR == -1 && c - t->currentC == -1){
            strcpy(direction, "Northwest");
        }

    if (strcmp(direction, t->lastDir) == 0){
        return false;
    }

  /*check the destination didn't cross more than max times*/

    if (iscross(*t, r, c, t->currentR, t->currentC) && t->cross >= t->max)
        return false;

    else return true;

}


bool hasMoreKingMoves(const LostKingTour* t) {
    // TO DO; add a return statement in order to compile
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {   /*don't need to check this position*/
                continue;
            }
            int r = t->currentR + i;  /*check every direction*/
            int c = t->currentC + j;
            if (isKingMoveValid(t, r, c) == true) { /*check has more king moves*/
                return true;
            }
        }
    }
    return false;  /*no more moves*/
}

bool moveKing(LostKingTour* t, int r, int c) {
    // TO DO; add a return statement in order to compile

    /*record the path in the board*/
    static int counter = 0;
    ++counter;
    t->board[t->currentR][t->currentC] = counter - 1;

    t->board[r][c] = 'K';              /*the position of king*/

    
    if (r - t->currentR == 1 && c - t->currentC == 0) {           //update the last direction
        strcpy(t->lastDir, "South");
    }
    else if (r - t->currentR == 0 && c - t->currentC == 1) {
        strcpy(t->lastDir, "East");
    }
    else if (r - t->currentR == -1 && c - t->currentC == 0) {
        strcpy(t->lastDir, "North");
    }
    else if (r - t->currentR == 0 && c - t->currentC == -1) {
        strcpy(t->lastDir, "West");
    }
    else if (r - t->currentR == 1 && c - t->currentC == 1) {
        strcpy(t->lastDir, "Southeast");
    }
    else if (r - t->currentR == 1 && c - t->currentC == -1) {
        strcpy(t->lastDir, "Southwest");
    }
    else if (r - t->currentR == -1 && c - t->currentC == 1) {
        strcpy(t->lastDir, "Northeast");
    }
    else if(r - t->currentR == -1 && c - t->currentC == -1) {
        strcpy(t->lastDir, "Northwest");
    }

    if (iscross(*t, r, c, t->currentR, t->currentC) == true) {       // update the cross number
        t->cross += 1;
    }

    t->currentR = r;      /*update*/
    t->currentC = c;
 

}
