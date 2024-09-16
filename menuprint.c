#include <stdio.h>
#include <stdlib.h>
#include "menuprint.h"
#include "logicfunctions.h"

void drawWithNotice(char field[10][10], int ships[10])
{
    printf("\n");
    printf("  1234567890\n");
    for (int i=0; i<10; i++)
    {
        printf("%c ",numberToLetter(i));
        for(int j=0; j<10; j++)
        {
            printf("%c",field[i][j]);
        }
        if (ships[i]==4)
        {
            printf("     0000 - 4 Decker\n");
        }
        else if (ships[i]==3)
        {
            printf("      000 - 3 Decker\n");
        }
        else if (ships[i]==2)
        {
            printf("       00 - 2 Decker\n");
        }
        else if (ships[i]==1)
        {
            printf("        0 - 1 Decker\n");
        }        
        else printf("\n");
    }

}

void printField(char field[10][10])
{
    printf("\n");
    printf("  1234567890\n");
    for (int i=0; i<10; i++)
    {
        printf("%c ",numberToLetter(i));
        for(int j=0; j<10; j++)
        {
            printf("%c",field[i][j]);
        }      
        printf("\n");
    }
}

void drawMenu()
{
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Settings\n");
    printf("0. Exit\n");

}

void drawNewGameMenu()
{
    system("cls");
    printf("1. Construct your field\n");
    printf("2. Generate your field\n");
    printf("3. Load your field\n");
    printf("0. Back\n");
}

void drawConstructionMenu(char yourField[10][10],int freeShips[10])
{
    system("cls");
    drawWithNotice(yourField,freeShips);
    printf("1. Add Ship\n");
    printf("2. Remove Ship\n");
    if (isReady(freeShips)==1)
        printf("3. Start Game\n");
    printf("0. Back");
}

void drawDeckerChoiceMenu(char yourField[10][10],int freeShips[10])
{
    system("cls");
    drawWithNotice(yourField,freeShips);
    printf("1. Add 1 Decker\n");
    printf("2. Add 2 Decker\n");
    printf("3. Add 3 Decker\n");
    printf("4. Add 4 Decker\n");
    printf("0. Back\n");
}

void saveChoiceMenu()
{
    system("cls");
    printf("1. Save Field1\n");
    printf("2. Save Field2\n");
    printf("3. Save Field3\n");
    printf("0. Back\n");
}

void loadFileMenu()
{
    system("cls");
    printf("1. Load savedField1\n");
    printf("2. Load savedField2\n");
    printf("3. Load savedField3\n");
    printf("0. Back\n");
}

void generatedFieldMenu(char yourField[10][10])
{
    system("cls");
    printField(yourField);
    printf("1. Generate different field\n");
    printf("2. Start game\n");
    printf("3. Save that field\n");
    printf("0. Back\n");
}

void askTheAdress(char field[10][10],int freeShips[10])
{
    system("cls");
    drawWithNotice(field,freeShips);
    printf("Type the field name in format LETTERNUMBER (e.g. A5): \n");
}

void verticalOrHorizontal()
{
    printf("You want to put it vertical or horizontal?\n");
    printf("1. Vertical\n");
    printf("2. Horizontal\n");
}