#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "systemfunctions.h"

bool checkInputs(char input[])
{
    for(int i = 0; i < strlen(input); i++)
    {
        if(isalpha(input[i]))
        {
            printf("Incorrect input. Press enter to continue.\n");
            hitEnter();
            return false;
        }
        if(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%')
        {
            printf("Incorrect input. Press enter to continue.\n");
            hitEnter();
            return false;
        }
    }
    return true;
}

char operatorCheck(char input[])
{
    char returnChar = 'a';
    if(strlen(input) > 1)
    {
        return returnChar;
    }

    if(input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/' || input[0] == '%')
    {
        return input[0];
    }

    return returnChar;
}