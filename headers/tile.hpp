#include <SFML/Graphics.hpp>

#ifndef TILE_H
#define TILE_H
class Tile{
    public:
    static const int TILESIZE;

    int value;
    bool isEmpty;
    bool isMerging;

    Tile(bool empty, bool merging);


    
};


#endif