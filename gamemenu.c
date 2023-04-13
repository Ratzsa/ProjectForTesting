#include <stdio.h>
#include <stdbool.h>
#include "gamecode.h"
#include "systemfunctions.h"

void gameMenu()
{
    bool inGameMenu = true;
    int gameMenuSelect;

    while(inGameMenu)
    {
        gameMenuSelect = 0;
        clearConsole();
        printf("ROCK PAPER SCISSORS\n1. Play\n2. Print all games\n3. Return to main menu\n");
        printf("Select: ");
        scanf(" %d", &gameMenuSelect);

        switch(gameMenuSelect)
        {
            case 1:
                gameMain();
                break;

            case 2:
                printf("PRINT LIST\n");
                hitEnter();
                break;

            case 3:
                inGameMenu = false;
                break;

            default:
                printf("Incorrect input. Press enter to continue.\n");
                hitEnter();
                break;
        }
    }
}