#ifndef CHARACTER_H
#define CHARACTER_H
#include "stuff.h"
#include "Debug.h"



/** Class for generating all characters in the game*/

class Character
{
    public:
        Character(int,int,int,int,int,int,int,int,bool); /**< Custom character constructor */
        Character(int,int,bool,int); /**< Default character constructor*/
        virtual ~Character();
        int Getcharposx() {return charpos.X;}
        int Getcharposy() {return charpos.Y;}
        void Setcharposx(int val) {charpos.X = val;}
        void Setcharposy(int val) {charpos.Y = val;}
        void Resetcharpos() /**< Resets the character's position to -99 for x and y. Don't use? */
        {charpos.X = -99;
         charpos.Y = -99;}

        int Getcharhboxx() {return charhbox.X;}
        int Getcharhboxy() {return charhbox.Y;}
        void Setcharhboxx(int val) {charhbox.X = val;}
        void Setcharhboxy(int val) {charhbox.Y = val;}
        void Resetcharhbox()  /**< Resets the character's box size to -1. Don't use this either */
        {charhbox.X = -1;
         charhbox.Y = -1;}

         bool GetisPlayer() {return isPlayer;}
         void SetisPlayer(int val){isPlayer = val;}

         bool Getintheair() {return intheair;}
         void Setintheair(int val){intheair = val;}

         bool Getiscrouched() {return iscrouched;}
         void Setiscrouched(int val){iscrouched = val;}

         int Getcharspeed(){return charspeed;}
         void Setcharspeed(int val) {charspeed = val;}

         int Getcharnum(){return charnum;}
         void Setcharnum(int val) {charnum = val;}

         int Getvecpos(){return vecpos;}
         void Setvecpos(int val) {vecpos = val;}

         int Getcharmoment(){return charmoment;}
         void Setcharmoment(int val) {charmoment = val;}
         /**< Checks if the character is already in the air, and if not, jumps! */
         void jumpjump ()
         {
             if (intheair == false)
             {
                 charmoment = charjump;
             }

         }

         void crouchcrouch ()  /**< Checks if the character is in the air or already crouched, and if not, crouches. */
         {
             if (intheair == true) //can't crouch in the air
             {
                 return;
             }

             if (iscrouched == false) //so long as the character isn't already crouched, crouch
             {
                 charhbox.Y = charhbox.Y-3; //make the character's hitbox smaller for the crouch

             }

             iscrouched = true;

         }
         void standstand ()  /**< If the character is crouched, uncrouch em  */
         {
             if (iscrouched == true) //so long as the character is crouching, stand
             {
                 charhbox.Y = charhbox.Y+3; //make the character's hitbox smaller for the crouch
                 charpos.Y = charpos.Y-3; //moves the character's position up 3 to match up with the size change. Yes it's negative, that's cuz Y gets smaller the higher it gets.


             }

             iscrouched = false;

         }



         void Reducemoment(int val)  /**< Reduces character momemtum down to 0 */
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


        int GetMovetick(){return Movetick;}
        void SetMovetick(int val) {Movetick = val;}
        void AddMovetick() {Movetick = Movetick + 1;}
        void ResetMovetick () {Movetick = 0;}  /**< Resets Movetick to 0! */




    protected:
    private:
        coord charpos; /**< The character's position on the map, this is the top left corner of the character*/
        coord charhbox; /**< The character's hit box*/
        int charspeed; /**< How fast this character moves CURRENTLY. This is affected by crouching and stuff*/
        int charjump; /**< momentum added when you jump*/
        int charmoment; /**< actual momentum*/
        bool intheair; /**< is this character in the air*/
        bool iscrouched; /**< is this character crouched */
        bool isPlayer; /**< Is this the player or not*/
        int charnum; /**< The character's assigned number (later may match the vector position)*/
        int vecpos; /**< The character's vector position*/
        int Movetick; /**< how many ticks have passed since this character tried to move last.*/
};

#endif // CHARACTER_H
