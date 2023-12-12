#include "../headers/tile.hpp"

Tile::Tile(bool empty, bool merging) {
    value = 0;
    isEmpty = empty;
    isMerging = merging;
/**
    if (!font.loadFromFile("../fonts/arial.ttf")) //../fonts/
    {
        std::cout << "Error importing font\n";
    }
    */
}

const int Tile::TILESIZE = 220;
const int Tile::PADDING = 10;


void Tile::draw(sf::RenderWindow& window, int x, int y) {
    sf::RectangleShape rectangle(sf::Vector2f(TILESIZE - 2 * PADDING, TILESIZE - 2 * PADDING));
    rectangle.setPosition(x * TILESIZE + PADDING, y * TILESIZE + PADDING); 
    rectangle.setFillColor(sf::Color(168, 135, 50));
/** 
    // Create a text
    sf::Text text;
    text.setFont(font); 

    // Convert the integer value to a string
    std::stringstream ss;
    ss << value;
    text.setString(ss.str()); 

    text.setCharacterSize(50); 
    text.setFillColor(sf::Color::Black); 
    text.setPosition(x * TILESIZE + PADDING, y * TILESIZE + PADDING); 
*/
    // Draw the rectangle and the text
    window.draw(rectangle);
    //window.draw(text);

}

void Tile::setValue(int NewVal) {
    value = NewVal;
}

