#include "TheMap.h"

TheMap::TheMap()
{
   Gravity = 10; //default Gravity setting
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
// TODO (Dan#1#): Move and teleport characters onto the map. Hitboxes should all contain the character vectorposition?
//When moving, need to have some sort of collision detection/resolution
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
    // TODO (Dan#2#): Add a collision checker, this may need to be a seperate function



}
