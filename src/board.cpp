#include "../headers/board.hpp"

Board::Board() {
    for (int i = 0; i < boardMatrix.size(); i++) {
        for (int j = 0; boardMatrix[i].size() < 4; j++) {
            boardMatrix[i][j] = Tile(true, false); 
        }
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (int i = 0; i < boardMatrix.size(); i++) {
        for (int j = 0; j < boardMatrix[i].size(); j++) {
            boardMatrix[i][j].draw(window, i, j);
        }
    }
}