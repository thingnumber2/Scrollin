#ifndef THEMAP_H
#define THEMAP_H
#include <vector>
#include "Things.h"

extern Things AllThings;



class TheMap
{
    public:
        TheMap();
        virtual ~TheMap();
        int maparray [1000][200]; //this is the map array. It assumes tiles as 10/10 pixels. -2 is passable, anything -1 or greater is impassable, 2 is hitbox? Translation to pixelsis 2000 pixels tall, 10,000 long.
        void testfill ();
        bool teleportchar(int,int,int);
        // TODO (Dan#1#): Need to detect where characters are and put the appropriate boxes in the map. Draw will find these and draw them . ...
        //
        //Need a collision check function.
        //
        //Gravity function.
        int GetGravity(){return Gravity;}
        void SetGravity(int val) {Gravity = val;}


    protected:
    private:
        int Gravity; //How fast things drop eh?
};

#endif // THEMAP_H
