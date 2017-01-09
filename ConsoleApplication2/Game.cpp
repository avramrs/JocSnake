#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Snake.h"
#include "Items.h"

int main() 
{

	unsigned WIDTH = 32;
	unsigned HEIGHT = 24;
	short timeSet = 175;							//time== 175 normal//time==100 fast//time==250 slow
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");						//Window
	sf::RectangleShape tile;
	item.setPosition(-10, -10);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	food.setSize(sf::Vector2f(SCALE, SCALE));
	food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);                   //32 width 24 height
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);
	tile.setSize(sf::Vector2f(SCALE, SCALE));
	tile.setFillColor(sf::Color::Green);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	item.setFillColor(sf::Color::Black);
	snakeHead.setSize(sf::Vector2f(SCALE, SCALE));
	snakeHead.setPosition(0, 0);
	snakeHead.setFillColor(sf::Color::Red);
	window.setVerticalSyncEnabled(true);
	sf::Time elapsed;
	sf::Clock clock;
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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

		if (item.getGlobalBounds() == snakeHead.getGlobalBounds())
		{
			itemSet = false;
			item.setPosition(-10, -10);
			/*switch (itemType) :
			{
			case 0:
			case 1:
			case 2:

			}*/
			itemTimer=0;
			std::cout << "hat";
		}
			if (itemSet == false)
			{
			
				if (itemTimer > 28)
				{
					itemSet = true;
					itemType = rand() % 3;
					item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);
					set = false;
						while (set != true)
						{
							set = true;
							item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);
							for (int i = 0; i < tailLen - 1; i++)
							{
								if (item.getGlobalBounds() == tail[i].getGlobalBounds())
								{
									item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);
									set = false;
									

								}
							}
							std::cout << "Set";
						}
				}
			}

			
		if (food.getGlobalBounds() == snakeHead.getGlobalBounds())
		{
			score += 1000;
			food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);
			while (set != false)
			{
				set = false;
				
				for (int i = 0; i < tailLen - 1; i++)
				{
					if (food.getGlobalBounds() == tail[i].getGlobalBounds())
					{
						food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);
						set = true;
						
					}
				}
			}
			set = true;
			tailLen++;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))							//CHEAT
		{
			tailLen++;
			
			std::cout << timeSet << std::endl;
		}
////////////////////////////////////////////////////////////1FRAME////////////////////////////////////////////////////////////

		if (elapsed.asMilliseconds() > timeSet) 
		{
			itemTimer++;
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
		window.clear();
		
		for (int i = 0; i <= 64; i++)
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
	if (snakeHead.getPosition().y < 0)
	{
		snakeHead.setPosition(snakeHead.getPosition().x, 575);
	}
	if (snakeHead.getPosition().y > 575)
	{
		snakeHead.setPosition(snakeHead.getPosition().x, 0);
	}
}
