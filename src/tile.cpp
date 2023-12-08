#include "../headers/tile.hpp"

Tile::Tile(bool empty, bool merging) {
    value = 0;
    isEmpty = empty;
    isMerging = merging;
}

const int Tile::TILESIZE = 220;
const int Tile::PADDING = 10;

void Tile::draw(sf::RenderWindow& window, int x, int y) {
    sf::RectangleShape rectangle(sf::Vector2f(TILESIZE - 2 * PADDING, TILESIZE - 2 * PADDING));
    rectangle.setPosition(x * TILESIZE + PADDING, y * TILESIZE + PADDING); 
    rectangle.setFillColor(sf::Color(168, 135, 50));
    window.draw(rectangle);
}
