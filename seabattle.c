#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "logicfunctions.h"
#include "menuprint.h"
#include "errors.h"



int main()
{
    char selectionButton = '1';
    while (selectionButton!='0')
    {
        system("cls");
        char yourField[10][10];
        fillWithWater(yourField[0]);
        int freeShips[10]={4,3,3,2,2,2,1,1,1,1};
        drawMenu();
        selectionButton = getch();
        if (selectionButton=='1')
        {
            while (selectionButton!='0')
            {
                drawNewGameMenu();          
                selectionButton = getch();
                if (selectionButton=='1')
                {
                    
                    fillWithWater(yourField[0]);
                    drawConstructionMenu(yourField,freeShips);
                    while(selectionButton!='0')
                    {
                        
                        selectionButton=getch();
                        if (selectionButton=='1')
                        {
                            drawDeckerChoiceMenu(yourField,freeShips);
                            char letter,number;
                            selectionButton = getch();
                            if (selectionButton == '1')
                            {
                                if (isThere(freeShips,1)==1)
                                {
                                    askTheAdress(yourField,freeShips);
                                    scanf(" %c %c",&letter,&number);
                                    getchar();
                                    if ((isCorrectInput(letter)==1)&&(isCorrectInput(number)==1))
                                    {
                                        if (isOkToPlace(letter,number,1,yourField,1)==1)
                                        {
                                            putShip(letter,number,1,yourField[0],1);
                                            removeShip(&freeShips,1);
                                            printf("Adding 1 decker to %c%c",letter,number);
                                            getchar();
                                        }
                                        else    iSP();
                                    }
                                    else    iC();
                                }
                                else    nETTS();
                            }
                            else if (selectionButton == '2')
                            {
                                if (isThere(freeShips,2)==1)
                                {
                                    askTheAdress(yourField,freeShips);
                                    scanf(" %c %c",&letter,&number);
                                    getchar();
                                    if ((isCorrectInput(letter)==1)&&(isCorrectInput(number)==1))
                                    {
                                        verticalOrHorizontal();
                                        selectionButton = getchar();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,2,yourField,1)==1)
                                            {
                                                putShip(letter,number,2,yourField[0],1);
                                                removeShip(&freeShips,2);
                                                printf("Adding 2 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,2,yourField,2)==1)
                                            {
                                                putShip(letter,number,2,yourField[0],2);
                                                removeShip(&freeShips,2);
                                                printf("Adding 2 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                    }
                                    else    iC();
                                }
                                else    nETTS();
                            }
                            else if (selectionButton == '3')
                            {
                                if (isThere(freeShips,3)==1)
                                {
                                    askTheAdress(yourField,freeShips);
                                    scanf(" %c %c",&letter,&number);
                                    getchar();
                                    if ((isCorrectInput(letter)==1)&&(isCorrectInput(number)==1))
                                    {
                                        verticalOrHorizontal();
                                        selectionButton = getchar();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,3,yourField,1)==1)
                                            {
                                                putShip(letter,number,3,yourField[0],1);
                                                removeShip(&freeShips,3);
                                                printf("Adding 3 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,3,yourField,2)==1)
                                            {
                                                putShip(letter,number,3,yourField[0],2);
                                                removeShip(&freeShips,3);
                                                printf("Adding 3 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                    }
                                    else    iC();
                                }
                                else    nETTS();
                            }
                            else if (selectionButton == '4')
                            {
                                if (isThere(freeShips,4)==1)
                                {
                                    askTheAdress(yourField,freeShips);
                                    scanf(" %c %c",&letter,&number);
                                    getchar();
                                    if ((isCorrectInput(letter)==1)&&(isCorrectInput(number)==1))
                                    {
                                        verticalOrHorizontal();
                                        selectionButton = getchar();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,4,yourField,1)==1)
                                            {
                                                putShip(letter,number,4,yourField[0],1);
                                                removeShip(&freeShips,4);
                                                printf("Adding 4 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,4,yourField,2)==1)
                                            {
                                                putShip(letter,number,4,yourField[0],2);
                                                removeShip(&freeShips,4);
                                                printf("Adding 4 decker to %c%c",letter,number);
                                                getchar();
                                            }
                                            else    iSP();
                                        }
                                    }
                                    else    iC();
                                }
                                else    nETTS();
                            }
                            else nS();
                        }
                        else if (selectionButton=='2')
                        {
                            system("cls");
                            printf("nothing there...\n");
                            getch();
                        }
                        else if ((selectionButton=='3')&&(isReady(freeShips)==1))
                        {
                            system("cls");
                            printField(yourField);
                            char enemieField[10][10];
                            fillWithWater(enemieField[0]);
                            generateRandomField(enemieField[0]);
                            printField(enemieField);
                            getch();
                        }
                    }
                    selectionButton = '1';
                }
                else if (selectionButton=='2')
                {
                    generateRandomField(yourField[0]);
                    while(selectionButton!='0')
                    {
                        generatedFieldMenu(yourField);
                        selectionButton=getch();
                        if (selectionButton=='1')
                        {
                            fillWithWater(yourField[0]);
                            generateRandomField(yourField[0]);
                        }
                        if (selectionButton=='2')
                        {
                            selectionButton='0';
                        }
                        if (selectionButton=='3')
                        {
                            while(selectionButton!='0')
                            {
                                saveChoiceMenu();
                                selectionButton=getch();
                                if (selectionButton=='1') fieldSave1(yourField);
                                if (selectionButton=='2') fieldSave2(yourField);
                                if (selectionButton=='3') fieldSave3(yourField);   
                            }
                        }
                    }
                }
                else if (selectionButton=='3')
                {
                    char yourField[10][10];
                    fillWithWater(yourField[0]);
                    while(selectionButton!='0')
                    {
                        loadFileMenu();
                        selectionButton=getch();
                        if (selectionButton=='1') loadFile1(yourField[0]);
                        if (selectionButton=='2') loadFile2(yourField[0]);
                        if (selectionButton=='3') loadFile3(yourField[0]);
                        selectionButton='0';
                    }
                }
            }
            
            system("cls");
            printField(yourField);
            printf("1. Start game\n");
            printf("0. Back\n");
            selectionButton = getch();
            if(selectionButton=='1')
            {
                int gameOver = 0;
                char lettershot,numbershot;
                char enemyField[10][10];
                fillWithWater(enemyField[0]);
                generateRandomField(enemyField[0]);
                while (gameOver!=1)
                {
                    system("cls");
                    printf("----YOUR FIELD----");
                    printField(yourField);
                    printf("---ENEMY FIELD---");
                    printEncryptedEnemyField(enemyField);
                    printf("Selecft Field to shoot: \n");
                    scanf(" %c %c",&lettershot,&numbershot);
                    getchar();
                    if ((isCorrectInput(lettershot)==1)&&(isCorrectInput(numbershot)==1))
                        {
                            if (checkShot(enemyField,lettershot,numbershot)==1)
                            {
                                commitShot(enemyField[0],lettershot,numbershot);
                                enemyShoots(yourField[0]);
                            }
                            else 
                            {
                                printf("This spot was alredy shot!\n");
                                getchar();
                            }
                        }
                    if ((isAlive(yourField)==0)||(isAlive(enemyField)==0))
                    {
                        system("cls");
                        printf("GAME OVER\n");
                        getchar();
                        gameOver = 1;
                    }
                }
            }

        }
        else if (selectionButton=='2')
        {
            system("cls");
            printf("Loading game\n");
            getch();
        }
        else if (selectionButton=='3')
        {
            system("cls");
            printf("Settings\n");
            getch();
        }

        
    }
    
    return 0;
}