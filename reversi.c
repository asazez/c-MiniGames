#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#define N 7
#define EMPTY 0
#define O 1
#define X 2

void gameboard(int rows, int columns, int board[N][N]) {
	char letters[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int  row[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	int i, j;


	printf("  ");


	for (i = 0; i < columns; i++) {                            /*print the columns*/
		printf("%2c", letters[i]);
	}


	printf("\n");

	for (i = 0; i < rows; i++) {                               /*print the rows*/
		printf(" %d", row[i]);

		for (j = 0; j < columns; j++) {                           /*print the players' pieces*/
			if (board[i][j] == EMPTY) {
				printf(" .");
			}
			else if (board[i][j] == 1) {
				printf(" O");
			}
			else if (board[i][j] == 2) {
				printf(" X");
			}
		}

		printf("\n");

	}
}

int board_full_check(int board[N][N]) {                 /*check if the game is over*/

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (board[i][j] == EMPTY) {
				return 0;                               /*not full returns 0, game keep going*/
			}
		}
	}
	return 1;        /*full returns 1*/

}

int winnercheck(int board[N][N]) {
	int winner = 0;                       /*game continue*/
	int num_O = 0;
	int num_X = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				num_O++;
			}
			else if (board[i][j] == 2) {
				num_X++;
			}
		}
	}

	if (num_O == num_X) {
		winner = 1;             /*draw*/
	}

	if (num_O > num_X) {
		winner = 2;              /*O wins*/
	}

	if (num_X > num_O) {
		winner = 3;              /*X wins*/
	}

	return winner;
}

int move_from_check(int player, int(board)[][N], int rowTo, int colTo) {        /*check the piece move is invalid or not */
	if (player == O && board[rowTo][colTo] == X) {                        /*invalid move, pass*/
		return 1;
	}

	if (player == X && board[rowTo][colTo] == O) {                             /*invalid move, pass*/
		return 1;
	}

	if (board[rowTo][colTo] == EMPTY) {                                             /*invalid move, pass*/
		return 1;
	}

	else {
		return 0;
	}                                              /*valid move*/

}

int move_to_check(int board[][N], int rowTo, int colTo, int rowFrom, int colFrom) {  /*check the destination of piece move is invalid or not */

	if (rowTo < 0 || rowTo >= N || colTo < 0 || colTo >= N) {             /*invalid move, pass*/
		return 1;
	}

	else if (rowFrom == rowTo && colFrom == colTo) {                           /*invalid move, pass*/
		return 1;
	}

	else if (abs(rowTo - rowFrom) > 2 || abs(colTo - colFrom) > 2) {
		return 1;                                                                 /*invalid move, pass*/
	}

	else if (board[rowTo][colTo] != EMPTY) {                                             /*invalid move, pass*/
		return 1;
	}

	else {
		return 0;
	}                                                        /*acceptable movement*/
}

int check_for_empty_split(int rowTo, int colTo, int rowFrom, int colFrom) {
	if (colFrom == colTo && abs(rowFrom - rowTo) == 2) {
		return 1;             /*when the distance is 2 vertically, the source is empty*/
	}
	else if (rowFrom == rowTo && abs(colFrom - colTo) == 2) {    /*when the distance is 2 horizontally, the source is empty*/
		return 1;
	}
	else if (abs(rowFrom - rowTo) == 2 && abs(colFrom - colTo) == 2) {       /*when the distance is 2 diagonally, the source is empty*/
		return 1;
	}
	else if (abs(rowFrom - rowTo) == 1 && abs(colFrom - colTo) == 2) {       /*when the distance is 2 diagonally, the source is empty*/
		return 1;
	}
	else if (abs(rowFrom - rowTo) == 2 && abs(colFrom - colTo) == 1) {       /*when the distance is 2 diagonally, the source is empty*/
		return 1;
	}

	else {
		return 2;
		/*the source is split,both new position and old position have pieces*/
	}

}

int make_move(int board[][N], int colFrom, int rowFrom, int colTo, int rowTo, int player) {
	board[rowTo][colTo] = player;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {   /*checking if there have opponent's piece(s) at the 8 positions that next to destination*/
			int r = rowTo + i;
			int c = colTo + j;

			if (r < 0 || r >= N || c < 0 || c >= N) {           /*stop the function if it runs over the gameboard*/
				continue;
			}

			if (board[r][c] == player) {       /*skip position that is current player's piece*/
				continue;
			}

			if (board[r][c] == 0) {                /*skip when the position is empty*/
				continue;
			}

			/*if the adjacent position next to destination is opponent's piece(s),then change them into current*/
			board[r][c] = player;                                       /*player's piece(s)*/

		}
	}

	int empty_split = check_for_empty_split(rowTo, colTo, rowFrom, colFrom);
	if (empty_split == 1) {                     /*make sure the split and empty source are working*/
		board[rowFrom][colFrom] = 0;
	}

	else if (empty_split == 2) {
		board[rowFrom][colFrom] = player;
	}

	return 0;

}

int main(void) {

	int board[N][N] = { 0 };                                    /*initialization*/

	board[0][0] = O;                                          /*top left corner*/
	board[0][N - 1] = X;                                      /*top right corner*/
	board[N - 1][0] = X;                                      /*bottom left corner*/
	board[N - 1][N - 1] = O;                                  /*bottom right corner*/

	gameboard(N, N, board);                               /*print the first game board*/

	/*game starts*/
	int pass = 0;                                        /*if 2 passes, gameover*/
	int player = O;                                  /*the first player is always player O*/
	int last_player = O;

	while (board_full_check(board) == 0) {

		if (player == O) {
			printf("O moves (from to): ");
		}

		else {
			printf("X moves (from to): ");
		}

		char PosCharFrom, PosCharTo;
		int PosNumFrom, PosNumTo;
		int t = scanf("%c%d %c%d", &PosCharFrom, &PosNumFrom, &PosCharTo, &PosNumTo);
		(void)getchar();

		int colFrom = toupper(PosCharFrom) - 'A';             /*Convert the number entered by the player into a position*/
		int rowFrom = PosNumFrom;
		int colTo = toupper(PosCharTo) - 'A';
		int rowTo = PosNumTo;

		if (move_from_check(player, board, rowFrom, colFrom) == 0 && move_to_check(board, rowTo, colTo, rowFrom, colFrom) == 0) {

			if (check_for_empty_split(rowTo, colTo, rowFrom, colFrom) == 1) {  /*the source is empty*/
				board[rowFrom][colFrom] = 0;
				board[rowTo][colTo] = player;

				int check_move = make_move(board, colFrom, rowFrom, colTo, rowTo, player);   /*the function is use for changing opponent's piece*/
				if (check_move == 0) {
					gameboard(N, N, board);
				}

			}

			else if (check_for_empty_split(rowTo, colTo, rowFrom, colFrom) == 2) {   /*the source is split*/
				board[rowFrom][colFrom] = player;
				board[rowTo][colTo] = player;

				int check_move = make_move(board, colFrom, rowFrom, colTo, rowTo, player);
				if (check_move == 0) {
					gameboard(N, N, board);
				}
				if (check_move != 0) {
					gameboard(N, N, board);
				}
			}

			if (player == O)      /*update the player's name*/
				player = X;
			else
				player = O;

			pass = 0;

		}

		else if (move_from_check(player, board, rowFrom, colFrom) == 1 || move_to_check(board, rowTo, colTo, rowFrom, colFrom) == 1)
		{
			if (player == O) {
				printf("Invalid! O passes!\n");
			}
			else {
				printf("Invalid! X passes!\n");
			}

			pass++;
			last_player = player;

			if (player == O) {
				player = X;
			}
			else {
				player = O;                /*check if the move is valid or not.If the move is invalid, stop the while loop, it's the next player's turn*/
			}
			gameboard(N, N, board);

		}

		if (pass == 2 && last_player != player) {       /*two consecutively pass,gameover*/
			break;
		}

	}

	int num_O = 0;
	int num_X = 0;

	for (int i = 0; i < N; i++)                 /*when the game is over, calculate the pieces of each player.*/
	{
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				num_O++;
			}
			else if (board[i][j] == 2) {
				num_X++;
			}
		}
	}
	printf("O %d : %d X\n", num_O, num_X);

	if (winnercheck(board) == 1) {
		printf("Draw!\n");
	}

	if (winnercheck(board) == 2) {
		printf("O wins!\n");
	}

	if (winnercheck(board) == 3) {
		printf("X wins!\n");
	}

	return(0);
}
