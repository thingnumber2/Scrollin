#include "TheVideo.h"
extern Debug DB;

TheVideo::TheVideo()
{
    //ctor
}

TheVideo::~TheVideo()
{
    //dtor
}

void TheVideo::Startup()
{
     sf::RenderWindow window(sf::VideoMode(800, 500), "Main Window"); //This is drawing the window


     sf::View Camera1; //this is the camera view
     Camera1.setSize(sf::Vector2f(800, 500)); //setting it's  size
     window.setView(Camera1);

   while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        ///Events here

        sf::Event event; //event loop
        while (window.pollEvent(event)) // TODO (Dan#2#): Need to work on a way to change the speed of movement based on the character's speed. May have to limit or increase the number of moves in each timeframe.
        {
        switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        AllMap.movechar(AllThings.Gettheplayer(),dleft); //sort of a placeholder thing right now for testing
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        AllMap.movechar(AllThings.Gettheplayer(),dright);
                    }

                    break;


                // we don't process other types of events
                default:
                    break;
            }


        }



        ///Draw Here

            Camera1.setCenter(sf::Vector2f(400, 1750));
            window.setView(Camera1);

            sf::Font gisha;
            if (!gisha.loadFromFile("images/gisha.ttf"))
            {window.clear(sf::Color::Red);}



            sf::Texture deftext; //create new texture
            if (!deftext.loadFromFile("images/default.png")) //define the texture as our png in "images"
            {window.clear(sf::Color::Red);} //junky error message
            sf::Sprite defaultsprite; //create new sprite
            defaultsprite.setTexture(deftext); //set the sprite's texture to our loaded texture


        ///Draw passable/impassable/hitbox (testing)
// TODO (Dan#1#): Move the character, draw the character, make character collisions. Make other characters.
//Character size needs to be a thing, their hitbox, etc.
            //loop through the map array looking for impassable tiles and draw them
            for (int a = 0;a<1000;a++)
            {
                for (int b = 0;b<200;b++)
                {
                    if (AllMap.maparray[a][b] == -1)
                      {
                            defaultsprite.setColor(sf::Color::Blue);
                            defaultsprite.setPosition(a*10,b*10); //set position converted into pixels
                            window.draw(defaultsprite);

                      }
                    else if (AllMap.maparray[a][b] >= -1) //draw hitboxes
                      {

                            defaultsprite.setColor(sf::Color::Yellow);
                            defaultsprite.setPosition(a*10,b*10); //set position converted into pixels
                            window.draw(defaultsprite);

                      }


                }
            };




        ///debug text


        window.display(); //display everything drawn
}

}
