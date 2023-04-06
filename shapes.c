#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "systemfunctions.h"
#include "checkinputs.h"

const float PI = 3.1415926535;

void rectangle();
void triangle();
void circle();
void parallelogram();

void shapesMain()
{
    bool inShapesMenu = true;
    int shapesMenuSelect;
    while(inShapesMenu)
    {
        shapesMenuSelect = 0;
        clearConsole();
        printf("Shapes Menu\nSelect a shape to calculate\n");
        printf("1. Rectangle\n");
        printf("2. Triangle\n");
        printf("3. Circle\n");
        printf("4. Parallelogram\n");
        printf("5. Return to main menu\n");
        printf("Option: ");
        scanf(" %d", &shapesMenuSelect);

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
        printf("Circumference: %.2f\nArea: %.2f\nPress enter to continue.", circumference, area);
        inRectangleMenu = false;
        hitEnter();
    }
    return;
}

void triangle()
{
    clearConsole();
    printf("TRIANGLE!\n");
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
    printf("Circle radius: %.2f\nCircle diameter: %.2f\n", circleRadius, circleRadius * 2);
    printf("Circumference: %.2f\nArea: %.2f\nPress enter to continue.\n", circleCircumference, circleArea);

    hitEnter();
    return;
}

void parallelogram()
{
    clearConsole();
    printf("PARALLELOGRAM!\n");
    hitEnter();
}