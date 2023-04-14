#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "systemfunctions.h"
#include "checkinputs.h"

const float PI = 3.1415926535;

void rectangle();
void triangle();
void circle();
void parallelogram();
int menuSelectionConvert(char text[]);

void shapesMain()
{
    clearInput();
    char menuInput[20];
    bool inShapesMenu = true;
    int shapesMenuSelect;
    while(inShapesMenu)
    {
        clearConsole();
        printf("Shapes Menu\nType a shape to calculate\n");
        printf("Rectangle\n");
        printf("Triangle\n");
        printf("Circle\n");
        printf("Parallelogram\n");
        printf("Or type exit to return to main menu\n");
        printf("Option: ");
        scanf(" %s", menuInput);

        shapesMenuSelect = menuSelectionConvert(menuInput); // Kanske vore bättre med en bunt if-satser, men det här funkar som det ska.

        switch(shapesMenuSelect)
        {
            case 1:
                rectangle();
                break;

            case 2:
                triangle();
                break;

            case 3:
                circle();
                break;

            case 4:
                parallelogram();
                break;

            case 5:
                inShapesMenu = false;
                break;
            
            default:
                printf("Incorrect input. Press enter to continue.\n");
                hitEnter();
                break;
        }
    }
}

void rectangle()
{
    float sideA;
    float sideB;
    float circumference;
    float area;
    char rectangleInput[50];
    bool inRectangleMenu = true;
    bool isRectangleNum;
    
    while(inRectangleMenu)
    {
        clearConsole();
        printf(" _______________ \n|               |\n|   RECTANGLE   | b\n|_______________|\n        a\n");
        printf("Enter side a: ");
        scanf(" %s", rectangleInput);
        isRectangleNum = checkInputs(rectangleInput);
        if(!isRectangleNum)
        {
            return;
        }
        sideA = atof(rectangleInput);

        printf("Enter side b: ");
        scanf(" %s", rectangleInput);
        isRectangleNum = checkInputs(rectangleInput);
        if(!isRectangleNum)
        {
            return;
        }
        sideB = atof(rectangleInput);
        
        circumference = (sideA + sideB) * 2;
        area = sideA * sideB;

        clearConsole();
        printf(" _______________ \n|               |\n|   RECTANGLE   | a\n|_______________|\n        b\n");
        printf("Side a: %.2f\nSide b: %.2f\n", sideA, sideB);
        printf("Rectangle circumference: %.2f\nArea: %.2f\nPress enter to continue.", circumference, area);
        inRectangleMenu = false;
        hitEnter();
    }
    return;
}

void triangle()
{
    float sideA;
    float sideB;
    float sideC;
    float triangleCircumference;
    float triangleArea;
    char triangleInput[50];
    bool isTriangleNum;

    clearConsole();
    printf(" |\\\n | \\\na|  \\ c\n |   \\\n |____\\\n    b\n");
    printf("Enter a: ");
    scanf(" %s", triangleInput);
    isTriangleNum = checkInputs(triangleInput);
    if(!isTriangleNum)
    {
        return;
    }
    sideA = atof(triangleInput);

    printf("Enter b: ");
    scanf(" %s", triangleInput);
    isTriangleNum = checkInputs(triangleInput);
    if(!isTriangleNum)
    {
        return;
    }
    sideB = atof(triangleInput);

    sideC = sqrt((sideA * sideA) + (sideB * sideB));

    triangleArea = (sideA * sideB) / 2;
    triangleCircumference = sideA + sideB + sideC;    

    printf("Triangle circumference: %.2f\nArea: %.2f\nSide c: %.2f\nPress enter to continue.\n", triangleCircumference, triangleArea, sideC);

    hitEnter();
}

void circle()
{
    float circleRadius;
    float circleCircumference;
    float circleArea;
    char circleInput[50];
    bool isCircleNum;

    clearConsole();
    printf("    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x\n   CIRCLE\n");
    printf("Enter radius: ");
    scanf(" %s", circleInput);

    isCircleNum = checkInputs(circleInput);
    if(!isCircleNum)
    {
        return;
    }
    circleRadius = atof(circleInput);

    circleCircumference = 2 * PI * circleRadius;
    circleArea = PI * (circleRadius * circleRadius);

    clearConsole();
    printf("    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x\n   CIRCLE\n");
    printf("Circle radius: %.2f\nDiameter: %.2f\n", circleRadius, circleRadius * 2);
    printf("Circumference: %.2f\nArea: %.2f\nPress enter to continue.\n", circleCircumference, circleArea);

    hitEnter();
    return;
}

void parallelogram()
{
    float parallelogramA;
    float parallelogramB;
    float parallelogramH;
    float parallelogramCircumference;
    float parallelogramArea;
    char parallelogramInput[50];
    bool isParallelogramNum;

    clearConsole();
    printf("    ________\n   /|       /\n  / | h    / a\n /  |     /\n/___|____/\n     b\n");

    printf("Enter a: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        return;
    }
    parallelogramA = atof(parallelogramInput);

    printf("Enter b: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        return;
    }
    parallelogramB = atof(parallelogramInput);

    printf("Enter h: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        return;
    }
    parallelogramH = atof(parallelogramInput);

    parallelogramCircumference = (parallelogramA + parallelogramB) * 2;
    parallelogramArea = parallelogramB * parallelogramH;

    printf("Parallelogram circumference: %.2f\nArea: %.2f\nPress enter to contine.\n", parallelogramCircumference, parallelogramArea);

    hitEnter();
}

int menuSelectionConvert(char text[])
{
    for(int i = 0; i < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
    }

    char menuRectangle[] = "rectangle";
    char menuTriangle[] = "triangle";
    char menuCircle[] = "circle";
    char menuParallelogram[] = "parallelogram";
    char menuExit[] = "exit";

    if(strcmp(text, menuRectangle) == 0)
    {
        return 1;
    }

    if(strcmp(text, menuTriangle) == 0)
    {
        return 2;
    }

    if(strcmp(text, menuCircle) == 0)
    {
        return 3;
    }

    if(strcmp(text, menuParallelogram) == 0)
    {
        return 4;
    }

    if(strcmp(text, menuExit) == 0)
    {
        return 5;
    }

    return 0;   
}