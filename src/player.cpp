#include "../headers/player.hpp"

Player::Player(int x, int y) : GameTile("./images/pacman.jpeg", x, y, true, false) {

}

void Player::move(int dx, int dy) {
    pos.x += dx * GameTile::TILESIZE;
    pos.y += dy * GameTile::TILESIZE;


    sprite.setPosition(pos);
}