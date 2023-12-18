#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "../headers/board.hpp"

// arch -x86_64 g++ -std=c++17 src/main.cpp src/tile.cpp src/board.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
// ./build/bin/2048




int main()
{
    int windowsWidth = 885;
    int windowsHeight = 885;
    int Xindex = 0;
    int Yindex = 0;


    sf::RenderWindow window(sf::VideoMode(windowsWidth, windowsHeight), "2048");
    window.setFramerateLimit(144);

    Board board;
    board.SpawnRandomTile();
    board.SpawnRandomTile();

    sf::Text score;
    sf::Font arial;

    if(!arial.loadFromFile("fonts/arial.ttf")) {
        std::cout << "ARIAL BROKEN\n";
    }

    score.setFont(arial);
    score.setString("1000");
    

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
                    case sf::Keyboard::W: board.moveUp();break;
                    case sf::Keyboard::A: board.moveLeft(); break;
                    case sf::Keyboard::S: board.moveDown(); break;
                    case sf::Keyboard::D: board.moveRight(); break;
                
                default:
                    break;
                }
            }
        }

        window.clear(sf::Color(64, 55, 37));
        board.draw(window);
        window.draw(score); 

        window.display();
        
    }
}