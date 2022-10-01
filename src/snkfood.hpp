#pragma once
#include "snkprop.hpp"
#include <stdlib.h>
#include <time.h>
#include <random>

class snk_food
{
public:
    position pos;
    uniform_int_distribution<> distr;
    mt19937 gen;
    snk_food()
    {
        random_device rd;
        gen = mt19937(rd());
        distr = uniform_int_distribution<>(XMIN, XMAX);

        pos.x = distr(gen);
        pos.y = distr(gen);
    }
    void newpos()
    {
        pos.x = distr(gen);
        pos.y = distr(gen);
    }
};