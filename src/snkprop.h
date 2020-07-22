#include <iostream>
#include "../src/mmaker/src/func.h"

using namespace std;

struct position
{
    int x, y;
};

class snk_prop
{
    vector< position >pos(1);
    public:
    snk_prop()
    {
        pos[0].x=10;
        pos[0].y=10;
    }
    pos move(int);
    void grow();
    bool self_collision();
};

pos snk_prop::move(int x)
{
    for(int i=0; i < pos.size()-1 ; i++ )
    {
        pos[i+1].x = pos[i].x;
        pos[i+1].y = pos[i].y;
    }
    switch(x)
    {
        case 1:
            pos[0].x = pos[1].x + 1;
            break;
        case 2:
            pos[0].y = pos[1].y - 1;
            break;
        case 3:
            pos[0].x = pos[1].x - 1;
            break;
        case 4:
            pos[0].y = pos[1].y + 1;
            break;
    }

}

void snk_prop::grow()
{
    pos.push_back( pos[ pos.size()-1 ] );
}

bool snk_prop::self_collision()
{
    for(int i=1; i< pos.size(); i++)
    {
        if(pos[0] == pos[i])
        {
            return true;
        }
    }
    return false;
}
