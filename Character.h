#ifndef CHARACTER_H
#define CHARACTER_H
#include "stuff.h"
#include "Debug.h"



// TODO (Dan#3#): Crouching is mostly done, but you need to make the speed slower when you're crouched.

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

         bool Getintheair() {return intheair;}
         void Setintheair(int val){intheair = val;}

         int Getcharspeed(){return charspeed;}
         void Setcharspeed(int val) {charspeed = val;}

         int Getcharnum(){return charnum;}
         void Setcharnum(int val) {charnum = val;}

         int Getvecpos(){return vecpos;}
         void Setvecpos(int val) {vecpos = val;}

         int Getcharmoment(){return charmoment;}
         void Setcharmoment(int val) {charmoment = val;}
         void jumpjump ()
         {
             if (intheair == false) //so long as the character isn't already jumping, jump
             {
                 charmoment = charjump;
             }

         }//make the character jump?

// FIXME (Dan#1#): There's a bug here that when you're running you leave behind little hitbox poops when trying to crouch and I can't figure out why.
         void crouchcrouch ()
         {
             if (iscrouched == false) //so long as the character isn't already crouched, crouch
             {
                 charhbox.Y = charhbox.Y-3; //make the character's hitbox smaller for the crouch

             }

             iscrouched = true;

         }
         void standstand ()
         {
             if (iscrouched == true) //so long as the character isn't already crouched, crouch
             {
                 charhbox.Y = charhbox.Y+3; //make the character's hitbox smaller for the crouch
                 charpos.Y = charpos.Y-3; //moves the character's position up 3 to match up with the size change. Yes it's negative, that's cuz Y gets smaller the higher it gets.


             }

             iscrouched = false;

         }



         void Reducemoment(int val) //reduces momentum without going below 0
             {
                 if (charmoment - val <= 0)
                 {
                     charmoment = 0;
                 }
                 else
                 {
                     charmoment = charmoment - val;
                 }
             }




    protected:
    private:
        coord charpos; //The character's position on the map, this is the top left corner of the character
        coord charhbox; //The character's hit box
        int charspeed; //How fast this character moves
        int charjump; //momentum added when you jump
        int charmoment; //actual momentum
        bool intheair; //is this character in the air?
// TODO (Dan#1#): Also , controllers? That's an easy one
        bool iscrouched;
        bool isPlayer; //Is this the player or not
        int charnum; //The character's assigned number (later may match the vector position)
        int vecpos; //The character's vector position
};

#endif // CHARACTER_H
