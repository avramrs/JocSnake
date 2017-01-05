#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
int main() {
	
	int dirX = 1, dirY = 0;
	float SCALE = 25.0f;
	unsigned WIDTH = 32;
	unsigned HEIGHT = 24;
	unsigned score = 0;
	int tailLen = 0;
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");						//Window
	sf::RectangleShape shape;
	sf::RectangleShape tail[768];
	sf::RectangleShape tile;
	sf::RectangleShape food;
	food.setSize(sf::Vector2f(SCALE, SCALE));
	food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);                   //32 width 24 height
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);
	tile.setSize(sf::Vector2f(SCALE, SCALE));
	tile.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(SCALE , SCALE));
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color::Red);
	window.setVerticalSyncEnabled(true);
	sf::Time elapsed;
	sf::Clock clock;
	//FPS
	while (window.isOpen()) {
		
		elapsed = clock.getElapsedTime();


		sf::Event event;
		while (window.pollEvent(event)) {
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&dirX!=1)
			{
				dirX = -1;
				dirY = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&dirX!=-1)
			{
				dirX = 1;
				dirY = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&dirY!=1)                     //DIRECTION
			{
				dirX = 0;
				dirY = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&dirY!=-1)
			{
				dirX = 0;
				dirY = 1;
			}
				// left key is pressed: move our character
				
			

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (food.getGlobalBounds() == shape.getGlobalBounds())
		{
			score += 1000;
			
			food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE);       //EAT
			tailLen++;
			std::cout << tailLen << std::endl;
		}

		if (elapsed.asMilliseconds() > 175) 
		{
			
			for (int i = tailLen-2; i >=0; i--)
			{
				tail[i+1] = tail[i];
			}
			tail[0] = shape;
			shape.move(dirX*SCALE, dirY*SCALE);                                       //MOVE
			
			
			if (shape.getPosition().x < 0)
			{
				shape.setPosition(775, shape.getPosition().y);
			}
			if (shape.getPosition().x > 775)
			{
				shape.setPosition(0, shape.getPosition().y);                          //EDGE
			}
			if (shape.getPosition().y < 0)
			{
				shape.setPosition(shape.getPosition().x, 575);
			}
			if (shape.getPosition().y > 575) 
			{
				shape.setPosition(shape.getPosition().x, 0);
			}
			for (int i = 0; i < tailLen; i++)
			{
				if (tail[i].getGlobalBounds() == shape.getGlobalBounds())
					window.close();
			}
			
			clock.restart();
		}
			
		
		window.clear();
		
		for (int i = 0; i <= 64; i++)
			for (int j = 0; j <= 80; j++)
			{
				tile.setPosition(j*SCALE+2.5, i*SCALE+2.5);                              //DRAW
				window.draw(tile);
			}
		for (int i = 0; i < tailLen; i++)
		{
			window.draw(tail[i]);
			std::cout << tail[i].getPosition().x << " " << tail[i].getPosition().y << "|||||";
		}
		std::cout << std::endl;
			window.draw(shape);
		
		window.draw(food);
		window.display();
	}

}