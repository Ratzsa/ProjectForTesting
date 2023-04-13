#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include "checkinputs.h"
#include "systemfunctions.h"

void calculator()
{
    float firstNum;
    float secondNum;
    bool calculatorNum;
    char calculatorInput[50];
    char operator;

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

    switch(operator)
    {
        case '+':
            printf("%.2f + %.2f = %.2f\nPress enter to continue.\n", firstNum, secondNum, firstNum + secondNum);
            hitEnter();
            return;

        case '-':
            printf("%.2f - %.2f = %.2f\nPress enter to continue.\n", firstNum, secondNum, firstNum - secondNum);
            hitEnter();
            return;

        case '*':
            printf("%.2f * %.2f = %.2f\nPress enter to continue.\n", firstNum, secondNum, firstNum * secondNum);
            hitEnter();
            return;

        case '/':
            printf("%.2f / %.2f = %.2f\nPress enter to continue.\n", firstNum, secondNum, firstNum / secondNum);
            hitEnter();
            return;

        case '%':
            printf("%d %% %d = %.2d\nPress enter to continue.\n", (int)firstNum, (int)secondNum, (int)firstNum % (int)secondNum);
            hitEnter();
            return;

        default:
            printf("Incorrect input. Press enter to continue.\n");
            hitEnter();
            return;
    }    
}