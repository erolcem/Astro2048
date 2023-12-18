#include <nlohmann/json.hpp>  // Include the JSON library

// these all go in board.cpp


// BELOW IS FUNCTION CALL:  
// myBoard.saveTiles();

void Board::saveTiles() {

    // Save the board to a JSON file
    nlohmann::json jsonBoard;
    for (int i = 0; i < boardMatrix.size(); ++i) {
        for (int j = 0; j < boardMatrix[i].size(); ++j) {
            jsonBoard[i][j]["isEmpty"] = boardMatrix[i][j].isEmpty;
            jsonBoard[i][j]["value"] = boardMatrix[i][j].value;
        }
    }

    // Save the JSON to a file (adjust the filename/path as needed)
    std::ofstream outputFile("board.json");
    if (outputFile.is_open()) {
        outputFile << jsonBoard.dump(4);  // Pretty-print with an indentation of 4 spaces
        outputFile.close();
    }
}

// BELOW IS FUNCTION CALL:
// myBoard.loadTiles();

void Board::loadTiles() {
    // Read the JSON from the file (adjust the filename/path as needed)
    std::ifstream inputFile("board.json");
    if (inputFile.is_open()) {
        nlohmann::json jsonBoard;
        inputFile >> jsonBoard;

        // Only load the values from the JSON into the existing boardMatrix
        for (int i = 0; i < boardMatrix.size(); ++i) {
            for (int j = 0; j < boardMatrix[i].size(); ++j) {
                boardMatrix[i][j].isEmpty = jsonBoard[i][j]["isEmpty"];
                boardMatrix[i][j].value = jsonBoard[i][j]["value"];
            }
        }

        inputFile.close();
    } else {
        // Handle the case when the file cannot be opened
        std::cerr << "Error: Unable to open the JSON file for reading.\n";
    }
}



// ====================================
// this onwards belongs in main.cpp


    // Ask the user if they want to load the last save
    std::cout << "Do you want to load the last save? (y/n): ";
    char response;
    std::cin >> response;

    if (response == 'y' || response == 'Y') {
        // Load the tiles from the JSON file
        myBoard.loadTiles();
        std::cout << "Tiles loaded from the last save.\n";
    } else {
        // The user chose not to load the last save, continue with the game
        std::cout << "Starting a new game.\n";
        // ... (other game initialization logic)
    }


      if (event.type == sf::Event::Closed) {
        
        myBoard.saveTiles(); // put it over here
        window.close();
      }
// at the end just before closing the window takes effect:
