#ifndef THEVIDEO_H
#define THEVIDEO_H
#include <SFML/Graphics.hpp>
#include "TheMap.h"
#include "Things.h"

extern TheMap AllMap;


class TheVideo
{
    public:
        TheVideo();
        virtual ~TheVideo();
        void Startup ();
        int MainMenu();
    protected:
    private:
};

#endif // THEVIDEO_H
