#ifndef THEMAP_H
#define THEMAP_H
#include <vector>
#include "Character.h"



class TheMap
{
    public:
        TheMap();
        virtual ~TheMap();
        int maparray [1000][200]; //this is the map array. It assumes tiles as 10/10 pixels. 0 is passable, 1 is impassable. Translation to pixelsis 2000 pixels tall, 10,000 long.
        void testfill ();

        int GetGravity(){return Gravity;}
        void SetGravity(int val) {Gravity = val;}

    protected:
    private:
        int Gravity; //How fast things drop eh?
};

#endif // THEMAP_H
