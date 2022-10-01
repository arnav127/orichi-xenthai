#include "../utils.hpp"
#include "../gameprop.hpp"
#include <thread>

game_state gs;

void lvl1() {
    drawlvl();
    thread th1(input, ref(gs));
    thread th2(movement, ref(gs));
    thread th3(food, ref(gs));
    th1.join();
    th2.join();
    th3.join();
}