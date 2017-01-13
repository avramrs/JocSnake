#pragma once
unsigned long long score = 0;
sf::RectangleShape food;
sf::RectangleShape item;
sf::RectangleShape tile;
sf::RectangleShape HUD;
sf::String scoreString;
sf::String timerString;
sf::Font gameFont;

short itemType;
short HUDtimer = 0;
short selectedLine = 0;
unsigned int itemTimer=0;
unsigned int powerUpTimer = 0;
unsigned int gameTimer = 0;
unsigned int timer = 0;
bool menu = true;
bool set = true;
bool itemSet = false;
bool scoreboard = false;
bool scoreboardOpened = false;
bool shop = false;
bool multiplayer = false;
short winner = 0;