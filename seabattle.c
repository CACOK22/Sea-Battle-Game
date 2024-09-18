//bruh
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "logicfunctions.h"
#include "menuprint.h"
#include "errors.h"

int bD = 0;

int main()
{
    char selectionButton = '1';
    while (selectionButton!='0')
    {
        system("cls");
        char yourField[10][10];
        fillWithWater(yourField[0]);
        int refresh[10]={4,3,3,2,2,2,1,1,1,1};
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
                    
                    while(selectionButton!='0')
                    {
                        drawConstructionMenu(yourField,freeShips);
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
                                        selectionButton = getch();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,2,yourField,1)==1)
                                            {
                                                putShip(letter,number,2,yourField[0],1);
                                                removeShip(&freeShips,2);
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,2,yourField,2)==1)
                                            {
                                                putShip(letter,number,2,yourField[0],2);
                                                removeShip(&freeShips,2);
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
                                        selectionButton = getch();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,3,yourField,1)==1)
                                            {
                                                putShip(letter,number,3,yourField[0],1);
                                                removeShip(&freeShips,3);
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,3,yourField,2)==1)
                                            {
                                                putShip(letter,number,3,yourField[0],2);
                                                removeShip(&freeShips,3);
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
                                        selectionButton = getch();
                                        if (selectionButton == '1')
                                        {
                                            if (isOkToPlace(letter,number,4,yourField,1)==1)
                                            {
                                                putShip(letter,number,4,yourField[0],1);
                                                removeShip(&freeShips,4);
                                            }
                                            else    iSP();
                                        }
                                        else if (selectionButton=='2')
                                        {
                                            if (isOkToPlace(letter,number,4,yourField,2)==1)
                                            {
                                                putShip(letter,number,4,yourField[0],2);
                                                removeShip(&freeShips,4);
                                            }
                                            else    iSP();
                                        }
                                    }
                                    else    iC();
                                }
                                else    nETTS();
                            }
                            //else nS();
                            if (selectionButton!='0') selectionButton = '1';
                        }
                        else if (selectionButton=='2')
                        {
                            system("cls");
                            printf("nothing there...\n");
                            getch();
                        }
                        else if ((selectionButton=='0')&&(isReady(freeShips)!=1))
                        {
                            system("cls");
                            printf("Your field is not complete. If you leave it will not be saved.\n");
                            printf("Are you sure you want to exit?\n");
                            printf("1. No\n");
                            printf("0. Yes\n");
                            selectionButton = getch();
                            if (selectionButton=='0')
                            {
                                fillWithWater(yourField[0]);
                                for (int i=0; i<10; i++) freeShips[i] = refresh[i];
                            }
                        }
                    }
                }
                else if (selectionButton=='2')
                {
                    generateRandomField(yourField[0]);
                    for (int i=0; i<10; i++) freeShips[i]=0;
                    while(selectionButton!='0')
                    {
                        generatedFieldMenu(yourField);
                        selectionButton=getch();
                        if (selectionButton=='1')
                        {
                            fillWithWater(yourField[0]);
                            generateRandomField(yourField[0]);
                        }
                        else if (selectionButton=='2')
                        {
                            selectionButton='0';
                        }
                        else if (selectionButton=='3')
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
                        else if (selectionButton=='0')
                        {
                            fillWithWater(yourField[0]);
                            for (int i=0; i<10; i++) freeShips[i]=refresh[i];
                        }
                    }
                }
                else if (selectionButton=='3')
                {
                    while(selectionButton!='0')
                    {
                        loadFileMenu();
                        selectionButton=getch();
                        if (selectionButton=='1') loadFile1(yourField[0]);
                        if (selectionButton=='2') loadFile2(yourField[0]);
                        if (selectionButton=='3') loadFile3(yourField[0]);
                        selectionButton='0';
                    }
                    system("cls");
                    printf("---LOADED FIELD---\n");
                    printField(yourField);
                    for (int i=0; i<10; i++) freeShips[i] = 0;
                    printf("1. Continue\n");
                    printf("0. Back\n");
                    selectionButton=getch();
                    if (selectionButton=='0')
                    {
                        fillWithWater(yourField[0]);
                        for (int i=0; i<10; i++) freeShips[i] = refresh[i];
                    }
                    else selectionButton='0';
                }
            }
            
            if (isReady(freeShips)==1)
            {
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
                    int eLS=0;
                    int lsx,lsy,lssx,lssy;
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
                                    int check;
                                    check = commitShot(enemyField[0],lettershot,numbershot);
                                    if (check==0) 
                                    {
                                        eLS=1;
                                        while(eLS==1) 
                                        {
                                            eLS=enemyShoots(yourField[0],&lsx,&lsy,&lssx,&lssy); 
                                            getchar();
                                        } 
                                    }
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
            
            selectionButton='1';
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
            printf("1. Set bot difficulty to 1\n");
            printf("2. Set bot difficulty to 2\n");
            printf("0. Back\n");
            selectionButton=getch();
            if (selectionButton=='1')
            {
                bD = 0;
                system("cls");
                printf("success!\n");
                getchar();
            }
            else if (selectionButton=='2')
            {
                bD = 1;
                system("cls");
                printf("success!\n");
                getchar();
            }
        }
        
    }
    
    return 0;
}