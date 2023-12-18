#include "tile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef BOARD_H
#define BOARD_H
class Board {
public:
  std::array<std::array<Tile, 4>, 4> boardMatrix;

  Board();

  int counter;
  void draw(sf::RenderWindow &window);
  bool noMovement = false;
  void moveUp();
  void moveRight();
  void moveLeft();
  void moveDown();

  void SpawnRandomTile();
};

#endif