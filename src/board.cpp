#include "../headers/board.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() {
  for (int i = 0; i < boardMatrix.size(); i++) {
    for (int j = 0; j < boardMatrix[i].size(); j++) {
      boardMatrix[i][j] = Tile(true, false);
    }
  }
}

void Board::draw(sf::RenderWindow &window) {
  for (int i = 0; i < boardMatrix.size(); i++) {
    for (int j = 0; j < boardMatrix[i].size(); j++) {
      boardMatrix[i][j].draw(window, i, j);
    }
  }
}

void Board::SpawnRandomTile() {
  // seed random time
  std::srand(std::time(0));

  // create a vector to store coordinates of empty positions
  std::vector<std::pair<int, int>> emptyPositions;
  // iterate through board, add coordinates of empty spots to vector
  for (int i = 0; i < boardMatrix.size(); ++i) {
    for (int j = 0; j < boardMatrix[i].size(); ++j) {
      if (boardMatrix[i][j].isEmpty) {
        emptyPositions.push_back(std::make_pair(i, j));
      }
    }
  }

  // check if there are empty spaces, to spawn tiles
  if (!emptyPositions.empty()) {
    // randomly select an empty position
    int randomIndex = std::rand() % emptyPositions.size();
    int randomValue = (std::rand() % 2 + 1) * 2; // choose 2 or 4

    // place the new tile in selected position
    boardMatrix[emptyPositions[randomIndex].first]
               [emptyPositions[randomIndex].second]
                   .isEmpty = false;
    boardMatrix[emptyPositions[randomIndex].first]
               [emptyPositions[randomIndex].second]
                   .value = randomValue;

    // for bool. ignore
    // return true;
  } // else {
    //  No empty positions, game over
    // return false;
  //}
}
// boardMatrix[0].size()
// boardMatrix.size()

void Board::moveLeft() {
  // iterate through each column
  for (int j = 0; j < boardMatrix[0].size(); ++j) {
    // iterate through each row (no need to check the 1st row for upward
    // movement)
    for (int i = 1; i < boardMatrix.size(); ++i) {
      // checks if matrix is empty
      if (!boardMatrix[i][j].isEmpty) {
        int k = i;
        // loop will iterate upward through the column as long as there is empty
        // space above the tile or a tile that has the same value as the current
        // tile
        while (k > 0 &&
               (boardMatrix[k - 1][j].isEmpty ||
                boardMatrix[k - 1][j].value == boardMatrix[k][j].value)) {
          if (boardMatrix[k - 1][j].isEmpty) {
            std::swap(boardMatrix[k][j], boardMatrix[k - 1][j]);
            noMovement = false;
          } else if (boardMatrix[k - 1][j].value == boardMatrix[k][j].value) {
            // merge tiles with the same value
            boardMatrix[k - 1][j].value *= 2;
            counter += boardMatrix[k - 1][j].value;
            boardMatrix[k][j].isEmpty = true;
            noMovement = false;
            // boardMatrix[k][j].value = 0;
          }
          // remove a k, so the loop checks the tile above
          --k;
        }
      }
    }
  }
  // after moving, spawn a random tile
  if (!noMovement) {
    SpawnRandomTile();
    noMovement = true;
  }
}

void Board::moveRight() {
  // iterate through each column
  for (int j = 0; j < boardMatrix[0].size(); ++j) {
    // move tiles down within the column
    for (int i = boardMatrix.size() - 2; i >= 0; --i) {
      if (!boardMatrix[i][j].isEmpty) {
        int k = i;
        while (k < boardMatrix.size() - 1 &&
               (boardMatrix[k + 1][j].isEmpty ||
                boardMatrix[k + 1][j].value == boardMatrix[k][j].value)) {
          if (boardMatrix[k + 1][j].isEmpty) {
            std::swap(boardMatrix[k][j], boardMatrix[k + 1][j]);
            noMovement = false;
          } else if (boardMatrix[k + 1][j].value == boardMatrix[k][j].value) {
            boardMatrix[k + 1][j].value *= 2;
            counter += boardMatrix[k + 1][j].value;
            boardMatrix[k][j].isEmpty = true;
            noMovement = false;
            // boardMatrix[k][j].value = 0;
          }
          ++k;
        }
      }
    }
  }
  if (!noMovement) {
    SpawnRandomTile();
    noMovement = true;
  }
}

void Board::moveUp() {
  // iterate through each row
  for (int i = 0; i < boardMatrix[0].size(); ++i) {
    // iterate through columns
    for (int j = 1; j < boardMatrix.size(); ++j) {
      if (!boardMatrix[i][j].isEmpty) {
        int k = j;
        // loop will iterate upward through the column as long as there is empty
        // space above the tile or a tile that has the same value as the current
        // tile
        while (k > 0 &&
               (boardMatrix[i][k - 1].isEmpty ||
                boardMatrix[i][k - 1].value == boardMatrix[i][k].value)) {
          // if spot above tile is empty, lift current tile up
          if (boardMatrix[i][k - 1].isEmpty) {
            std::swap(boardMatrix[i][k], boardMatrix[i][k - 1]);
            noMovement = false;
          } else if (boardMatrix[i][k - 1].value == boardMatrix[i][k].value) {
            boardMatrix[i][k - 1].value *= 2;
            counter += boardMatrix[i][k - 1].value;
            boardMatrix[i][k].isEmpty = true;
            noMovement = false;
            // boardMatrix[k][j].value = 0;
          }
          --k;
        }
      }
    }
  }

  if (!noMovement) {
    SpawnRandomTile();
    noMovement = true;
  }
}

void Board::moveDown() {
  // iterate through each row
  for (int i = 0; i < boardMatrix[0].size(); ++i) {
    // iterate through each column
    for (int j = boardMatrix.size() - 2; j >= 0; --j) {
      if (!boardMatrix[i][j].isEmpty) {
        int k = j;
        while (k < boardMatrix.size() - 1 &&
               (boardMatrix[i][k + 1].isEmpty ||
                boardMatrix[i][k + 1].value == boardMatrix[i][k].value)) {
          if (boardMatrix[i][k + 1].isEmpty) {
            std::swap(boardMatrix[i][k], boardMatrix[i][k + 1]);
            noMovement = false;
          } else if (boardMatrix[i][k + 1].value == boardMatrix[i][k].value) {
            boardMatrix[i][k + 1].value *= 2;
            counter += boardMatrix[i][k + 1].value;
            boardMatrix[i][k].isEmpty = true;
            noMovement = false;
            // boardMatrix[k][j].value = 0;
          }
          ++k;
        }
      }
    }
  }
  if (!noMovement) {
    SpawnRandomTile();
    noMovement = true;
  }
}
