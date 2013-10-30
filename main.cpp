#include <iostream>
#include "TheVideo.h"
// TODO (Dan#1#): Exceptions?!?
TheMap AllMap;
Things AllThings;
Debug DB;


using namespace std;

int main()

    {
        AllMap.testfill();
        TheVideo Drawing;
        AllThings.addchardef(196,10,true);
        DB.dint(AllMap.teleportchar(0,30,180));
        Drawing.Startup();





        return 0;
    }
