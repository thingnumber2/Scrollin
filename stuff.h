#ifndef STUFF_H
#define STUFF_H






struct coord //Just stores coordinates. Right on.
{
    int X;
    int Y;
};

struct fcoord //stores frame coordinates in a sprite sheet
{
    int locX; //location of the frame on the sprite sheet (top left corner of it I think?)
    int locY;
    int sizeX; //size of the frame on the sprite sheet
    int sizeY;
};

enum SuccFail
{
    Fail = 0,
    Success = 1,
    MAXSuccFail
};

enum directions
{
    dup,
    ddown,
    dleft,
    dright,
    MaxDirections
};

enum animstates //AHH I don't know
{
    running,
    crouching,
    jumping,
    standing,
    MAXanimstates


};

enum charsheets
{
    CSdef,
    MAXCS
};





#endif // STUFF_H
