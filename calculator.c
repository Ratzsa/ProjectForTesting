#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "checkinputs.h"
#include "systemfunctions.h"

float calculation(float a, float b, char op);

void calculator()
{
    float firstNum;
    float secondNum;
    float result;
    bool calculatorNum;
    char calculatorInput[50];
    char operator;
    char opCheck[5] = "";

    clearConsole();

    printf("Enter the first number: ");
    scanf(" %s", calculatorInput);
    calculatorNum = checkInputs(calculatorInput);
    if(!calculatorNum)
    {
        return;
    }
    firstNum = atof(calculatorInput);
    clearInput();

    printf("Enter the second number: ");
    scanf(" %s", calculatorInput);
    calculatorNum = checkInputs(calculatorInput);
    if(!calculatorNum)
    {
        return;
    }
    secondNum = atof(calculatorInput);
    clearInput();

    printf("Select mathematical operator\nAddition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nModulus (%%)\n");
    scanf(" %s", calculatorInput);
    operator = operatorCheck(calculatorInput);

    /*
    TODO
    Fixa så man inte kan dela med 0.
    Fixa även så man inte kan x % 0 för det blir också skit.
    Försök även fixa 0 / 0.    
    */
    strncat(opCheck, &operator, 1);
    if((secondNum >= 0.000001 && secondNum <= -0.000001) && strcmp(opCheck, "/") == 0)
    {
        printf("Error: Can not divide by zero.\nPress enter to continue.\n");
        hitEnter();
        return;
    }

    result = calculation(firstNum, secondNum, operator);

    printf("%f %c %f = %.2f\nPress enter to continue.\n", firstNum, operator, secondNum, result);     
}

float calculation(float firstNum, float secondNum, char op)
{
    switch(op)
    {
        case '+':
            return(firstNum + secondNum);
            break;

        case '-':
            return(firstNum - secondNum);
            break;

        case '*':
            return(firstNum * secondNum);
            break;

        case '/':
            return(firstNum / secondNum);
            break;

        case '%':
            return((int)firstNum % (int)secondNum);
            break;

        default:
            printf("This should never happen!\n");
            exit(1);
    }   
}