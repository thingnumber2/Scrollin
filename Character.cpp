#include "Character.h"

extern Debug DB;

Character::Character(int X,int Y,int speed,int charnumber,int vectorpos,bool isplayer)
{
    charpos.X = X;
    charpos.Y = Y;
    charnum = charnumber;
    vecpos = vectorpos;
    Player = isplayer;
    charspeed = speed;
}

Character::~Character()
{
    //dtor
}
