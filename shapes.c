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
float rectangleCircum(const float a, const float b);
float rectangleArea(const float a, const float b);
float circleCircum(const float r);
float circleArea(const float r);
float triangleCircum(const float a, const float b, const float c);
float triangleArea(const float a, const float b);
float parallelogramCircum(const float a, const float b);
float parallelogramArea(const float b, const float h);

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
            printf("Incorrect input. Press enter to continue.\n");
            hitEnter();
            return;
        }
        sideA = atof(rectangleInput);

        printf("Enter side b: ");
        scanf(" %s", rectangleInput);
        isRectangleNum = checkInputs(rectangleInput);
        if(!isRectangleNum)
        {
            printf("Incorrect input. Press enter to continue.\n");
            hitEnter();
            return;
        }
        sideB = atof(rectangleInput);
        
        circumference = rectangleCircum(sideA, sideB);
        area = rectangleArea(sideA, sideB);

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
    float circumference;
    float area;
    char triangleInput[50];
    bool isTriangleNum;

    clearConsole();
    printf(" |\\\n | \\\na|  \\ c\n |   \\\n |____\\\n    b\n");
    printf("Enter a: ");
    scanf(" %s", triangleInput);
    isTriangleNum = checkInputs(triangleInput);
    if(!isTriangleNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    sideA = atof(triangleInput);

    printf("Enter b: ");
    scanf(" %s", triangleInput);
    isTriangleNum = checkInputs(triangleInput);
    if(!isTriangleNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    sideB = atof(triangleInput);

    sideC = sqrt((sideA * sideA) + (sideB * sideB));

    area = triangleArea(sideA, sideB);
    circumference = triangleCircum(sideA, sideB, sideC);    

    printf("Triangle circumference: %.2f\nArea: %.2f\nSide c: %.2f\nPress enter to continue.\n", circumference, area, sideC);

    hitEnter();
}

void circle()
{
    float radius;
    float circumference;
    float area;
    char circleInput[50];
    bool isCircleNum;

    clearConsole();
    printf("    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x\n   CIRCLE\n");
    printf("Enter radius: ");
    scanf(" %s", circleInput);

    isCircleNum = checkInputs(circleInput);
    if(!isCircleNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    radius = atof(circleInput);

    circumference = circleCircum(radius);
    area = circleArea(radius);

    clearConsole();
    printf("    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x\n   CIRCLE\n");
    printf("Circle radius: %.2f\nDiameter: %.2f\n", radius, radius * 2);
    printf("Circumference: %.2f\nArea: %.2f\nPress enter to continue.\n", circumference, area);

    hitEnter();
    return;
}

void parallelogram()
{
    float sideA;
    float sideB;
    float height;
    float circumference;
    float area;
    char parallelogramInput[50];
    bool isParallelogramNum;

    clearConsole();
    printf("    ________\n   /|       /\n  / | h    / a\n /  |     /\n/___|____/\n     b\n");

    printf("Enter a: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    sideA = atof(parallelogramInput);

    printf("Enter b: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    sideB = atof(parallelogramInput);

    printf("Enter h: ");
    scanf(" %s", parallelogramInput);
    isParallelogramNum = checkInputs(parallelogramInput);
    if(!isParallelogramNum)
    {
        printf("Incorrect input. Press enter to continue.\n");
        hitEnter();
        return;
    }
    height = atof(parallelogramInput);

    circumference = parallelogramCircum(sideA, sideB);
    area = parallelogramArea(sideB, height);

    printf("Parallelogram circumference: %.2f\nArea: %.2f\nPress enter to contine.\n", circumference, area);

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

float rectangleCircum(const float a, const float b)
{
    return (a + b) * 2;
}

float rectangleArea(const float a, const float b)
{
    return a * b;
}

float triangleCircum(const float a, const float b, const float c)
{
    return a + b + c;
}

float triangleArea(const float a, const float b)
{
    return (a * b) / 2;
}

float circleCircum(const float r)
{
    return 2 * PI * r;
}

float circleArea(const float r)
{
    return PI * (r * r);
}

float parallelogramCircum(const float a, const float b)
{
    return (a + b) * 2;
}

float parallelogramArea(const float b, const float h)
{
    return b * h;
}