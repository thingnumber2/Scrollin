#ifndef THINGS_H
#define THINGS_H
#include "Character.h"


class Things
{
    public:
        Things();
        virtual ~Things();
        std::vector <Character> charvector;
        void addchar (int,int,int,int,bool);

    protected:
    private:
};

#endif // THINGS_H
