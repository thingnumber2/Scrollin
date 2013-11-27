#include "Charanimate.h"
extern Things AllThings;

// TODO (Dan#5#): Come back around and tighten this up
Charanimate::Charanimate()
{
    //for testing right now, I don't know if this is the most efficient way to do this.
    runframeL[0].locX = 258;
    runframeL[1].locX = 225;
    runframeL[2].locX = 188;
    runframeL[3].locX = 145;
    runframeL[4].locX = 108;
    runframeL[5].locX = 72;

    runframeL[0].locY = 225;
    runframeL[1].locY = 225;
    runframeL[2].locY = 225;
    runframeL[3].locY = 225;
    runframeL[4].locY = 225;
    runframeL[5].locY = 225;

    runframeL[0].sizeX = 30;
    runframeL[1].sizeX = 30;
    runframeL[2].sizeX = 30;
    runframeL[3].sizeX = 38;
    runframeL[4].sizeX = 30;
    runframeL[5].sizeX = 30;

    runframeL[0].sizeY = 60;
    runframeL[1].sizeY = 60;
    runframeL[2].sizeY = 60;
    runframeL[3].sizeY = 60;
    runframeL[4].sizeY = 60;
    runframeL[5].sizeY = 60;
    ///AHHHHHHHH
    runframeR[0].locX = 295;
    runframeR[1].locX = 333;
    runframeR[2].locX = 368;
    runframeR[3].locX = 401;
    runframeR[4].locX = 446;
    runframeR[5].locX = 485;

    runframeR[0].locY = 225;
    runframeR[1].locY = 225;
    runframeR[2].locY = 225;
    runframeR[3].locY = 225;
    runframeR[4].locY = 225;
    runframeR[5].locY = 225;

    runframeR[0].sizeX = 30;
    runframeR[1].sizeX = 30;
    runframeR[2].sizeX = 30;
    runframeR[3].sizeX = 38;
    runframeR[4].sizeX = 30;
    runframeR[5].sizeX = 30;

    runframeR[0].sizeY = 60;
    runframeR[1].sizeY = 60;
    runframeR[2].sizeY = 60;
    runframeR[3].sizeY = 60;
    runframeR[4].sizeY = 60;
    runframeR[5].sizeY = 60;


    crouframeL[0].locX = 277;
    crouframeL[0].locY = 968;
    crouframeL[0].sizeX = 30;
    crouframeL[0].sizeY = 30;

    crouframeL[1].locX = 277;
    crouframeL[1].locY = 968;
    crouframeL[1].sizeX = 30;
    crouframeL[1].sizeY = 30;

    crouframeR[0].locX = 277;
    crouframeR[0].locY = 968;
    crouframeR[0].sizeX = 30;
    crouframeR[0].sizeY = 30;

    crouframeR[1].locX = 277;
    crouframeR[1].locY = 968;
    crouframeR[1].sizeX = 30;
    crouframeR[1].sizeY = 30;

    jumpframeL[0].locX = 226;
    jumpframeL[0].locY = 367;
    jumpframeL[0].sizeX = 30;
    jumpframeL[0].sizeY = 75;

    jumpframeL[1].locX = 226;
    jumpframeL[1].locY = 367;
    jumpframeL[1].sizeX = 30;
    jumpframeL[1].sizeY = 75;

    jumpframeR[0].locX = 328;
    jumpframeR[0].locY = 367;
    jumpframeR[0].sizeX = 30;
    jumpframeR[0].sizeY = 75;

    jumpframeR[1].locX = 328;
    jumpframeR[1].locY = 367;
    jumpframeR[1].sizeX = 30;
    jumpframeR[1].sizeY = 75;

    standframeL[0].locX = 252;
    standframeL[0].locY = 289;
    standframeL[0].sizeX = 30;
    standframeL[0].sizeY = 60;

    standframeL[1].locX = 252;
    standframeL[1].locY = 289;
    standframeL[1].sizeX = 30;
    standframeL[1].sizeY = 60;

    standframeR[0].locX = 300;
    standframeR[0].locY = 289;
    standframeR[0].sizeX = 30;
    standframeR[0].sizeY = 60;

    standframeR[1].locX = 300;
    standframeR[1].locY = 289;
    standframeR[1].sizeX = 30;
    standframeR[1].sizeY = 60;

    //ctor
}

fcoord Charanimate::animate(int vecnum) //run all neccesary checks then send back the appropriate frame to the requester
{
    fcoord Aresults;
    int oldstate = AllThings.charvector[vecnum].Getlaststate();
    if (AllThings.charvector[vecnum].Getintheair())
    {
        AllThings.charvector[vecnum].Setlaststate(jumping);
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return jumpframeL[framecheck(vecnum,oldstate,jumping,1)];
        else
        return jumpframeR[framecheck(vecnum,oldstate,jumping,1)];
    }
    else if (AllThings.charvector[vecnum].Getiscrouched())
    {
        AllThings.charvector[vecnum].Setlaststate(crouching);
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return crouframeL[framecheck(vecnum,oldstate,crouching,1)];
        else
        return crouframeR[framecheck(vecnum,oldstate,crouching,1)];
    }
    else if (AllThings.charvector[vecnum].Getismoving())
    {
        AllThings.charvector[vecnum].Setlaststate(running);
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return runframeL[framecheck(vecnum,oldstate,running,5)];
        else
        return runframeR[framecheck(vecnum,oldstate,running,5)];
    }
    else //this would be for standing animations I guess.
    {

        AllThings.charvector[vecnum].Setlaststate(standing);
        if (AllThings.charvector[vecnum].Getcharfacing() == 0)
        return standframeL[framecheck(vecnum,oldstate,standing,1)];
        else
        return standframeR[framecheck(vecnum,oldstate,standing,1)];
    }


}

int Charanimate::framecheck(int vecnum,int oldstate,int newstate,int endframe)
{
    if (oldstate == newstate && AllThings.charvector[vecnum].Getlastframe() < endframe)
    {
        AllThings.charvector[vecnum].Setlastframe(AllThings.charvector[vecnum].Getlastframe()+1);
        return AllThings.charvector[vecnum].Getlastframe();
    }
    else
    {
        AllThings.charvector[vecnum].Setlastframe(0);
        return 0;
    }

}
//find out what state we're in
//has enough time passed for this frame?
//find out what frame we're on
//return the data for that frame
//iterate the frame




Charanimate::~Charanimate()
{
    //dtor
}
