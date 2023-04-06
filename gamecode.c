#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "systemfunctions.h"

void gameResult(int player, int computer);
void printHand(int choice);

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
            printf("Incorrect input. You lose!\n");
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

void gameResult(const int player, const int computer)
{
    int result[][3] =  {{ 1, 2, 0},
                        { 0, 1, 2},
                        { 2, 0, 1}};
    int score = result[computer - 1][player - 1];

    if(score == 2)
    {
        printf("\nComputer played\n");
        printHand(computer);
        printf("You played\n");
        printHand(player);
        printf("\nYou win! Press enter to continue.\n");
        hitEnter();
    }
    else if(score == 1)
    {
        printf("\nComputer played\n");
        printHand(computer);
        printf("You played\n");
        printHand(player);
        printf("\nIt's a draw! Press enter to continue.\n");
        hitEnter();
    }
    else
    {
        printf("\nComputer played\n");
        printHand(computer);
        printf("You played\n");
        printHand(player);
        printf("\nYou lose! Press enter to continue.\n");
        hitEnter();
    }
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