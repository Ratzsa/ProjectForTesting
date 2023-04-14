#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gamecode.h"
#include "systemfunctions.h"

void printResults();

void gameMenu()
{
    bool inGameMenu = true;
    int gameMenuSelect;

    while(inGameMenu)
    {
        gameMenuSelect = 0;
        clearConsole();
        printf("ROCK PAPER SCISSORS\n1. Play\n2. Print result list\n3. Return to main menu\n");
        printf("Select: ");
        scanf(" %d", &gameMenuSelect);

        switch(gameMenuSelect)
        {
            case 1:
                gameMain();
                break;

            case 2:
                printResults();
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

void printResults()
{
    int lose = 0;
    int win = 0;
    int draw = 0;
    int total = 0;
    float winPercents = 0;
    Game gameFromFile;

    clearConsole();

    FILE *resultFile = fopen("results.rps", "rb");
    if (resultFile == NULL)
    {
        printf("File error, definitely crashing now.\n");
        hitEnter();
        exit(1);
    }

    while(fread(&gameFromFile, sizeof(Game), 1, resultFile) == 1)
    {
        if(gameFromFile.gameResult == 0)
        {
            lose++;
        }
        if(gameFromFile.gameResult == 1)
        {
            draw++;
        }
        if(gameFromFile.gameResult == 2)
        {
            win++;
        }
    }
    fclose(resultFile);

    total = lose + win + draw;
    
    if(total == 0)
    {
        printf("You have not played any games yet.\nPress enter to continue.\n");
    }

    else
    {
        winPercents = ((float)win / (float)total) * 100;
        printf("You have played %d games\n%d wins\n%d losses\n%d draws\nYou have won %.0f%% of your games.\nPress enter to continue.\n", total, win, lose, draw, winPercents);
    }

    hitEnter();

}