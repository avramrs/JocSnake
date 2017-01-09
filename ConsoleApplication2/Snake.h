#pragma once
#include <SFML/Graphics.hpp>
int dirX = 1, dirY = 0;
int tailLen = 0;
float SCALE = 25.0f;
sf::RectangleShape snakeHead;
sf::RectangleShape tail[768];
void snakeMove();
void snakeOutOfBounds();