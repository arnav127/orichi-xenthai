#include <vector>
#include "../src/mmaker/src/func.h"

#define XMAX getmax_x() - 5
#define YMAX getmax_y() - 10
#define XMIN 4
#define YMIN 4

using namespace std;

struct position
{
    int x, y;
};

class snk_prop
{
public:
    vector<position> pos;
    snk_prop()
    {
        position temp;
        temp.x = 35;
        temp.y = 15;
        pos.push_back(temp);
    }
    void move(int);
    void grow(int);
    bool self_collision();
    int score()
    {
        return pos.size();
    }
};

void snk_prop::move(int x)
{
    for (int i = pos.size() - 1; i > 0; i--)
    {
        pos[i].x = pos[i - 1].x;
        pos[i].y = pos[i - 1].y;
    }
    switch (x)
    {
    case 1:
        pos.front().y++;
        break;
    case 2:
        pos.front().x--;
        break;
    case 3:
        pos.front().y--;
        break;
    case 4:
        pos.front().x++;
        break;
    }
    if (pos.front().x < XMIN)
        pos.front().x = XMAX;
    if (pos.front().x > XMAX)
        pos.front().x = XMIN;
    if (pos.front().y < YMIN)
        pos.front().y = YMAX;
    if (pos.front().y > YMAX)
        pos.front().y = YMIN;
}

void snk_prop::grow(int x)
{
    pos.push_back(pos.back());

    switch (x)
    {
    case 1:
        pos.back().y--;
        break;
    case 2:
        pos.back().x++;
        break;
    case 3:
        pos.back().y++;
        break;
    case 4:
        pos.back().x--;
        break;
    }
}

bool snk_prop::self_collision()
{
    for (int i = 1; i < pos.size(); i++)
    {
        if (pos.front().x == pos[i].x and pos.front().y == pos[i].y)
        {
            return true;
        }
    }
    return false;
}
