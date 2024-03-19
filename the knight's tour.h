#include <stdbool.h>

typedef struct lostkingtour {
    int board[8][8];
    int currentR, currentC;
    int cross, max;
    char lastDir[10];
} LostKingTour;

void initTour(LostKingTour* t, int r, int c, int m);
void printTour(const LostKingTour* t);
bool isKingMoveValid(const LostKingTour* t, int r, int c);
bool hasMoreKingMoves(const LostKingTour* t);
bool moveKing(LostKingTour* t, int r, int c);
