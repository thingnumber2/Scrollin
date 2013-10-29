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
     for (int a = 0;a<1000;a++) //fill the array
            {
                for (int b = 0;b<200;b++)
                {
                    if (b == 199||b == 198||b==0||b==1)
                    {
                        maparray[a][b] = 1;
                    }

                    else if (a == 0||a == 999||a==1||a==998)
                    {
                        maparray[a][b] = 1;
                    }
                    else
                    maparray[a][b] = 0;

                }
            };
}
