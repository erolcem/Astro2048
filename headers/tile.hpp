#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#ifndef TILE_H
#define TILE_H
class Tile{
    public:
    static const int TILESIZE;
    static const int PADDING; 

    int value;
    bool isEmpty;
    bool isMerging;

    sf::Font font;

    Tile(bool empty, bool merging);

    Tile() : value(0), isEmpty(true), isMerging(false) {} // Deafault Constructor 

    void draw(sf::RenderWindow& window, int x, int y);

    void setValue(int newVal);

    
};


#endif