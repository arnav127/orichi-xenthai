#include <vector>
#include "../src/mmaker/src/func.h"

#define XMAX getmax_x()-5
#define YMAX getmax_y()-10
#define XMIN 2
#define YMIN 2

using namespace std;

struct position
{
    int x, y;
};

class snk_prop
{
    public:
    vector< position >pos; 
    int snk_size;
    // position *head, *tail;
    snk_prop()
    {
        position temp;
        temp.x = 35;
        temp.y = 15;
        pos.push_back(temp);
        // head = &pos[0];
        // tail = &pos[0];
        snk_size = 1;
    }
    void move(int);
    void grow(int);
    bool self_collision();
};

void snk_prop::move(int x)
{
    for(int i=0; i < pos.size()-1 ; i++ )
    {
        pos[i+1].x = pos[i].x;
        pos[i+1].y = pos[i].y;
    }
    switch(x)
    {
        case 1:
            pos[0].y++;
            break;
        case 2:
            pos[0].x--;
            break;
        case 3:
            pos[0].y--;
            break;
        case 4:
            pos[0].x++;
            break;
    }
    if(pos[0].x < XMIN)
        pos[0].x = XMAX ;
    if(pos[0].x > XMAX )
        pos[0].x = XMIN;
    if(pos[0].y < YMIN)
        pos[0].y = YMAX;
    if(pos[0].y > YMAX )
        pos[0].y = YMIN;
}

void snk_prop::grow(int x)
{
    pos.push_back( pos[ snk_size-1 ] );
    snk_size++;
    switch(x)
    {
        case 1:
            pos[snk_size].y--;
            break;
        case 2:
            pos[snk_size].x++;
            break;
        case 3:
            pos[snk_size].y++;
            break;
        case 4:
            pos[snk_size].x--;
            break;
    }
}

bool snk_prop::self_collision()
{
    for(int i=1; i< pos.size(); i++)
    {
        if(pos[0].x == pos[i].x and pos[0].y == pos[i].y)
        {
            return true;
        }
    }
    return false;
}
