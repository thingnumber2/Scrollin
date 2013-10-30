#include "Character.h"

extern Debug DB;

Character::Character(int X,int Y,int xbox,int ybox, int speed,int charnumber,int vectorpos,bool isplayer)
{
    charpos.X = X;
    charpos.Y = Y;
    charhbox.X = xbox;
    charhbox.Y = ybox;
    charnum = charnumber;
    vecpos = vectorpos;
    Player = isplayer;
    charspeed = speed;
}

Character::Character(int X, int Y, bool isplayer,int vectorpos)
{
    charpos.X = X;
    charpos.Y = Y;
    charhbox.X = 3;
    charhbox.Y = 6;
    charnum = -1;
    vecpos = vectorpos;
    Player = isplayer;
    charspeed = 2;
}

Character::~Character()
{
    //dtor
}
