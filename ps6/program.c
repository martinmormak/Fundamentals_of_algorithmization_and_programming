#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

void generate(const int size,int array[size][size]);
void print_array(const int size, const int array[size][size]);
void interaction(const int size, const int array[size][size]);

int main()
{
    srand(time(0));
    int level;
    int size;
    do
    {
        do
        {
            printf("Enter on which size of world would you like play?\n1 = 5*5\n2 = 10*10\n3 = 15*15\nPress 4 to Exit.");
            scanf("%d",&level);
        }while(level<1||level>4);
        if(level==4)
        {
            break;
        }
        int array[15][15]/*={
                {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
                {2,3,4,5,6,7,8,9,10,11,12,13,14,15,1},
                {3,4,5,6,7,8,9,10,11,12,13,14,15,1,2},
                {4,5,6,7,8,9,10,11,12,13,14,15,1,2,3},
                {5,6,7,8,9,10,11,12,13,14,15,1,2,3,4},
                {6,7,8,9,10,11,12,13,14,15,1,2,3,4,5},
                {7,8,9,10,11,12,13,14,15,1,2,3,4,5,6},
                {8,9,10,11,12,13,14,15,1,2,3,4,5,6,7},
                {9,10,11,12,13,14,15,1,2,3,4,5,6,7,8},
                {10,11,12,13,14,15,1,2,3,4,5,6,7,8,9},
                {11,12,13,14,15,1,2,3,4,5,6,7,8,9,10},
                {12,13,14,15,1,2,3,4,5,6,7,8,9,10,11},
                {13,14,15,1,2,3,4,5,6,7,8,9,10,11,12},
                {14,15,1,2,3,4,5,6,7,8,9,10,11,12,13},
                {15,1,2,3,4,5,6,7,8,9,10,11,12,13,14}}*/;

        switch(level)
        {
            case 1:
                size=5;
                break;
            case 2:
                size=10;
                break;
            case 3:
                size=15;
                break;
            default:
                continue;
                break;
        }
        generate(size,array);
        initscr();
        start_color();
        init_pair(1,COLOR_BLUE,COLOR_BLACK);
        init_pair(2,COLOR_YELLOW,COLOR_BLACK);
        init_pair(3,COLOR_GREEN,COLOR_BLACK);
        cbreak();
        noecho();
        keypad(stdscr,TRUE);
        curs_set(FALSE);
        nodelay(stdscr,TRUE);
        interaction(size,array);
        endwin();
        printf("Press enter to continue.");
        while(getchar()!='\n');
    }while(level!=4);
    printf("Bey!\n");
    return 0;
}

void generate(const int size, int array[size][size])
{
    int y;
    int x;
    for(y=0;y<size;y++)
    {
        for(x=0;x<size;x++)
        {
            do
            {
                array[y][x]=rand()%10+0;
            }while(array[y][x]%2==0);
        }
    }
    x=0;
    y=0;
    do
    {
        array[x][y]=rand()%10+0;
    }while(array[y][x]%2!=0);
    do
    {
        int q=rand()%2+0;
        if(q==0)
        {
            //printf("%d\t%d\n",x,y);
            if(x<size-1)
            {
                /*if(array[y][x-1]%2==0&&array[y][x+1]%2==0)
                {
                }
                else if(array[y-1][x]%2==0&&array[y+1][x]%2==0)
                {
                }
                else
                {*/
                x++;
                do
                {
                    array[y][x]=rand()%10+0;
                }while(array[y][x]%2!=0);
                //}
            }        
        }
        else if(q==1)
        {
            if(y<size-1)
            {
                /*if(array[y][x-1]%2==0&&array[y][x+1]%2==0)
                {
                }
                else if(array[y-1][x]%2==0&&array[y+1][x]%2==0)
                {
                }
                else
                {*/
                y++;
                do
                {
                    array[y][x]=rand()%10+0;
                }while(array[y][x]%2!=0);
                //}
            }
        }
        else if(q==2)
        {
            if(x>0)
            {
                /*if(array[y][x-1]%2==0&&array[y][x+1]%2==0)
                {
                }
                else if(array[y-1][x]%2==0&&array[y+1][x]%2==0)
                {
                }
                else
                {*/
                x--;
                do
                {
                    array[y][x]=rand()%10+0;
                }while(array[y][x]%2!=0);
                //}
            }
        }
        else if(q==3)
        {
            if(y>0)
            {
                /*if(array[y][x-1]%2==0&&array[y][x+1]%2==0)
                {
                }
                else if(array[y-1][x]%2==0&&array[y+1][x]%2==0)
                {
                }
                else
                {*/
                y--;
                do
                {
                    array[y][x]=rand()%10+0;
                }while(array[y][x]%2!=0);
                //}
            }
        }
    }while(x<size-1||y<size-1);
}

void print_array(const int size, const int array[size][size])
{
    for(int y=0;y<size;y++)
    {
        for(int x=0;x<size;x++)
        {
            mvprintw(y,x,"%d",array[y][x]);
        }
    }
}

void interaction(const int size, const int array[size][size])
{
    int input;
    int y=0;
    int x=0;
    clear();
    char buffer[]="Press q/Q to quit. Move by arrows. You can stand only in an even number.";
    mvprintw(LINES-1,0,"%s",buffer);
    print_array(size,array);
    char player = 'P';
    char finish = 'X';
    attron(COLOR_PAIR(1));
    mvprintw(y,x,"%c",player);
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(size-1,size-1,"%c",finish);
    attroff(COLOR_PAIR(2));
    refresh();
    do
    {
        input=getch();
        if(input=='q'||input=='Q')
        {
            continue;
        }
        switch(input)
        {
            case KEY_LEFT:
                if(x>0)
                {
                    if(array[y][x-1]%2==0)
                    {
                        attron(COLOR_PAIR(3));
                        mvprintw(y,x,"%d",array[y][x]);
                        attroff(COLOR_PAIR(3));
                        x--;
                        attron(COLOR_PAIR(1));
                        mvprintw(y,x,"%c",player);
                        attroff(COLOR_PAIR(1));

                    }
                    else
                    {
                        mvprintw(LINES-2,0,"%d is not even number!          ",array[y][x-1]);
                    }
                }
                else
                {
                    mvprintw(LINES-2,0,"%s","I can't move this direction!          ");
                }
                break;
            case KEY_RIGHT:
                if(x<size-1)
                {
                    if(array[y][x+1]%2==0)
                    {
                        attron(COLOR_PAIR(3));
                        mvprintw(y,x,"%d",array[y][x]);
                        attroff(COLOR_PAIR(3));
                        x++;
                        attron(COLOR_PAIR(1));
                        mvprintw(y,x,"%c",player);
                        attroff(COLOR_PAIR(1));
                    }
                    else
                    {
                        mvprintw(LINES-2,0,"%d is not even number!          ",array[y][x+1]);
                    }
                }
                else
                {
                    mvprintw(LINES-2,0,"%s","I can't move this direction!          ");
                }
                break;
            case KEY_UP:
                if(y>0)
                {
                    if(array[y-1][x]%2==0)
                    {
                        attron(COLOR_PAIR(3));
                        mvprintw(y,x,"%d",array[y][x]);
                        attroff(COLOR_PAIR(3));
                        y--;
                        attron(COLOR_PAIR(1));
                        mvprintw(y,x,"%c",player);
                        attroff(COLOR_PAIR(1));
                    }
                    else
                    {
                        mvprintw(LINES-2,0,"%d is not even number!          ",array[y-1][x]);
                    }
                }
                else
                {
                    mvprintw(LINES-2,0,"%s","I can't move this direction!          ");
                }
                break;
            case KEY_DOWN:
                if(y<size-1)
                {
                    if(array[y+1][x]%2==0)
                    {
                        attron(COLOR_PAIR(3));
                        mvprintw(y,x,"%d",array[y][x]);
                        attroff(COLOR_PAIR(3));
                        y++;
                        attron(COLOR_PAIR(1));
                        mvprintw(y,x,"%c",player);
                        attroff(COLOR_PAIR(1));
                    }
                    else
                    {
                        mvprintw(LINES-2,0,"%d is not even number!          ",array[y+1][x]);
                    }
                }
                else
                {
                    mvprintw(LINES-2,0,"%s","I can't move this direction!          ");
                }
                break;
        }
        refresh();
        if(x==size-1&&y==size-1)
        {
            mvprintw(LINES-2,0,"%s","You won!                    ");
            refresh();
            sleep(5);
            while(getchar()!='\n');
            break;
        }
    }while(input!='q'&&input!='Q');
}
