#include "Debug.h"

Debug::Debug()
{
    //ctor
}



Debug::~Debug()
{
    //dtor
}


void Debug::dint(int A)
{

    sf::RenderWindow debugwindow(sf::VideoMode(200, 200), "Debug Window"); //Debug window
    debugwindow.setPosition(sf::Vector2i(175, 300));

   std::stringstream ss;//create a stringstream
   ss << A;//add number to the stream
   std::string text = ss.str();//return a string with the contents of the stream

    while (debugwindow.isOpen())
    {
        debugwindow.clear(sf::Color::Black);

        sf::Event devent; //event loop
        while (debugwindow.pollEvent(devent))
        {
        switch (devent.type)
            {
                // window closed
                case sf::Event::Closed:
                    debugwindow.close();
                    break;


                // we don't process other types of events
                default:
                    break;
            }


        }





            sf::Font gisha;
            if (!gisha.loadFromFile("images/gisha.ttf"))
            {debugwindow.clear(sf::Color::Red);}

            sf::Text debugtext;
            debugtext.setFont(gisha);
            debugtext.setCharacterSize(16);
            debugtext.setColor(sf::Color::Red);
            debugtext.setPosition(2,0);

             debugtext.setString(text);

             debugwindow.draw(debugtext);


             debugwindow.display();


}

}

void Debug::dstring(std::string text)
{
    sf::RenderWindow debugwindow(sf::VideoMode(200, 200), "Debug Window"); //Debug window
    debugwindow.setPosition(sf::Vector2i(175, 300));

    while (debugwindow.isOpen())
    {
        debugwindow.clear(sf::Color::Black);

        sf::Event devent; //event loop
        while (debugwindow.pollEvent(devent))
        {
        switch (devent.type)
            {
                // window closed
                case sf::Event::Closed:
                    debugwindow.close();
                    break;


                // we don't process other types of events
                default:
                    break;
            }


        }





            sf::Font gisha;
            if (!gisha.loadFromFile("images/gisha.ttf"))
            {debugwindow.clear(sf::Color::Red);}

            sf::Text debugtext;
            debugtext.setFont(gisha);
            debugtext.setCharacterSize(16);
            debugtext.setColor(sf::Color::Red);
            debugtext.setPosition(2,0);

             debugtext.setString(text);

             debugwindow.draw(debugtext);


             debugwindow.display();



 }

}


