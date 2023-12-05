#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

//arch -x86_64 g++ -std=c++17 src/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    int windowsWidth = 900;
    int windowsHeight = 900;
    int Xindex = 0;
    int Yindex = 0;


    sf::RenderWindow window(sf::VideoMode(windowsWidth, windowsHeight), "2048");
    window.setFramerateLimit(144);

    // Background setup
    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;
    
    if (BackgroundTexture.loadFromFile("./images/grid.png")) {
        std::cout << "successful sprite loading\n";


        BackgroundSprite.setTexture(BackgroundTexture);
        BackgroundSprite.setTextureRect(sf::IntRect(Xindex*0, Yindex*0,  225, 225));
        BackgroundSprite.scale(sf::Vector2f(4, 4));
    }
    else
    {
        std::cout << "player image failed to load\n";
    }



    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        { 
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);


        window.draw(BackgroundSprite);


        window.display();
    }
}