#include <SFML/Graphics.hpp>
#include "../headers/gameWorld.hpp"
#include <iostream>

auto main() -> int
{
    // Create a window
    float windowsWidth = 700;
    float windowsHeight = 775;
    sf::RenderWindow window(sf::VideoMode(windowsWidth, windowsHeight), "Pac-Man");
    window.setFramerateLimit(60);

    GameWorld gameWorld = GameWorld();
    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Closing the Window
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            
            // Keyboard inputs for movement
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::W: gameWorld.player->move(0,-1); break;
                    case sf::Keyboard::A: gameWorld.player->move(-1, 0); break;
                    case sf::Keyboard::S: gameWorld.player->move(0, 1); break;
                    case sf::Keyboard::D: gameWorld.player->move(1, 0); break;
                    default: break;
                }
            }
        }

        window.clear();

    for(int i = 0; i < gameWorld.tiles.size(); i++) {
        for(int j = 0; j < gameWorld.tiles[i].size(); j++) {
            window.draw(gameWorld.tiles[i][j]->sprite);
        }
    }
        window.draw(gameWorld.player->sprite);
        //std::cout << gameWorld.player->pos.x << "X pos ____ Y pos" << gameWorld.player->pos.x << "\n";


        window.display();
    }

    return 0;
}
