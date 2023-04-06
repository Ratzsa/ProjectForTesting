#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "systemfunctions.h"

const char rock[] = "    _______\n---'   ____)\n      (_____)\n      (_____)\n      (____)\n---.__(___)";
const char paper[] = "    _______\n---'   ____)____\n          ______)\n          _______)\n         _______)\n---.__________)";
const char scissors[] = "    _______\n---'   ____)____\n          ______)\n       __________)\n      (____)\n---.__(___)";

void gameMain()
{
    srand(time(0));
    bool gameRunning = true;
    int gameSelection;

    while(gameRunning)
    {
        printf("ROCK PAPER SCISSORS\nChoose your hand!\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");
        printf("Choice: ");
        scanf(" %d", &gameSelection);
    }


}