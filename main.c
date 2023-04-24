#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "systemfunctions.h"
#include "shapes.h"
#include "calculator.h"
#include "gamemenu.h"
#include "gamecode.h"

int main()
{
    // För att säkerställa att resultatfilen funkar.
    FILE *temp = fopen("results.rps", "rb");
    if(temp == NULL)
    {
        fclose(temp);
        temp = fopen("results.rps", "wb");
        fclose(temp);
    }
    if(temp == NULL)
    {
        printf("File error. Crashing to OS.\n");
        exit(1);
    }

    bool programIsRunning = true;
    int mainMenuSelect;
    while(programIsRunning)
    {
        mainMenuSelect = 0;
        clearConsole();
        printf("Main Menu\nSelect an option\n");
        printf("1. Shapes\n");
        printf("2. Calculator\n");
        printf("3. Rock-Paper-Scissors\n");
        printf("5. Exit\n");
        printf("Select: ");
        scanf(" %d", &mainMenuSelect);

        switch(mainMenuSelect)
        {
            case 1:
                shapesMain();
                break;

            case 2:
                calculator();
                break;

            case 3:
                gameMenu();
                break;

            case 5:
                printf("Exiting program\n");
                exit(1);
                break;

            default:
                printf("Incorrect input. Press enter to continue.\n");
                hitEnter();
                break;
        }
    }
    return 0;
}