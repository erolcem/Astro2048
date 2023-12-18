#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#ifndef TILE_H
#define TILE_H
class Tile {
public:
  int value;
  bool isEmpty;
  bool isMerging;

  std::map<int, sf::Color> colourMap;

  Tile(bool empty, bool merging);

  Tile() : value(0), isEmpty(true), isMerging(false) {} // Deafault Constructor

  void draw(sf::RenderWindow &window, int x, int y);

  void setValue(int newVal);

  sf::Text textValue;
  sf::Font arial;
};

#endif