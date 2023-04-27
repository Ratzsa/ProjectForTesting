#ifndef __GAME_CODE_
#define __GAME_CODE_

#include <time.h>

typedef struct
{
    int gameResult;
    time_t dateAdded;
} Game;

void gameMain();
void gameResult(const int player, int computer);
void printHand(const int choice);
void saveResult(const int result);
int gameMechanics(const int player, const int computer);

#endif