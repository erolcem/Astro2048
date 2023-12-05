#include <SFML/Graphics.hpp>
#include "gameTile.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameTile {
    public:
    Player(int x, int y);

    void move(int dx, int dy);


};

#endif