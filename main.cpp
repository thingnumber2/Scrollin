#include <iostream>
#include "TheVideo.h"
// TODO (Dan#1#): Exceptions?!?
TheMap AllMap; //Global map
Things AllThings; //Global things thing
Debug DB;


using namespace std;

int main()

    {
        AllMap.testfill();
        TheVideo Drawing;
        AllThings.addchardef(30,180,true);
        AllMap.teleportchar(0,30,190);
        Drawing.Startup();





        return 0;
    }
