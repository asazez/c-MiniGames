#define _CRT_SECURE_NO_WARNINGS

// Include more headers below if needed
#include "lostking.h"
#include <stdio.h>


int main(void) {
    LostKingTour tour;
    // TO DO

    initTour(&tour, 0, 0, 0);                /*initialization*/
    LostKingTour* tourPtr = &tour;        /*create a pointer*/

    printf("Starting position (row col): ");                     /*The program starts with prompting the user to enter the king’s starting position. You can assume that this user input is always two integers, the row and column in the chessboard*/
    int t = scanf("%d %d", &tourPtr->currentR, &tourPtr->currentC);
    while (t != 2 || tourPtr->currentR < 0 || tourPtr->currentR > 7 || tourPtr->currentC < 0 || tourPtr->currentC > 7) {      //If the user enters an invalid position (row or column outside 0–7, display a warning and go back to step 1.//
        printf("Invalid. Try again!\n");
        printf("Starting position (row col): ");
        t=scanf("%d %d", &tourPtr->currentR, &tourPtr->currentC);
    }

    printf("Max crossing: ");
    t=scanf("%d", &tourPtr->max);   /*Next, prompt the user to enter the maximum allowed king crossings*/
    while (tourPtr->max <= 0) {
        printf("Invalid. Try again!\n"); /* display a warning and go back to step 3.*/
        printf("Max crossing: ");
        t=scanf("%d", &tourPtr->max);
    }


    printTour(&tour);

    /*game starts*/

	int r = 0;
	int c = 0;

	while ((hasMoreKingMoves(&tour) == true)) {


		printf("Make a move (row col): ");
		t = scanf("%d %d", &r, &c);

		while ((isKingMoveValid(&tour, r, c)) == false) {
			printf("Invalid move. Try again!\n");
			printf("Make a move (row col): ");
			t = scanf("%d %d", &r, &c);
		}

		moveKing(&tour, r, c);
		printTour(&tour);

	}

	int boardfullcheck = 0;                                  /*check is the player finish the game*/
	

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (tourPtr->board[i][j] == -10) {
					boardfullcheck++;
				}
			}
		}

		if (boardfullcheck > 0) {
			printf("Sorry. No more moves!\n");
		}

		if (boardfullcheck == 0) {
			printf("Finished.Well Done!\n");
		}

	

    return 0;
}
