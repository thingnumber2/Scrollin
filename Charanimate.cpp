#include "Charanimate.h"
extern Things AllThings;

Charanimate::Charanimate()
{
    //for testing right now, I don't know if this is the most efficient way to do this.
    runframeL[0].locX = 254;
    runframeL[1].locX = 218;
    runframeL[2].locX = 178;
    runframeL[3].locX = 128;
    runframeL[4].locX = 85;

    runframeL[0].locY = 158;
    runframeL[1].locY = 158;
    runframeL[2].locY = 158;
    runframeL[3].locY = 158;
    runframeL[4].locY = 158;

    runframeL[0].sizeX = 30;
    runframeL[1].sizeX = 30;
    runframeL[2].sizeX = 30;
    runframeL[3].sizeX = 30;
    runframeL[4].sizeX = 30;

    runframeL[0].sizeY = 60;
    runframeL[1].sizeY = 60;
    runframeL[2].sizeY = 60;
    runframeL[3].sizeY = 60;
    runframeL[4].sizeY = 60;
    ///AHHHHHHHH
    runframeR[0].locX = 296;
    runframeR[1].locX = 341;
    runframeR[2].locX = 381;
    runframeR[3].locX = 430;
    runframeR[4].locX = 465;

    runframeR[0].locY = 158;
    runframeR[1].locY = 158;
    runframeR[2].locY = 158;
    runframeR[3].locY = 158;
    runframeR[4].locY = 158;

    runframeR[0].sizeX = 30;
    runframeR[1].sizeX = 30;
    runframeR[2].sizeX = 30;
    runframeR[3].sizeX = 30;
    runframeR[4].sizeX = 30;

    runframeR[0].sizeY = 60;
    runframeR[1].sizeY = 60;
    runframeR[2].sizeY = 60;
    runframeR[3].sizeY = 60;
    runframeR[4].sizeY = 60;


    crouframeL[0].locX = 277;
    crouframeL[0].locY = 968;
    crouframeL[0].sizeX = 30;
    crouframeL[0].sizeY = 30;

    crouframeR[0].locX = 277;
    crouframeR[0].locY = 968;
    crouframeR[0].sizeX = 30;
    crouframeR[0].sizeY = 30;

    jumpframeL[0].locX = 226;
    jumpframeL[0].locY = 367;
    jumpframeL[0].sizeX = 30;
    jumpframeL[0].sizeY = 75;

    jumpframeR[0].locX = 328;
    jumpframeR[0].locY = 367;
    jumpframeR[0].sizeX = 30;
    jumpframeR[0].sizeY = 75;

    standframeL[0].locX = 252;
    standframeL[0].locY = 289;
    standframeL[0].sizeX = 30;
    standframeL[0].sizeY = 60;

    standframeR[0].locX = 300;
    standframeR[0].locY = 289;
    standframeR[0].sizeX = 30;
    standframeR[0].sizeY = 60;

    //ctor
}

fcoord Charanimate::animate(int vecnum) //run all neccesary checks then send back the appropriate frame to the requester
{
    fcoord Aresults;
    if (AllThings.charvector[vecnum].Getintheair())
    {
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return jumpframeL[0];
        else
        return jumpframeR[0];
    }
    else if (AllThings.charvector[vecnum].Getiscrouched())
    {
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return crouframeL[0];
        else
        return crouframeR[0];
    }
    else if (AllThings.charvector[vecnum].Getismoving())
    {
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return runframeL[2];
        else
        return runframeR[2];
    }
    else //this would be for standing animations I guess.
    {
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return standframeL[0];
        else
        return standframeR[0];
    }


}

// TODO (Dan#1#): Still working on this animation thing

//find out what state we're in
//has enough time passed for this frame?
//find out what frame we're on
//return the data for that frame
//iterate the frame

Charanimate::~Charanimate()
{
    //dtor
}
