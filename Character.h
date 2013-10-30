#ifndef CHARACTER_H
#define CHARACTER_H
#include "stuff.h"
#include "Debug.h"




class Character
{
    public:
        Character(int,int,int,int,int,int,int,int,bool); //kind of a weird character thing, might not be permanent
        Character(int,int,bool,int); //Just for making a basic default character
        virtual ~Character();
        int Getcharposx() {return charpos.X;}
        int Getcharposy() {return charpos.Y;}
        void Setcharposx(int val) {charpos.X = val;}
        void Setcharposy(int val) {charpos.Y = val;}
        void Resetcharpos() //this may or may not even work, what is more than 1 character does this? Ewwww
        {charpos.X = -99;
         charpos.Y = -99;}

        int Getcharhboxx() {return charhbox.X;}
        int Getcharhboxy() {return charhbox.Y;}
        void Setcharhboxx(int val) {charhbox.X = val;}
        void Setcharhboxy(int val) {charhbox.Y = val;}
        void Resetcharhbox() //should never need to use this?
        {charhbox.X = -1;
         charhbox.Y = -1;}

         bool GetisPlayer() {return isPlayer;}
         void SetisPlayer(int val){isPlayer = val;}

         int Getcharspeed(){return charspeed;}
         void Setcharspeed(int val) {charspeed = val;}

         int Getcharnum(){return charnum;}
         void Setcharnum(int val) {charnum = val;}

         int Getvecpos(){return vecpos;}
         void Setvecpos(int val) {vecpos = val;}




    protected:
    private:
        coord charpos; //The character's position on the map, this is the top left corner of the character
        coord charhbox; //The character's hit box
        int charspeed; //How fast this character moves
        int charjump; //momentum added when you jump
        int charmoment; //actual momentum
        bool isPlayer; //Is this the player or not
        int charnum; //The character's assigned number (later may match the vector position)
        int vecpos; //The character's vector position
};

#endif // CHARACTER_H
