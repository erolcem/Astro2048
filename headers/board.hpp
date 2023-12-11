#include <SFML/Graphics.hpp>
#include "tile.hpp"
#include <iostream>

#ifndef BOARD_H
#define BOARD_H
class Board {
    public:
    std::array<std::array<Tile, 4>, 4> boardMatrix;

    Board();

    void draw(sf::RenderWindow& window);

    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();

    void SpawnRandomTile();


    
};


#endif