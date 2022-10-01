#include "src/mmaker/src/mmaker.h"
#include "src/levels/level1.cpp"

int main()
{
    system("clear");
    menu snk;
    snk.menu_head("ORICHI XENTHAI");
    snk.add("KIDDY MODE", 1, "Snake can go through walls");
    snk.add("RELATIVELY EASY", 2, "Snake can go through walls");
    snk.add("STRICTLY AVERAGE", 3, "Snake can go through walls");
    snk.add("BONE CRUSHING HARD", 4, "Snake can go through walls");
    snk.add("NIGHTMARE", 5, "Snake cannot go through walls");
    snk.add("EXIT", 6);
    int op;
    while (true)
    {
        op = snk.display();
        switch (op)
        {
        case 1:
            lvl1();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
