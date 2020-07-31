// #include "../src/snkprop.h"
#include "../src/snk_food.h"
#include "../src/colors.h"
#include<iostream>
#include<vector>
#include<unistd.h>
#include<thread>
using namespace std;
snk_prop snk;
// int dirx=0, diry=0;
int direction = 1;
bool alive = true;
void input()
{
    int op;
    while(alive)
    {
        op = getch();
        if(op == 'x')
        {
            alive = false;
            return;
        }
        if(op != 27)
            getch();
        int temp = getch();
        if(op == 27 and temp != '[')
            getch();
        op =  getch();
        switch(op)
        {
            case 67:
                direction = 1;
                break;
            case 65:
                direction = 2;
                break;
            case 68:
                direction = 3;
                break;
            case 66:
                direction = 4;
                break;
            
        }
    }
}

void movement()
{
    snk_food apple;
    gotoxy(apple.pos.x, apple.pos.y);
    cout << blink << fgreen << '#' << colreset << flush;
    while(alive)
    {
        gotoxy(snk.pos[0].x, snk.pos[0].y);
        cout << "@" << flush;
        if(snk.self_collision() == true)
            alive = false;
        gotoxy(0, 0);
        cout << "Score = " << snk.snk_size << flush;
        if(direction == 1 or direction == 3)
            usleep(20000);
        if(direction == 2 or direction == 4)
            usleep(40000);
        gotoxy(snk.pos[snk.snk_size-1].x, snk.pos[snk.snk_size-1].y);
        cout << " " << flush;
        
        if(snk.pos[0].x == apple.pos.x and snk.pos[0].y == apple.pos.y)
        {
            gotoxy(apple.pos.x, apple.pos.y);
            cout << " ";
            apple.newpos();
            gotoxy(apple.pos.x, apple.pos.y);
            cout << blink << fred << '#' << colreset << flush;
            snk.grow(direction);
        }
        snk.move(direction);
    }
}
void food()
{
    snk_food apple;
    gotoxy(apple.pos.x, apple.pos.y);
    cout << blink << fgreen << '#' << colreset << flush;
    while(alive)
    {
        if(snk.pos[0].x == apple.pos.x and snk.pos[0].y == apple.pos.y)
        {
            gotoxy(apple.pos.x, apple.pos.y);
            cout << " ";
            apple.newpos();
            gotoxy(apple.pos.x, apple.pos.y);
            cout << blink << fred << '#' << colreset << flush;
            snk.grow(direction);
        }
        
    }
}
void drawlvl()
{
    system("clear");
    gotoxy(XMIN-1,YMIN-1);
    cout << string(YMAX+1, ':');
    gotoxy(XMAX+1, 0);
    cout << string(YMAX+1, ':');
    for(int i=0;i<XMAX+2;i++)
    {
        gotoxy(i, 0);
        cout << ":";
        gotoxy(i, YMAX+1);
        cout << ":";
        cout << flush;
    } 
}
void lvl1()
{
    drawlvl();
    thread th1 (input);
    thread th2 (movement);
    // thread th3 (food);
    th1.join();
    th2.join();
    // th3.join();
}

int main()
{
    lvl1();
    return 0;
}


/*
void level1()
{
    system("clear");
    int direction = 1;
    //snk_food food;
    bool alive = true;
    while(alive)
    {
        if(kbhit())
        {
            getch();
            getch();
            int inp = getch();
            cin.clear();
            //gotoxy(0,0);
            //cout << inp;
            switch(inp)
            {
                case 27:
                    //return;
                case 67:
                    direction = 1;
                    break;
                case 65:
                    direction = 2;
                    break;
                case 68:
                    direction = 3;
                    break;
                case 66:
                    direction = 4;
            }
        }
        snk.move(direction);
        if(snk.self_collision() == true)
        {
            //gameover();
            return;
        }
        //snk.move(1);
            //remove(tail);
        // if(*head == food.pos)
        // {
        //     score++;
        //     do
        //     {
        //         food.new_pos();
        //     }while(overlap(food.pos));
        // }
        //gotoxy(0,0);
        //cout << ' ';
        //gotoxy(0, 0);
        //cout << "      ";
        gotoxy(snk.head->x, snk.head->y);
        cout << "@" << flush;
        gotoxy(0, 0);
        usleep(200000);
        gotoxy(snk.tail->x, snk.tail->y);
        cout << " ";

    }
}
*/