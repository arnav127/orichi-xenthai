#include "snkprop.h"
#include <stdlib.h>
#include <time.h>

class snk_food
{
public:
    position pos;
    snk_food()
    {
        srand(time(0));
        pos.x = (rand() % (XMAX - XMIN)) + XMIN;
        pos.y = (rand() % (YMAX - YMIN)) + YMIN;
    }
    void newpos()
    {
        gotoxy(XMAX, YMAX);
        pos.x = (rand() % (XMAX - XMIN)) + XMIN;
        pos.y = (rand() % (YMAX - YMIN)) + YMIN;
    }
};