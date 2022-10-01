// #include "../src/snkprop.h"
#include "../src/snk_food.h"
#include "../src/colors.h"
#include <iostream>
#include <vector>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

snk_prop snk;
int direction = 1;
bool alive = true;
mutex mtx;

void input()
{
    int op;
    while (alive)
    {
        op = getch();
        if (op == 'x')
        {
            alive = false;
            return;
        }
        if (op != 27)
            getch();
        int temp = getch();
        if (op == 27 and temp != '[')
            getch();
        op = getch();
        switch (op)
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
        usleep(30000);
    }
}

void printtoscr(int x, int y, string str, string color = colreset, string effect = colreset)
{
    mtx.lock();
    gotoxy(x, y);
    cout << effect << color << str << colreset << flush;
    mtx.unlock();
}

void movement()
{
    while (alive)
    {
        printtoscr(snk.pos.front().x, snk.pos.front().y, "@", fmagenta, bold);
        if (snk.self_collision())
            alive = false;
        printtoscr(0, 9, to_string(snk.score()));
        if (direction == 1 or direction == 3)
            usleep(30000);
        if (direction == 2 or direction == 4)
            usleep(60000);
        printtoscr(snk.pos.back().x, snk.pos.back().y, " ");
        snk.move(direction);
    }
}

void food()
{
    snk_food apple;
    printtoscr(apple.pos.x, apple.pos.y, "#", fgreen, blink2);
    while (alive)
    {
        if (snk.pos.front().x == apple.pos.x and snk.pos.front().y == apple.pos.y)
        {
            apple.newpos();
            printtoscr(apple.pos.x, apple.pos.y, "#", fgreen);
            snk.grow(direction);
        }
        usleep(30000);
    }
}

void drawlvl()
{
    system("clear");
    printtoscr(0, 0, "Score = ");
    printtoscr(XMIN - 1, YMIN, string(YMAX - YMIN, ':'));
    printtoscr(XMAX + 1, YMIN, string(YMAX - YMIN, ':'));
    for (int i = XMIN - 1; i <= XMAX + 1; i++)
    {
        printtoscr(i, YMIN - 2, "::");
        printtoscr(i, YMAX + 1, "::");
    }
}

void lvl1()
{
    drawlvl();
    thread th1(input);
    thread th2(movement);
    thread th3(food);
    th1.join();
    th2.join();
    th3.join();
}
