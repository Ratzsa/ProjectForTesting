#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "systemfunctions.h"
#include "gamecode.h"

void gameResult(const int player, const int computer);
void printHand(const int choice);
void saveResult(const int result);
int gameMechanics(const int player, const int computer);

enum resultList { LOSE, DRAW, WIN };

const char rock[] = "    _______\n---'   ____)\n      (_____)\n      (_____)\n      (____)\n---.__(___)";
const char paper[] = "    _______\n---'   ____)____\n          ______)\n          _______)\n         _______)\n---.__________)";
const char scissors[] = "    _______\n---'   ____)____\n          ______)\n       __________)\n      (____)\n---.__(___)";

void gameMain()
{
    srand(time(0));
    bool gameRunning = true;
    bool gameContinue = true;
    int playerSelection;
    int computerSelection;
    
    while(gameRunning)
    {
        clearConsole();
        gameContinue = true;
        playerSelection = 0;
        printf("ROCK PAPER SCISSORS\nChoose your hand!\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");
        printf("Choice: ");
        scanf(" %d", &playerSelection);

        computerSelection = rand() % 3 + 1;

        if(playerSelection > 3 || playerSelection < 1)
        {
            printf("Incorrect input. Game will not count.\nPress enter to continue.\n");
            hitEnter();
        }
        else
        {
            gameResult(playerSelection, computerSelection);
        }
        playerSelection = 0;

        while(gameContinue)
        {
            clearConsole();
            printf("Press 1 to play again, 2 to quit.\n");
            printf("Choice: ");
            scanf(" %d", &playerSelection);

            switch(playerSelection)
            {
                case 1:
                    gameContinue = false;
                    break;

                case 2:
                    gameContinue = false;
                    gameRunning = false;
                    break;

                default:
                    printf("Incorrect input. Press enter to continue.\n");
                    hitEnter();
                    break;
            }
        }        
    }
}

int gameMechanics(const int player, const int computer)
{
    int result[][3] =  {{ DRAW, WIN, LOSE},
                        { LOSE, DRAW, WIN},
                        { WIN, LOSE, DRAW}};
    return result[computer - 1][player - 1];
}

void gameResult(const int player, const int computer)
{
    
    int score = gameMechanics(player, computer);

    printf("\nComputer played\n");
    printHand(computer);
    printf("\nYou played\n");
    printHand(player);

    if(score == WIN)
    {
        
        printf("\nYou win! Press enter to continue.\n");
        hitEnter();
    }
    else if(score == DRAW)
    {
        printf("\nIt's a draw! Press enter to continue.\n");
        hitEnter();
    }
    else
    {
        printf("\nYou lose! Press enter to continue.\n");
        hitEnter();
    }
    saveResult(score);
}

void printHand(const int choice)
{
    if(choice == 1)
    {
        printf(rock);
        printf("\n");
    }
    if(choice == 2)
    {
        printf(paper);
        printf("\n");
    }
    if(choice == 3)
    {
        printf(scissors);
        printf("\n");
    }
}

void saveResult(const int result)
{
    FILE *resultFile = fopen("results.rps", "ab");
    if(resultFile == NULL)
    {
        printf("File error.\n");
        exit(1);
    }
    Game toFile;
    toFile.gameResult = result;
    toFile.dateAdded = time(0);
    fwrite(&toFile, sizeof(Game), 1, resultFile);
    fclose(resultFile);
}