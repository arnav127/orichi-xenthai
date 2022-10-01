#pragma once

#include "snkprop.hpp"
#include "snkfood.hpp"

struct game_state {
    int direction = 1;
    bool alive = true;
    snk_food apple;
    snk_prop snk;
    int delay = 30000;
};