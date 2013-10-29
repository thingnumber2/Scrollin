#ifndef CHARACTER_H
#define CHARACTER_H
#include "stuff.h"
#include "TheMap.h"
#include "Debug.h"




class Character
{
    public:
        Character(int,int,int,int,int,bool);
        virtual ~Character();
        int Getcharposx() {return charpos.X;}
        int Getcharposy() {return charpos.Y;}
        void Setcharposx(int val) {charpos.X = val;}
        void Setcharposy(int val) {charpos.Y = val;}
        void Resetcharpos()
        {charpos.X = -1;
         charpos.Y = -1;}

        int Getcharhboxx() {return charhbox.X;}
        int Getcharhboxy() {return charhbox.Y;}
        void Setcharhboxx(int val) {charhbox.X = val;}
        void Setcharhboxy(int val) {charhbox.Y = val;}
        void Resetcharhbox()
        {charhbox.X = -1;
         charhbox.Y = -1;}

         bool GetPlayer() {return Player;}
         void SetPlayer(int val) {Player = val;}

         int Getcharspeed(){return charspeed;}
         void Setcharspeed(int val) {charspeed = val;}

         int Getcharnum(){return charnum;}
         void Setcharnum(int val) {charnum = val;}

         int Getvecpos(){return vecpos;}
         void Setvecpos(int val) {vecpos = val;}




    protected:
    private:
        coord charpos; //The character's position on the map
        coord charhbox; //The character's hit box
        int charspeed; //How fast this character moves
        bool Player; //Is this the player or not
        int charnum; //The character's assigned number (later may match the vector position)
        int vecpos; //The character's vector position
};

#endif // CHARACTER_H
