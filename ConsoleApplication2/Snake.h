#pragma once
#include <SFML/Graphics.hpp>
short dirX = 1, dirY = 0;
int tailLen = 0;
float SCALE = 25.0f;
bool alive = false;
sf::RectangleShape snakeHead;
sf::RectangleShape tail[768];					//WIDTH*HEIGHT=768
void snakeMove(bool multiplayer);
void snakeOutOfBounds(bool multiplayer);
////////////////2nd SNAKE//////////////////
short dirX2 = -1, dirY2 = 0;
int tailLen2 = 0;
sf::RectangleShape enemySnakeHead;
sf::RectangleShape enemyTail[768];