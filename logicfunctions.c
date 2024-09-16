#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "logicfunctions.h"
char intNumberToCharNumber (int number)
{
    if (number == 0) return '1';
    if (number == 1) return '2';
    if (number == 2) return '3';
    if (number == 3) return '4';
    if (number == 4) return '5';
    if (number == 5) return '6';
    if (number == 6) return '7';
    if (number == 7) return '8';
    if (number == 8) return '9';
    if (number == 9) return '0';
}
char intNumberToCharLetter (int number)
{
    if (number == 0) return 'A';
    if (number == 1) return 'B';
    if (number == 2) return 'C';
    if (number == 3) return 'D';
    if (number == 4) return 'E';
    if (number == 5) return 'F';
    if (number == 6) return 'G';
    if (number == 7) return 'H';
    if (number == 8) return 'I';
    if (number == 9) return 'J';
}
void generateRandomField(char *field)
{
    int v;
    char x,y;
    char newField[10][10];
    fillWithWater(newField[0]);
    int fieldInsertion[10]={4,3,3,2,2,2,1,1,1,1};
    for (int i=0; i<6; i++)
    {
        int k=0;
        while (k!=1)
        {
            x = intNumberToCharNumber(rand() % 10);
            y = intNumberToCharLetter(rand() % 10);
            v = rand() % 2;
            k = isOkToPlace(y,x,fieldInsertion[i],newField,v+1);
        }
        putShip(y,x,fieldInsertion[i],newField[0],v+1);
    }
    for (int i=6; i<10; i++)
    {
        int k=0;
        while (k!=1)
        {
            x = intNumberToCharNumber(rand() % 10);
            y = intNumberToCharLetter(rand() % 10);
            k = isOkToPlace(y,x,fieldInsertion[i],newField,1);
        }
        putShip(y,x,fieldInsertion[i],newField[0],1);
    }

    for (int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            *(field + i*10 + j) = newField[i][j];
        }
    }

}
int removeShip(int (*field)[10],int number)
{
    for (int i=0; i<10; i++)
        if  ((*field)[i]==number)
        {
            (*field)[i]=0;
            return 1;
        }
    return 0;
}
int numberToNumber (char letter)
{
    if (letter=='1') return 0;
    else if (letter=='2') return 1;
    else if (letter=='3') return 2;
    else if (letter=='4') return 3;
    else if (letter=='5') return 4;
    else if (letter=='6') return 5;
    else if (letter=='7') return 6;
    else if (letter=='8') return 7;
    else if (letter=='9') return 8;
    else if (letter=='0') return 9;
    return 10;
}
int letterToNumber (char letter)
{
    if (letter=='A') return 0;
    else if (letter=='B') return 1;
    else if (letter=='C') return 2;
    else if (letter=='D') return 3;
    else if (letter=='E') return 4;
    else if (letter=='F') return 5;
    else if (letter=='G') return 6;
    else if (letter=='H') return 7;
    else if (letter=='I') return 8;
    else if (letter=='J') return 9;
    return 10;
}
void putShip(char i_letter,char i_number, int length, char *field, int vertical)
{
    int letter = letterToNumber(i_letter);
    int number = numberToNumber(i_number);
    if (vertical==1)
    {
        for (int i=0; i<length; i++)
        {
            *(field + (letter+i)*10 + number) = '*';
        }
    }
    else
    {
        for (int i=0; i<length; i++)
        {
            *(field + letter*10 + (number+i)) = '*';
        }
    }
}
int isOkToPlace(char i_letter, char i_number, int length,char field[10][10],int vertical)
{
    int letter = letterToNumber(i_letter);
    int number = numberToNumber(i_number);
    if (vertical == 1)
    {
        if ((letter+length)>10)
            return 0;
        for (int i=0; i<length; i++)
        {
            if (letter+i == 0)
            {
                if (number == 0)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i+1][number+1]!='`') return 0;
                }
                else if (number == 9)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i+1][number-1]!='`') return 0;
                }
                else
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i+1][number+1]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i+1][number-1]!='`') return 0;
                }
            }
            else if (letter+i == 9)
            {
                if (number == 0)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i-1][number+1]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }
                else if (number == 9)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i-1][number-1]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }
                else
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i-1][number+1]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i-1][number-1]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }
            }
            else
            {
                if (number == 0)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i+1][number+1]!='`') return 0;
                    if (field[letter+i-1][number+1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }
                else if (number == 9)
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i+1][number-1]!='`') return 0;
                    if (field[letter+i-1][number-1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }
                else
                {
                    if (field[letter+i][number]!='`') return 0;
                    if (field[letter+i][number-1]!='`') return 0;
                    if (field[letter+i][number+1]!='`') return 0;
                    if (field[letter+i+1][number-1]!='`') return 0;
                    if (field[letter+i+1][number+1]!='`') return 0;
                    if (field[letter+i-1][number-1]!='`') return 0;
                    if (field[letter+i-1][number+1]!='`') return 0;
                    if (field[letter+i+1][number]!='`') return 0;
                    if (field[letter+i-1][number]!='`') return 0;
                }

            }
        }
        
    }
    else
    {
        if ((number+length)>10)
            return 0;
        for (int i=0; i<length; i++)
        {
            if(number+i==0)
            {
                if (letter==0)
                {
                    if (field[letter][number+i]!='`') return 0; 
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter+1][number+i+1]!='`') return 0;
                }
                else if (letter==9)
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter-1][number+i+1]!='`') return 0;
                }
                else
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter+1][number+i+1]!='`') return 0;
                    if (field[letter-1][number+i+1]!='`') return 0;
                    
                }
            }
            else if(number+i==9)
            {
                if (letter == 0)
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter+1][number+i-1]!='`') return 0;
                }
                else if (letter == 9)
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter-1][number+i-1]!='`') return 0;
                }   
                else          
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter-1][number+i-1]!='`') return 0;
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter+1][number+i-1]!='`') return 0;
                }
            }
            else
            {
                if (letter==0)
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter+1][number+i-1]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter+1][number+i+1]!='`') return 0;
                }
                else if(letter==9)
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter-1][number+i-1]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter-1][number+i+1]!='`') return 0;
                }
                else
                {
                    if (field[letter][number+i]!='`') return 0;
                    if (field[letter+1][number+i]!='`') return 0;
                    if (field[letter][number+i-1]!='`') return 0;
                    if (field[letter+1][number+i-1]!='`') return 0;
                    if (field[letter][number+i+1]!='`') return 0;
                    if (field[letter+1][number+i+1]!='`') return 0;
                    if (field[letter-1][number+i]!='`') return 0;
                    if (field[letter-1][number+i-1]!='`') return 0;
                    if (field[letter-1][number+i+1]!='`') return 0;
                }
            }
        }

    }
    return 1;
}
int isCorrectInput(char symbol)
{
    if ((symbol=='1')||(symbol=='2')||(symbol=='3')||(symbol=='4')||(symbol=='5')||(symbol=='6')||(symbol=='7')||(symbol=='8')||(symbol=='9')||(symbol=='0')||
    (symbol=='A')||(symbol=='B')||(symbol=='C')||(symbol=='D')||(symbol=='E')||(symbol=='F')||(symbol=='G')||(symbol=='H')||(symbol=='I')||(symbol=='J'))
        return 1;
    else return 0;
    return 0;
}
int isThere(int ships[10],int deck)
{
    for (int i=0; i<10; i++)
        if (ships[i]==deck)
            return 1;

    return 0;
}
int isReady(int ships[10])
{
    for(int i=0; i<10; i++)
        if (ships[i]!=0)
            return 0;
    return 1;
}

char numberToLetter(int number)
{
    char symbol='0';
    if (number==0) return 'A';
    if (number==1) return 'B';
    if (number==2) return 'C';
    if (number==3) return 'D';
    if (number==4) return 'E';
    if (number==5) return 'F';
    if (number==6) return 'G';
    if (number==7) return 'H';
    if (number==8) return 'I';
    if (number==9) return 'J';

}

void fillWithWater(char* field)
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            *(field + i*10 + j) = '`';
        }
    }
}
void printEncryptedEnemyField(char field[10][10])
{
    printf("\n");
    printf("  1234567890\n");
    for (int i=0; i<10; i++)
    {
        printf("%c ",numberToLetter(i));
        for(int j=0; j<10; j++)
        {
            if((field[i][j]=='`')||(field[i][j]=='*'))
                printf("/");
            else printf("%c",field[i][j]);
        }      
        printf("\n");
    }
}

void fieldSave1(char yourField[10][10])
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField1.txt","w");
    for(int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            fprintf (fieldSaved,"%c",yourField[i][j]);
    fclose(fieldSaved);
    system("cls");
    printf("Saved succesfully\n");
    getch();
}

void fieldSave2(char yourField[10][10])
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField2.txt","w");
    for(int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            fprintf (fieldSaved,"%c",yourField[i][j]);
    fclose(fieldSaved);
    system("cls");
    printf("Saved succesfully\n");
    getch();
}

void fieldSave3(char yourField[10][10])
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField3.txt","w");
    for(int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            fprintf (fieldSaved,"%c",yourField[i][j]);
    fclose(fieldSaved);
    system("cls");
    printf("Saved succesfully\n");
    getch();
}

void loadFile1(char* field)
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField1.txt","r");
    char inputSymbol;
    int i = 0;
    int j = 0;
    inputSymbol=getc(fieldSaved);
    while(inputSymbol!=EOF)
    {
        *(field + i*10 + j)=inputSymbol;
        inputSymbol=getc(fieldSaved);
        if (j==9) {i++; j=0;}
        else j++;
    }   
    fclose(fieldSaved);
}

void loadFile2(char* field)
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField3.txt","r");
    char inputSymbol;
    int i = 0;
    int j = 0;
    inputSymbol=getc(fieldSaved);
    while(inputSymbol!=EOF)
    {
        *(field + i*10 + j)=inputSymbol;
        inputSymbol=getc(fieldSaved);
        if (j==9) {i++; j=0;}
        else j++;
    }   
    fclose(fieldSaved);
}

void loadFile3(char* field)
{
    FILE * fieldSaved;
    fieldSaved = fopen("data/savedField3.txt","r");
    char inputSymbol;
    int i = 0;
    int j = 0;
    inputSymbol=getc(fieldSaved);
    while(inputSymbol!=EOF)
    {
        *(field + i*10 + j)=inputSymbol;
        inputSymbol=getc(fieldSaved);
        if (j==9) {i++; j=0;}
        else j++;
    }   
    fclose(fieldSaved);
}

int isAlive(char field[10][10])
{
    for (int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if (field[i][j]=='*')
                return 1;
        }
    }
    return 0;
}

int checkShot(char field[10][10],char letter, char number)
{
    int l = letterToNumber(letter);
    int n = numberToNumber(number);
    if ((field[l][n]=='o')||(field[l][n]=='X')) return 0;
    return 1;
}

int commitShot(char* field,char letter,char number)
{
    int i = letterToNumber(letter);
    int j = numberToNumber(number);
    if (*(field + i*10 + j)=='`')
    {
        *(field + i*10 + j)='o';
        return 0;
    }
    else if (*(field + i*10 + j)=='*')
    {
        *(field + i*10 + j)='X';
        return 1;
    }
}

int enemyShoots(char* field)
{
    int i,j;
    i = rand() % 10;
    j = rand() % 10;
    while ((*(field + i*10 + j)=='o')||(*(field + i*10 + j)=='X')) 
    { 
        i = rand() % 10;
        j = rand() % 10;
    }
    if (*(field + i*10 + j)=='`')
        {
            *(field + i*10 + j)='o';
            printf("Enemie MISSES %d %d\n",i,j);
            return 0;
        }
    else if (*(field + i*10 + j)=='*')
        {
            *(field + i*10 + j)='X';
            printf("Enemie HIT %d %d\n",i,j);
            return 1;
        }
            
    
}