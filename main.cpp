#include <iostream>
#include "TheVideo.h"
// TODO (Dan#3#): Exceptions?!?
TheMap AllMap; //Global map
Things AllThings; //Global things thing
Debug DB; //debug class, neato.


using namespace std;

int main()

    {

        AllMap.testfill();
        AllThings.addchardef(30,180,true);
        AllMap.teleportchar(0,30,150);

        TheVideo Drawing;
       /* switch (Drawing.MainMenu())
        {
            case 0:
            break;
            case 1:
            Drawing.Startup();
            break;
            case 2:
            break;
            default:
            break;


        }
        */
        Drawing.Startup();





        return 0;
    }
