#include <SFML/Graphics.hpp>
#include <iostream>
int main() {

	int dirX = 1, dirY = 0;
	float scl = 25.0f;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");				//Window
	sf::RectangleShape shape;
	sf::RectangleShape tile;
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);
	tile.setSize(sf::Vector2f(scl, scl));
	tile.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(scl , scl));
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&dirY!=1)
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
		if (elapsed.asMilliseconds() > 200) 
		{
			shape.move(dirX*scl, dirY*scl);
			clock.restart();
		}
			
		
		window.clear();
		
		for (int i = 0; i <= 64; i++)
			for (int j = 0; j <= 80; j++)
			{
				tile.setPosition(j*scl+2.5, i*scl+2.5);
				window.draw(tile);
			}
		window.draw(shape);
		window.display();
	}

}