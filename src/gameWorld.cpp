#include "../headers/gameWorld.hpp"

GameWorld::GameWorld() {
    setUpInitialState();
    setUpTiles();
    player = std::make_unique<Player>(playerPos.x * GameTile::TILESIZE, playerPos.y * GameTile::TILESIZE);
}


void GameWorld::setUpInitialState() {
    doorPos = sf::Vector2i(1,0);
    playerPos = sf::Vector2i(13,23);
    setUpEnemyPositions();
}

void GameWorld::setUpEnemyPositions() {
    enempyPos.clear();
    enempyPos.push_back(sf::Vector2i(0,2));
    enempyPos.push_back(sf::Vector2i(6,0));
    enempyPos.push_back(sf::Vector2i(2,7));
}

void GameWorld::setUpTiles() {
    tiles.clear();

    for(int i = 0; i < map.size(); i++) {
        std::vector<std::unique_ptr<GameTile>> row;
        for(int j = 0; j < map[i].size(); j++) {
            switch(map[i][j]) {
                case 'w':
                    row.push_back(std::make_unique<Wall>(j * GameTile::TILESIZE, i * GameTile::TILESIZE));
                    break;
                case 'f':
                    row.push_back(std::make_unique<Floor>(j * GameTile::TILESIZE, i * GameTile::TILESIZE));
                    break;
                case 'd':
                    row.push_back(std::make_unique<Door>(j * GameTile::TILESIZE, i * GameTile::TILESIZE)); 
                    break;
            }
        }
    tiles.push_back(std::move(row));
    }

}
