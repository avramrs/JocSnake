#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <fstream>
#include "Snake.h"
#include "Items.h"
using namespace std;
ifstream scoreboard("scoreboard.txt");

short  HUD_SPACE = 50;
int main() 
{
	short WIDTH = 32;
	short HEIGHT = 24;
	short timeSet = 175;							//time== 175 normal//time==100 fast//time==250 slow
	
	sf::String scoreString;
	sf::RenderWindow window(sf::VideoMode(800, 600+HUD_SPACE), "Snake");						//Window
	sf::RectangleShape tile;
	sf::RectangleShape HUD;
	sf::Font gameFont;

	HUD.setSize(sf::Vector2f(800, 50));
	HUD.setFillColor(sf::Color::Black);
	HUD.setPosition(0, 0);
	item.setPosition(-10, -10);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	food.setSize(sf::Vector2f(SCALE, SCALE));
	food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);                   //32 width 24 height
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);
	tile.setSize(sf::Vector2f(SCALE, SCALE));
	tile.setFillColor(sf::Color::Green);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	item.setFillColor(sf::Color::Black);
	snakeHead.setSize(sf::Vector2f(SCALE, SCALE));
	snakeHead.setPosition(0, HUD_SPACE);
	snakeHead.setFillColor(sf::Color::Red);
	window.setVerticalSyncEnabled(true);
	sf::Time elapsed;
	sf::Clock clock;
	if (!gameFont.loadFromFile("8-BIT WONDER.ttf"))
		cout << "fail";
	sf::Text scoreText("SCORE", gameFont);
	sf::Text scoreValue('0', gameFont);
	scoreValue.setFillColor(sf::Color::White);
	scoreValue.setPosition(180, 10);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(25, 10);
		
////////////////////////////////////////////////////////////MAIN_LOOP////////////////////////////////////////////////////////////
	while (window.isOpen())
	{
		elapsed = clock.getElapsedTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dirX != 1)
			{
				dirX = -1;
				dirY = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&dirX!=-1)
			{
				dirX = 1;
				dirY = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dirY != 1)                     //DIRECTION
			{
				dirX = 0;
				dirY = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dirY != -1)
			{
				dirX = 0;
				dirY = 1;
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (powerUpTimer > 60)
		{
			timeSet = 175;													//RESET
		}
		if (item.getGlobalBounds() == snakeHead.getGlobalBounds())
		{
			itemSet = false;
			item.setPosition(-10, -10);
			switch (itemType) {
			case 0: {
				timeSet = 100;
				powerUpTimer = 0;
				std::cout << "SPEED UP";
				break;
			}
			case 1:
			{
				timeSet = 250;
				powerUpTimer = 0;
				std::cout << "SLOW DOWN";
				break;
			}
			case 2: 
			{
				score *= 2;
				std::cout << "DOUBLE SCORE";
				break; 
			}
			}
			
			itemTimer=0;
			
		}
			if (itemSet == false)
			{
			
				if (itemTimer > 30)
				{
					itemSet = true;
					itemType = rand() % 3;
					item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);
					set = false;
						while (set != true)
						{
							set = true;
							item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);
							for (int i = 0; i < tailLen - 1; i++)
							{
								if (item.getGlobalBounds() == tail[i].getGlobalBounds())
								{
									item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);
									set = false;
									

								}
							}
							std::cout << "Set";
						}
				}
			}

			
		if (food.getGlobalBounds() == snakeHead.getGlobalBounds())
		{
			score += 100;
			
			food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);
			while (set != false)
			{
				set = false;
				
				for (int i = 0; i < tailLen - 1; i++)
				{
					if (food.getGlobalBounds() == tail[i].getGlobalBounds())
					{
						food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE+HUD_SPACE);
						set = true;
						
					}
				}
			}
			set = true;
			tailLen++;
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))							//CHEAT
		{
			tailLen++;
			
			std::cout << timeSet << std::endl;
		}*/
////////////////////////////////////////////////////////////1FRAME////////////////////////////////////////////////////////////

		if (elapsed.asMilliseconds() > timeSet) 
		{
			itemTimer++;
			powerUpTimer += 2;
			std::cout << itemTimer << std::endl;
			snakeMove();                                     
			snakeOutOfBounds();
			for (int i = 0; i < tailLen; i++)
			{
				if (tail[i].getGlobalBounds() == snakeHead.getGlobalBounds())
					window.close();
			}
			clock.restart();
		}
			
////////////////////////////////////////////////////////////DRAW////////////////////////////////////////////////////////////		
		scoreString = to_string(score);
		scoreValue.setString(scoreString);
		window.clear();
		window.draw(HUD);
		window.draw(scoreText);
		window.draw(scoreValue);
		for (int i = 2; i <= 66; i++)
			for (int j = 0; j <= 80; j++)
			{
				tile.setPosition(j*SCALE+2.5, i*SCALE+2.5);                             
				window.draw(tile);
			}
		for (int i = 0; i < tailLen; i++)
		{
			window.draw(tail[i]);
		}
			window.draw(snakeHead);
			if(itemSet==true)
			window.draw(item);
		
		window.draw(food);
		window.display();
	}

}
////////////////////////////////////////////////////////////FUNCTIONS////////////////////////////////////////////////////////////
void snakeMove()
{
	for (int i = tailLen - 2; i >= 0; i--)
	{
		tail[i + 1] = tail[i];
	}
	tail[0] = snakeHead;
	snakeHead.move(dirX*SCALE, dirY*SCALE);
}
void snakeOutOfBounds()
{
	if (snakeHead.getPosition().x < 0)
	{
		snakeHead.setPosition(775, snakeHead.getPosition().y);
	}
	if (snakeHead.getPosition().x > 775)
	{
		snakeHead.setPosition(0, snakeHead.getPosition().y);
	}
	if (snakeHead.getPosition().y < 0+HUD_SPACE)
	{
		snakeHead.setPosition(snakeHead.getPosition().x, 575+HUD_SPACE);
	}
	if (snakeHead.getPosition().y > 575+HUD_SPACE)
	{
		snakeHead.setPosition(snakeHead.getPosition().x, 0+HUD_SPACE);
	}
}
