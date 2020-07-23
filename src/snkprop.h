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
    vector< position >pos; 
    public:
    position *head, *tail;
    snk_prop()
    {
        position temp;
        temp.x = 35;
        temp.y = 15;
        pos.push_back(temp);
        head = &pos[0];
        tail = &pos[0];
    }
    void move(int);
    void grow();
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
            head->y++;
            break;
        case 2:
            head->x--;
            break;
        case 3:
            head->y--;
            break;
        case 4:
            head->x++;
            break;
    }
    if(head->x < XMIN)
        head->x = XMAX ;
    if(head->x > XMAX )
        head->x = XMIN;
    if(head->y < YMIN)
        head->y = YMAX;
    if(head->y > YMAX )
        head->y = YMIN;
}

void snk_prop::grow()
{
    pos.push_back( pos[ pos.size()-1 ] );
    tail++;
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
