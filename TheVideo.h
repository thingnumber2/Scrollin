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
        void Mapmake();

        int Getscreenx() {return screenx;}
        void Setscreenx(int val){screenx = val;}
        int Getscreeny() {return screeny;}
        void Setscreeny(int val){screeny = val;}

        void movescreen(int movedir)
            {
                switch (movedir) //Sets each of these based the direction moved.
                    {
                        case dup:
                        screeny = screeny - 1;
                        break;
                        case ddown:
                        screeny = screeny + 1;
                        break;
                        case dleft:
                        screenx = screenx - 1;
                        break;
                        case dright:
                        screenx = screenx + 1;
                        break;

                    }
            }

    protected:
    private:
        int screenx = 300; //position of the camera (for mapmake)
        int screeny = 1800;
};

#endif // THEVIDEO_H
