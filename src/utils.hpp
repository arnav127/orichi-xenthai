#pragma once

#include <iostream>
#include <mutex>
#include "colors.h"
#include "snkprop.hpp"
#include "snkfood.hpp"
#include "gameprop.hpp"

using namespace std;

mutex mtx;

void input(game_state &gs)
{
    int op;
    while (gs.alive)
    {
        op = getch();
        if (op == 'x')
        {
            gs.alive = false;
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
            gs.direction = 1;
            break;
        case 65:
            gs.direction = 2;
            break;
        case 68:
            gs.direction = 3;
            break;
        case 66:
            gs.direction = 4;
            break;
        }
        usleep(gs.delay);
    }
}

void printtoscr(int x, int y, string str, string color = colreset, string effect = colreset)
{
    mtx.lock();
    gotoxy(x, y);
    cout << effect << color << str << colreset << flush;
    mtx.unlock();
}

void movement(game_state &gs)
{
    while (gs.alive)
    {
        printtoscr(gs.snk.pos.front().x, gs.snk.pos.front().y, "@", fmagenta, bold);
        if (gs.snk.self_collision())
            gs.alive = false;
        printtoscr(0, 9, to_string(gs.snk.score()));
        if (gs.direction == 1 or gs.direction == 3)
            usleep(gs.delay);
        if (gs.direction == 2 or gs.direction == 4)
            usleep(gs.delay * 1.7);
        printtoscr(gs.snk.pos.back().x, gs.snk.pos.back().y, " ");
        gs.snk.move(gs.direction);
    }
}

void food(game_state &gs)
{
    printtoscr(gs.apple.pos.x, gs.apple.pos.y, "#", fgreen, blink2);
    while (gs.alive)
    {
        if (gs.snk.pos.front().x == gs.apple.pos.x and gs.snk.pos.front().y == gs.apple.pos.y)
        {
            gs.apple.newpos();
            printtoscr(gs.apple.pos.x, gs.apple.pos.y, "#", fgreen);
            gs.snk.grow(gs.direction);
        }
        usleep(gs.delay);
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