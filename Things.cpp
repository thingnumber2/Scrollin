#include "Things.h"

Things::Things()
{
    //ctor
}

Things::~Things()
{
    //dtor
}

void Things::addchar(int X,int Y,int xbox,int ybox,int speed,int charnum,bool isplayer)
{
    Character newcharacter(X,Y,xbox,ybox,speed,charnum,charvector.size(),isplayer);
    charvector.push_back(newcharacter);


}

void Things::addchardef(int X,int Y,bool isplayer)
{
    Character newcharacter(X,Y,isplayer,charvector.size());
    charvector.push_back(newcharacter);


}
