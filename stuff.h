#ifndef STUFF_H
#define STUFF_H






struct coord //Just stores coordinates. Right on.
{
    int X;
    int Y;
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



#endif // STUFF_H
