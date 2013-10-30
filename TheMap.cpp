#include "TheMap.h"

TheMap::TheMap()
{
   Gravity = 5; //default Gravity setting
}

TheMap::~TheMap()
{
    //dtor
}

void TheMap::testfill() //just fills this thing while I'm testing
{
     for (int a = 0;a<1000;a++) //fill the array with some basic stuff
            {
                for (int b = 0;b<200;b++)
                {
                    if (b == 199||b == 198||b==0||b==1)
                    {
                        maparray[a][b] = -1;
                    }

                    else if (a == 0||a == 999||a==1||a==998)
                    {
                        maparray[a][b] = -1;
                    }
                    else
                    maparray[a][b] = -2;

                }
            };
}

void TheMap::Gravitycheck()
{
    // TODO (Dan#1#): Do this thing here
}

// TODO (Dan#2#): Gravity thoughts: ...
//Gravity "movechar"s you down always, at a rate of Gravity minus Momentum. When you jump, your character gains upward momentum, and you will lose it to gravity each second.  If you hit an obstacle above you , you will also be reduced to 0 momentum.


// TODO (Dan#1#): Character movement, and then, gravity, which should just be an extension of movement.
///Movement amount should always be 1, speed should be something else. If it's more than 1 we can pass through other things without a check.
bool TheMap::movechar(int vecpos,int direction) //removes character info from old location and adds them to new location based on their speed of movement
{
        int newX = AllThings.charvector[vecpos].Getcharposx(); //sets defaults for X and Y, to be changed below
        int newY = AllThings.charvector[vecpos].Getcharposy();
        switch (direction) //Sets each of these based the direction moved.
        {
            case dup:
            newY = newY - 1;
            break;
            case ddown:
            newY = newY + 1;
            break;
            case dleft:
            newX = newX - 1;
            break;
            case dright:
            newX = newX + 1;
            break;

        }


     //Checks if there's anything already in that space (other than empty space and the existing character) and fails if so.
    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++)
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            if (maparray[newX + A][newY + B] != vecpos && maparray[newX + A][newY + B] != -2)
                return Fail;

        }


    }
    //Remove's character's hitbox based on character position and hitbox size. Hitbox is composed of the character's vector position
    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++)
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            maparray[AllThings.charvector[vecpos].Getcharposx() + A][AllThings.charvector[vecpos].Getcharposy() + B] = -2;
        }


    }

    //Draws character's hitbox based on character position and hitbox size. Hitbox is composed of the character's vector position
    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++)
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            maparray[newX + A][newY + B] = vecpos;
        }


    }

        //set new location for this character, yay
        AllThings.charvector[vecpos].Setcharposx(newX);
        AllThings.charvector[vecpos].Setcharposy(newY);
        return Success;



}






bool TheMap::teleportchar(int vecpos,int newX,int newY) //removes character info from old location and adds them to new location
{

    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++) //Checks if there's anything already in that space (other than empty space and the existing character) and fails if so.
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            if (maparray[newX + A][newY + B] != vecpos && maparray[newX + A][newY + B] != -2)
                return Fail;

        }


    }

    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++) //Remove's character's hitbox based on character position and hitbox size. Hitbox is composed of the character's vector position
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            maparray[AllThings.charvector[vecpos].Getcharposx() + A][AllThings.charvector[vecpos].Getcharposy() + B] = -2;
        }


    }


    for (int A = 0; A < AllThings.charvector[vecpos].Getcharhboxx();A++) //Draws character's hitbox based on character position and hitbox size. Hitbox is composed of the character's vector position
    {
        for (int B = 0; B < AllThings.charvector[vecpos].Getcharhboxy();B++)
        {
            maparray[newX + A][newY + B] = vecpos;
        }


    }

        //set new location for this character, yay
        AllThings.charvector[vecpos].Setcharposx(newX);
        AllThings.charvector[vecpos].Setcharposy(newY);
        return Success;



}
