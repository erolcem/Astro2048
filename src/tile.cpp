#include "../headers/tile.hpp"
//#include "./drawTiles.cpp"
#include "../headers/constants.hpp"

Tile::Tile(bool empty, bool merging) {
    value = 0;
    isEmpty = empty;
    isMerging = merging;

    colourMap = {
    {0, sf::Color(140, 123, 90)}, // Keep the same color for 0
    {2, sf::Color(255, 0, 0)}, // Red
    {4, sf::Color(255, 127, 0)}, // Orange
    {8, sf::Color(255, 255, 0)}, // Yellow
    {16, sf::Color(0, 255, 0)}, // Green
    {32, sf::Color(0, 0, 255)}, // Blue
    {64, sf::Color(46, 43, 95)}, // Indigo
    {128, sf::Color(139, 0, 255)}, // Violet
    {256, sf::Color(255, 0, 255)}, // Magenta
    {512, sf::Color(255, 255, 255)}, // White
    {1024, sf::Color(127, 127, 127)}, // Gray
    {2048, sf::Color(0, 0, 0)}, // Black
    // Continue with other colors as needed
};
/**
    colourMap = {
    {0, sf::Color(140, 123, 90)},
    {2, sf::Color(191, 183, 166)},
    {4, sf::Color(209, 197, 169)},
    {8, sf::Color(224, 138, 72)},
    {16, sf::Color(242, 149, 78)},
    {32, sf::Color(237, 135, 57)},
    {64, sf::Color(242, 66, 2)},
    {128, sf::Color(227, 209, 143)},
    {256, sf::Color(232, 204, 100)},
    {512, sf::Color(240, 206, 81)},
    {1024, sf::Color(168, 135, 50)},
    {2048, sf::Color(232, 190, 37)},
    {4096, sf::Color(104, 158, 108)},
    {8192, sf::Color(88, 168, 94)},
    {16384, sf::Color(62, 156, 70)},
    {32768, sf::Color(37, 148, 46)},
    {65536, sf::Color(17, 128, 26)},
    {131072, sf::Color(52, 120, 209)},
};
*/
/**
    if (!font.loadFromFile("../fonts/arial.ttf")) //../fonts/
    {
        std::cout << "Error importing font\n";
    }
    */
}



void Tile::draw(sf::RenderWindow& window, int x, int y) {

    sf::RectangleShape tileDrawn(sf::Vector2f(TILESIZE - 2 * PADDING, TILESIZE - 2 * PADDING));
    tileDrawn.setPosition(x * TILESIZE + PADDING, y * TILESIZE + PADDING); 

    if (colourMap.count(value) > 0 && !isEmpty) {
        tileDrawn.setFillColor(colourMap[value]);
    } else {
        tileDrawn.setFillColor(colourMap[0]);
    }


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
    window.draw(tileDrawn);
    //window.draw(text);

}

void Tile::setValue(int NewVal) {
    value = NewVal;
}

