#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#endif

void clearInput();

void hitEnter()
{
    clearInput();
    clearInput();
}

void clearConsole()
{
    #ifdef _WIN32
        system("cls");
    #elif __APPLE__
        printf("\x1b[H\x1b[2J\x1b[3J");
    #elif __linux__
        printf("\x1b[H\x1b[2J\x1b[3J");
    #elif __unix__
        printf("\x1b[H\x1b[2J\x1b[3J");
    else
        printf("\x1b[H\x1b[2J\x1b[3J");
    #endif
}

void clearInput()
{
    while(getchar() != '\n')
    {

    }
}

void redColour() 
{
    printf("\033[1;31m");
}

void resetColour() 
{
    printf("\033[0m");
}

void greenColour()
{
    printf("\033[0;32m");
}