#include <SFML/Graphics.hpp>
#include "gameTile.hpp"
#include <vector>
#include "door.hpp"
#include "floor.hpp"
#include "wall.hpp"
#include "player.hpp"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld {
    public:
    std::vector<std::vector<std::unique_ptr< GameTile>> > tiles;
    GameWorld();

    std::unique_ptr<Player> player;

    sf::Vector2i doorPos;
    sf::Vector2i playerPos;
    std::vector<sf::Vector2i> enempyPos;

    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();

private:
    // 28x x 31y
    const std::vector<std::vector<char>> map = {
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'f', 'f', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'d', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'd'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'f', 'f', 'f', 'f', 'f', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'f', 'f', 'f', 'f', 'f'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'w'},
        {'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w'},
        {'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'w', 'w', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w', 'w', 'f', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'f', 'w'},
        {'w', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'w'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}
    };

};

#endif

