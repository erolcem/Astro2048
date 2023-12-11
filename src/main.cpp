#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "../headers/board.hpp"

//arch -x86_64 g++ -std=c++17 src/main.cpp src/tile.cpp src/board.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    int windowsWidth = 885;
    int windowsHeight = 885;
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

    Board board;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        { 
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        

            if(event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                    case sf::Keyboard::W: board.moveUp(); std::cout <<"UP\n" ;break;
                    case sf::Keyboard::A: board.moveLeft(); break;
                    case sf::Keyboard::S: board.moveDown(); break;
                    case sf::Keyboard::D: board.moveRight(); break;
                
                default:
                    break;
                }
            }
        }

        window.clear(sf::Color::White);


        //window.draw(BackgroundSprite);
        window.clear(sf::Color(168, 94, 50));
        board.draw(window);


        window.display();
        
    }
}