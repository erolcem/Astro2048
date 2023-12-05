#include "../headers/tile.hpp"

Tile::Tile(bool empty, bool merging) {
    value = 0;
    isEmpty = empty;
    isMerging = merging;
}

const int Tile::TILESIZE = 25;
