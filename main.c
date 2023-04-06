#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "systemfunctions.h"
#include "shapes.h"
#include "calculator.h"
#include "gamecode.h"

int main()
{
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
        printf("Option: ");
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
                gameMain();
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