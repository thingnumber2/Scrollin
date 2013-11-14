#include "Character.h"

extern Debug DB;

// TODO (Dan#6#): At some point you need to make it so that when the character generates he's put on the map instead of having to be teleported or moved first. Maybe this should be in the map class instead though, and just call this character class.
Character::Character(int X,int Y,int xbox,int ybox, int speed,int jump,int charnumber,int vectorpos,bool isplayer)
{
    charpos.X = X;
    charpos.Y = Y;
    charhbox.X = xbox;
    charhbox.Y = ybox;
    charnum = charnumber;
    vecpos = vectorpos;
    SetisPlayer(isplayer);
    charspeed = speed;
    charjump = jump;
    iscrouched = false;
    charmoment = 0;
    SetMovetick(0);
}

Character::Character(int X, int Y, bool isplayer,int vectorpos)
{
    charpos.X = X;
    charpos.Y = Y;
    charhbox.X = 3;
    charhbox.Y = 6;
    charnum = -1;
    vecpos = vectorpos;
    SetisPlayer(isplayer);
    charspeed = 2;
    charjump  = 40;
    iscrouched = false;
    charmoment = 0;
    SetMovetick(0);
}

Character::~Character()
{
    //dtor
}
