#include "TheMap.h"
extern Things AllThings;
extern Debug DB;

TheMap::TheMap()
{
   Gravity = 1; //default Gravity setting
}

TheMap::~TheMap()
{
    //dtor
}



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
            default:
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

    //Adds character's hitbox based on character position and hitbox size. Hitbox is composed of the character's vector position
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

void TheMap::Gravitycheck() //does gravity related things
{
    for (int A = 0;A < AllThings.charvector.size();A++) //iterates through all characters
    {
        if (AllThings.charvector[A].Getcharmoment() == 0) //checks each character to see their current momentum, and if it is equal to 0, gravity affects them, if not, it is reduced by the gravity amount and they move upward
        {
          AllThings.charvector[A].Setintheair(movechar(A,ddown)); //if movechar fails a "down" move, this will cause "in the air" to be "false" . If move char is successful, this character is still in the air.
        }
        else
        {
            AllThings.charvector[A].Reducemoment(Gravity);
            if (AllThings.charvector[A].Getcharmoment() != 0) //an attempt to make the character move a little bit through the air before starting to drop
            {
                if (movechar(A,dup)) //if the jump isn't interfered with, set state as "in the air"
                {
                    AllThings.charvector[A].Setintheair(true);
                }
                else
                {
                    AllThings.charvector[A].Setcharmoment(0);
                }


            }

        }


    }

}
