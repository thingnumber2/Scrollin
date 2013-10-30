#ifndef THINGS_H
#define THINGS_H
#include "Character.h"


class Things
{
    public:
        Things();
        virtual ~Things();
        std::vector <Character> charvector;
        void addchar (int,int,int,int,int,int,int,bool);
        void addchardef (int,int, bool);

        int Gettheplayer(){return theplayer;}
        void Settheplayer(int val) //use this to change who the player is.
        {
            charvector[theplayer].SetisPlayer(false); //changes old player to false
            theplayer = val; //sets new character as the player
            charvector[val].SetisPlayer(true); //Sets new player to true
        }

    protected:
    private:
        int theplayer; //stores which character is currently the player
};

#endif // THINGS_H
