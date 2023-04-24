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
    char operator = ' ';

    clearConsole();

    printf("Enter the first number: ");
    scanf(" %s", calculatorInput);
    calculatorNum = checkCalculatorInputs(calculatorInput);
    if(!calculatorNum)
    {
        return;
    }
    firstNum = atof(calculatorInput);
    clearInput();

    printf("Enter the second number: ");
    scanf(" %s", calculatorInput);
    calculatorNum = checkCalculatorInputs(calculatorInput);
    if(!calculatorNum)
    {
        return;
    }
    secondNum = atof(calculatorInput);
    clearInput();

    printf("Select mathematical operator\nAddition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nModulus (%%)\n");
    scanf(" %s", calculatorInput);
    operator = operatorCheck(calculatorInput);

    if(secondNum == 0.000000 && operator == '/')
    {
        printf("Error: Can not divide by zero.\nPress enter to continue.\n");
        hitEnter();
        return;
    }

    if(secondNum == 0.000000 && operator == '%')
    {
        printf("Error: Can not modulus by zero.\nPress enter to continue.\n");
        hitEnter();
        return;
    }

    if(firstNum == 0.000000 && secondNum == 0.000000)
    {
        printf("That is 0. Absolute zero. No matter what you are trying to do with those numbers, they will always be nothing.\nPress enter to continue.\n");
        hitEnter();
        return;
    }

    result = calculation(firstNum, secondNum, operator);
    printf("%.2f %c %.2f = %.2f\nPress enter to continue.\n", firstNum, operator, secondNum, result);
    hitEnter();     
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