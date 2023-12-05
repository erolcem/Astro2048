#include "../headers/gameTile.hpp"

GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool door) {
    if(!setUpSprite(textureName)) {
        return;
    }

    pos = sf::Vector2f(x, y);
    sprite.setPosition(pos);
    isPassable = passable;
    isDoor = door;
}

const int GameTile::TILESIZE = 25;

bool GameTile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, TILESIZE, TILESIZE));
    return true;
}
