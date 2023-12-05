#!/bin/bash
arch -x86_64 g++ -std=c++17 src/main.cpp src/gameWorld.cpp src/gameTile.cpp src/door.cpp src/wall.cpp src/floor.cpp src/player.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
