#include "Things.h"

Things::Things()
{
    //ctor
}

Things::~Things()
{
    //dtor
}

void Things::addchar(int X,int Y,int speed,int charnum,bool isplayer)
{
    Character newcharacter(X,Y,speed,charnum,charvector.size(),isplayer);
    charvector.push_back(newcharacter);

}
