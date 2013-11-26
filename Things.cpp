#include "Things.h"

Things::Things()
{
    theplayer = 0; //defaults the player to 0
}

Things::~Things()
{
    //dtor
}

void Things::addchar(int X,int Y,int xbox,int ybox,int speed,int jump,int charnum,bool isplayer)
{
    Character newcharacter(X,Y,xbox,ybox,speed,jump,charnum,charvector.size(),isplayer,CSdef);
    charvector.push_back(newcharacter);


}

void Things::addchardef(int X,int Y,bool isplayer)
{
    Character newcharacter(X,Y,isplayer,charvector.size());
    charvector.push_back(newcharacter);


}
