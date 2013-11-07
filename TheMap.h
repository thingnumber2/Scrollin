#ifndef THEMAP_H
#define THEMAP_H
#include <vector>
#include "Things.h"
#include "stuff.h"
#include <fstream>
#include <iostream>
#include <string>



class TheMap
{
    public:
        TheMap();
        virtual ~TheMap();
        int maparray [1000][200]; //this is the map array. It assumes tiles as 10/10 pixels. -2 is passable, anything -1 or greater is impassable, 2 is hitbox? Translation to pixelsis 2000 pixels tall, 10,000 long.
        bool teleportchar(int,int,int);
        bool movechar(int,int);
        void Gravitycheck();

        int GetGravity(){return Gravity;}
        void SetGravity(int val) {Gravity = val;}

        void SaveMap(std::string mapsavename) //saves just the map,not the characters. Can make it do that though, if we need to.
        {
            std::string combinemapsav = "maps/" + mapsavename; //adds the folder here
            std::ofstream savewoo(combinemapsav.c_str()); //saves the map to the maps folder yay
            if (!savewoo){}//do some kind of error here or some kind of junk
            for (int a = 0;a<1000;a++) //fill the array with some basic stuff
                    {
                        for (int b = 0;b<200;b++)
                        {
                            if (maparray[a][b] < 0) //checks for only map tiles, not characters and stuff
                            {
                                savewoo << maparray[a][b] << std::endl;
                            }
                            else
                            {
                                savewoo << -2 << std::endl; //saves a blank space where a character would have been if we were saving characters
                            }

                        }
                    }
        };
        void LoadMap(std::string maploadname)
        {
                std::ifstream loadwaa(maploadname.c_str());

                if (!loadwaa){}//do some kind of error here or some kind of junk

                while (loadwaa)
                {
                    int loadint;
                    loadwaa >> loadint;
                    for (int a = 0;a<1000;a++) //fill the array with some basic stuff
                    {
                        for (int b = 0;b<200;b++)
                        {
                            loadwaa >> maparray[a][b];

                        }
                    }
                }
        }


    protected:
    private:
        int Gravity; //How fast things drop eh?
};

#endif // THEMAP_H
