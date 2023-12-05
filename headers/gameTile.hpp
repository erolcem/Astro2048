#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {
    public:
    static const int TILESIZE;

    bool isPassable;
    bool isDoor;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;

    GameTile(std::string, float, float, bool, bool);
    bool setUpSprite(std::string);

};

#endif