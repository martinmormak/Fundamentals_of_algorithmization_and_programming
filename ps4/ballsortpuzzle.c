#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <time.h>
#include <stdbool.h>

void generator(const int rows, const int columns, char field[rows][columns])
{
    srand(time(0));
    int free1;
    int free2;
    for(int i=0;i<columns;i++)
    {
        for(int x=0;x<rows;x++)
        {
            field[x][i]=' ';
        }
    }
    free1=rand()%(columns-1)+0;
    do
    {
        free2=rand()%(columns-1)+0;
    }while(free1==free2);
    //printf("%d %d\n",free1,free2);
    for(int i=0;i<columns-2;i++)
    {
        for(int q=0;q<rows;q++)
        {
            int x;
            int y;
            do
            {
                do
                {
                    x=rand()%(columns)+0;
                }while(x==free1||x==free2);
                y=rand()%(rows)+0;
            }while(field[y][x]!=' ');
            field[y][x]=(char)(33+i);
            /*int x;
            do
            {
                x=rand()%(columns)+0;
            }while(x==free1||x==free2);
            int y=rand()%(rows)+0;
            if(field[y][x]==' ')
            {   
                field[y][x]=(char)(33+i);
            }
            else
            {
                q--;
            }*/
        }
    }
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
    x--;
    y--;
    int a=0;
    int b=rows-1;
    while(field[a][x]==' ')
    {
        if(a==rows-1)
        {
            break;
        }
        a++;
    }
    while(field[b][y]!=' ')
    {
        if(b==0)
        {
            printf("Bad move! This column is full!\n");
            return;
        }
        b--;
    }
    if(b==rows-1)
    {
        field[b][y]=field[a][x];
        field[a][x]=' ';
    }
    else if (field[a][x]==field[b+1][y])
    {
        field[b][y]=field[a][x];
        field[a][x]=' ';
    }
    else
    {
        printf("Bad move! You can't put this character '%c' on this '%c'!\n",field[a][x],field[b+1][y]);
    }
}

bool check(const int rows, const int columns, char field[rows][columns])
{
    for(int x=0;x<columns;x++)
    {
        if(field[rows-1][x]!=' ')
        {
            for(int y=rows-2;y>0;y--)
            {
                if(field[y][x]!=field[y-1][x])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void game_field(const int rows, const int columns, char field[rows][columns])
{
    //system("clear");//https://www.includehelp.com/c-programming-questions/how-to-clear-output-screen-in-c.aspx
    printf("\n\n\n");
    for(int y=0;y<rows;y++)
    {
        printf(" |");
        for(int x=0;x<columns;x++)
        {
            printf(" %c |",field[y][x]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i=0;i<columns;i++)
    {
        printf("--- ");
    }
    printf("\n  ");
    for(int i=0;i<columns;i++)
    {
        printf(" %i  ",i+1);
    }
    printf("\n");
}

void ball_sort_puzzle()
{
    system("clear");
    int columns=0;
    int rows=0;
    int x=0;
    int y=0;
    do
    {
        printf("Enter the number of rows.\nYou can choose from this interval <3;10>: ");
        scanf("%d",&rows);
    }while(rows<3||rows>10);
    do
    {
    printf("Enter the number of columns.\nYou can choose from this interval <4;10>: ");
    scanf("%d",&columns);
    }while(columns<4||columns>10);
    char field[rows][columns];
    for(int i=0;i<rows;i++)
    {
        for(int q=0;q<columns;q++)
        {
            field[i][q]=' ';
        }
    }
    generator(rows,columns,field);
    system("clear");
    game_field(rows,columns,field);
    while(!check(rows,columns,field))
    {
        printf("\n\n\n");
        do
        {
            printf("Enter column from which you want to get the top charakter:");
            scanf("%d",&x);
        }while(x<1||x>columns);
        do
        {
            printf("Where I can put this character:");
            scanf("%d",&y);
        }while(y<1||y>columns||x==y);
        system("clear");
        down_possible(rows,columns,field,x,y);
        /*if(check(rows,columns,field))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }*/
        game_field(rows,columns,field);
    }
    printf("\n\nCongratulation, you won!\n");
}
