#include "TheVideo.h"
extern Debug DB;
extern Things AllThings;
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
     sf::RenderWindow window(sf::VideoMode(800, 500), "awwwww dang"); //This is drawing the window


     sf::View Camera1; //this is the camera view
     Camera1.setSize(sf::Vector2f(800, 500)); //setting it's  size
     window.setView(Camera1);
     sf::Clock clock1; //The clock!

   while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        ///Events here

        sf::Time elapsedtime = clock1.getElapsedTime();
                if (elapsedtime.asMilliseconds() > 10)
                {
                    AllMap.Gravitycheck(); ///gravity yo
                    ///movement keypress events
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))// left key is pressed: move our character
                    {
                         AllMap.movechar(AllThings.Gettheplayer(),dleft);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))// right key is pressed: move our character
                    {
                         AllMap.movechar(AllThings.Gettheplayer(),dright);
                    }


                    clock1.restart();
                }

        sf::Event event; //event loop
        while (window.pollEvent(event))
        {
        switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:

                     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //press up to jump
                    {
                       AllThings.charvector[AllThings.Gettheplayer()].jumpjump();
                    }
                    break;


                // we don't process other types of events
                default:
                    break;
            }


        }



        ///Draw Here

            Camera1.setCenter(sf::Vector2f(AllThings.charvector[AllThings.Gettheplayer()].Getcharposx() * 10,AllThings.charvector[AllThings.Gettheplayer()].Getcharposy() * 10));
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

            bool flip; //just to flip the colors
            for (int a = 0;a<1000;a++)
            {
                flip = !flip;//flips the color for freedee effect
                for (int b = 0;b<200;b++)
                {
                    if (AllMap.maparray[a][b] == -1)
                      {
                            if (flip)
                            {
                                defaultsprite.setColor(sf::Color::Blue);
                            }
                            else
                            {
                                defaultsprite.setColor(sf::Color::Cyan);
                            }

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

int TheVideo::MainMenu()
{
     sf::RenderWindow menuwindow(sf::VideoMode(800, 500), "Main Menu"); //This is drawing the window


   while (menuwindow.isOpen())
    {
        menuwindow.clear(sf::Color::Black);
        ///Events here
        sf::Vector2i LPd = sf::Mouse::getPosition(menuwindow); //grabs position and puts it in a vector named LPd

        sf::Event event; //event loop
        while (menuwindow.pollEvent(event))
        {
        switch (event.type)
            {
                // menuwindow closed
                case sf::Event::Closed:
                    menuwindow.close();
                    break;

                    case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (LPd.x > 310 && LPd.x < 410 && LPd.y > 205 && LPd.y < 240)
                        {
                            return 1;
                        }
                        else if (LPd.x > 310 && LPd.x < 500 && LPd.y > 255 && LPd.y < 290)
                        {
                            return 2;
                        }

                    }


                // we don't process other types of events
                default:
                    break;
            }


        }



        ///Draw Here

            sf::Font gisha;
            if (!gisha.loadFromFile("images/gisha.ttf"))
            {menuwindow.clear(sf::Color::Red);}



            sf::Texture deftext; //create new texture
            if (!deftext.loadFromFile("images/default.png")) //define the texture as our png in "images"
            {menuwindow.clear(sf::Color::Red);} //junky error message
            sf::Sprite defaultsprite; //create new sprite
            defaultsprite.setTexture(deftext); //set the sprite's texture to our loaded texture


        ///Draw Menu

            sf::Text textyeah;
            textyeah.setFont(gisha);
            textyeah.setCharacterSize(32);
            textyeah.setColor(sf::Color::Red);
            textyeah.setPosition(320,2);
            textyeah.setString("Main Menu");
            menuwindow.draw(textyeah);

            textyeah.setColor(sf::Color::Blue);
            textyeah.setPosition(320,200);
            textyeah.setString("Game");
            menuwindow.draw(textyeah);

            textyeah.setPosition(320,250);
            textyeah.setString("Map Builder");
            menuwindow.draw(textyeah);

            //Draws coordinates of the mouse
            textyeah.setPosition(5,450);
            textyeah.setColor(sf::Color::Magenta);

            std::string teststr = static_cast<std::ostringstream*>( &(std::ostringstream() << LPd.x << "," << LPd.y) )->str();
            textyeah.setString(teststr);
            menuwindow.draw(textyeah);

            if (LPd.x > 310 && LPd.x < 410 && LPd.y > 205 && LPd.y < 240)
            {
                sf::VertexArray lines(sf::LinesStrip, 5);

                for (int B = 0;B < 5;B++)
                {
                  lines[B].color = sf::Color::Blue;
                }

                lines[0].position = sf::Vector2f(410, 205);
                lines[1].position = sf::Vector2f(410, 240);
                lines[2].position = sf::Vector2f(310, 240);
                lines[3].position = sf::Vector2f(310, 205);
                lines[4].position = sf::Vector2f(410, 205);
                menuwindow.draw(lines);
            }

            if (LPd.x > 310 && LPd.x < 500 && LPd.y > 255 && LPd.y < 290)
            {
                sf::VertexArray lines(sf::LinesStrip, 5);

                for (int B = 0;B < 5;B++)
                {
                  lines[B].color = sf::Color::Blue;
                }

                lines[0].position = sf::Vector2f(500, 255);
                lines[1].position = sf::Vector2f(500, 290);
                lines[2].position = sf::Vector2f(310, 290);
                lines[3].position = sf::Vector2f(310, 255);
                lines[4].position = sf::Vector2f(500, 255);
                menuwindow.draw(lines);
            }







        ///debug text


        menuwindow.display(); //display everything drawn

    }

    return 0;


    }
