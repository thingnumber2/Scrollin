#ifndef CHARANIMATE_H
#define CHARANIMATE_H
#include "stuff.h"
#include "Things.h"

class Charanimate
{
    public:
        Charanimate();
        virtual ~Charanimate();
        fcoord animate(int); //return the frame coordinates for this guy
        int framecheck(int,int,int,int); //check which frame this character should be on
    protected:
    private:
        int spritesheet; //which sprite sheet is being used
        int laststate; //what was the last state that was animated
        int currentframe; //what is the current animation frame
        fcoord runframeL[6]; //store frame locations on the sprite sheet.
        fcoord runframeR[6];
        fcoord crouframeL[2];
        fcoord crouframeR[2];
        fcoord jumpframeL[2];
        fcoord jumpframeR[2];
        fcoord standframeL[2];
        fcoord standframeR[2];

};

#endif // CHARANIMATE_H
