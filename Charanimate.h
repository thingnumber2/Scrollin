#ifndef CHARANIMATE_H
#define CHARANIMATE_H
#include "stuff.h"
#include "Things.h"

class Charanimate
{
    public:
        Charanimate();
        virtual ~Charanimate();
        fcoord animate(int);
    protected:
    private:
        int spritesheet; //which sprite sheet is being used
        int laststate; //what was the last state that was animated
        int currentframe; //what is the current animation frame
        fcoord runframeL[5]; //store frame locations on the sprite sheet. This really has to be redone.
        fcoord runframeR[5];
        fcoord crouframeL[1];
        fcoord crouframeR[1];
        fcoord jumpframeL[1];
        fcoord jumpframeR[1];
        fcoord standframeL[1];
        fcoord standframeR[1];

};

#endif // CHARANIMATE_H
