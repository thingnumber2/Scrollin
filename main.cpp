#include <iostream>
#include "TheVideo.h"
TheMap AllMap; //Global map
Things AllThings; //Global things thing
Debug DB; //debug class, neato.
#include <cassert>
// TODO (Dan#2#): Document the code. Not sure what I'm doing wrong on this but it's not quite working.

using namespace std;

int main()

    {

        AllMap.LoadMap("maps/default");
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
        //Drawing.Mapmake();





        return 0;
    }
