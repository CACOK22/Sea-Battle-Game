#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "errors.h"

void iSP()
{
    system("cls");
    printf("ERROR. Invalid ship Placement\n");
    getchar();
}

void iC()
{
    system("cls");
    printf("ERROR. Invalid Character\n");
    getchar();
}

void nETTS()
{
    system("cls");
    printf("ERROR. Not enough that type ships\n");
    getchar();
}


void nS()
{
    system("cls");
    printf("ERROR. Nothing selected\n");
    getchar();
}