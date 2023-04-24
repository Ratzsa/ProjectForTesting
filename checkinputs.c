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
            return false;
        }
        if(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%' || input[i] == '\\')
        {
            return false;
        }
    }
    return true;
}

bool checkCalculatorInputs(char input[])
{
    for(int i = 0; i < strlen(input); i++)
    {
        if(isalpha(input[i]))
        {
            return false;
        }
        if(input[i] == '/' || input[i] == '*' || input[i] == '%' || input[i] == '\\')
        {
            return false;
        }
        if((i > 0 && input[i] == '+') || (i > 0 && input[i] == '-'))
        {
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