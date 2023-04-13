#ifndef __GAME_CODE_
#define __GAME_CODE_

#include <time.h>

typedef struct
{
    int gameResult;
    time_t dateAdded;
} Game;

void gameMain();

#endif