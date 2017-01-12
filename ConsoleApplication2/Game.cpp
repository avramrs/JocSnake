#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <fstream>
#include "Snake.h"
#include "Items.h"
using namespace std;


fstream scoreboardFile;
ifstream gsaf;
short  HUD_SPACE = 50;

int main()
{
	short WIDTH = 32;
	short HEIGHT = 24;
	short timeSet = 175;							//time== 175 normal//time==100 fast//time==250 slow


	sf::RenderWindow window(sf::VideoMode(800, 600 + HUD_SPACE), "Snake");						//Window
	window.setVerticalSyncEnabled(true);


	srand(time(NULL));

	HUD.setSize(sf::Vector2f(800, 50));
	HUD.setFillColor(sf::Color::Black);
	HUD.setPosition(0, 0);
	item.setPosition(-10, -10);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	food.setSize(sf::Vector2f(SCALE, SCALE));
	food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);                   //32 width 24 height
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);
	tile.setSize(sf::Vector2f(SCALE, SCALE));
	tile.setFillColor(sf::Color::Green);
	item.setSize(sf::Vector2f(SCALE, SCALE));
	item.setFillColor(sf::Color::Black);
	snakeHead.setSize(sf::Vector2f(SCALE, SCALE));
	snakeHead.setPosition(0, HUD_SPACE);
	snakeHead.setFillColor(sf::Color::Red);
	sf::Time elapsed;
	sf::Clock clock;
	if (!gameFont.loadFromFile("8-BIT WONDER.ttf"))
		cout << "fail";
	sf::Text scoreText("SCORE", gameFont);
	sf::Text scoreValue('0', gameFont);
	sf::Text timerValue('0', gameFont);
	timerValue.setFillColor(sf::Color::White);
	timerValue.setPosition(425, 10);
	scoreValue.setFillColor(sf::Color::White);
	scoreValue.setPosition(180, 10);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(25, 10);
	/////////////MENU///////////
	sf::Text singleplayerText("SINGLEPLAYER", gameFont);
	sf::Text multiplayerText("MULTIPLAYER", gameFont);
	sf::Text scoreboardText("SCOREBOARD", gameFont);
	sf::Text shopText("SHOP", gameFont);
	sf::Text exitText("EXIT", gameFont);
	singleplayerText.setFillColor(sf::Color::White);
	multiplayerText.setFillColor(sf::Color::White);
	scoreboardText.setFillColor(sf::Color::White);
	shopText.setFillColor(sf::Color::White);
	exitText.setFillColor(sf::Color::White);
	singleplayerText.setPosition(220,200 );
	multiplayerText.setPosition(226, 250);
	scoreboardText.setPosition(250, 300);
	shopText.setPosition(329, 350);
	exitText.setPosition(335, 400);
	////////////////////SCOREBOARD/////////
	string line;
	sf::Text scoreboardFileText("", gameFont);
	scoreboardFileText.setFillColor(sf::Color::White);
	scoreboardFileText.setPosition(100, 50);
	short linePosition = 50;
	///////////////////??????????/////////////
	sf::Text r3a0roe("", gameFont);
	r3a0roe.setFillColor(sf::Color::Yellow);
	r3a0roe.setPosition(350, 300);
	gsaf.open("asdf.txt");
	getline(gsaf, line);
	r3a0roe.setString(line);
	gsaf.close();
	////////////////////////////////////////////////////////////MAIN_LOOP////////////////////////////////////////////////////////////
	while (window.isOpen())
	{
//////////////////////////////////////////////////////MENU//////////////////////////////////////////////////
		if (menu)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && selectedLine != 0)
					selectedLine--;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && selectedLine != 4)
					selectedLine++;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					switch (selectedLine)
					{
					case 0:
					{
						alive = 1;
						menu = 0;
						break;
					}
					case 1:
					{
						menu = 0;
						break;
					}
					case 2:
					{
						scoreboard = 1;
						menu = 0;
						break;
					}
					case 3:
					{
						shop = 1;
						menu = 0;
						break;
					}
					case 4:
					{
						window.close();
						break;
					}
					}
				}
			}
			switch (selectedLine) 
			{
			case 0:
			{
				singleplayerText.setFillColor(sf::Color::Yellow);
				multiplayerText.setFillColor(sf::Color::White);
				break;
			}
			case 1:
			{
				multiplayerText.setFillColor(sf::Color::Yellow);
				singleplayerText.setFillColor(sf::Color::White);
				scoreboardText.setFillColor(sf::Color::White);
				break;
			}
			case 2:
			{
				multiplayerText.setFillColor(sf::Color::White);
				scoreboardText.setFillColor(sf::Color::Yellow);
				shopText.setFillColor(sf::Color::White);
				break;
			}
			case 3:
			{
				scoreboardText.setFillColor(sf::Color::White);
				shopText.setFillColor(sf::Color::Yellow);
				exitText.setFillColor(sf::Color::White);
				break;
			}
			case 4:
			{
				shopText.setFillColor(sf::Color::White);
				exitText.setFillColor(sf::Color::Yellow);
				break;
			}
			}
			window.clear();
			window.draw(singleplayerText);
			window.draw(multiplayerText);
			window.draw(scoreboardText);
			window.draw(shopText);
			window.draw(exitText);
			window.display();
		}
////////////////////////////////////////////////SCOREBOARD//////////////////////////////////////////////////
		else if (scoreboard)
		{
			if (scoreboardOpened == false) 
			{
				scoreboardFile.open("scoreboard.txt");
				window.clear();
				if (scoreboardFile.is_open())
				{
					while (getline(scoreboardFile, line))
					{
						scoreboardFileText.setString(line);
						window.draw(scoreboardFileText);
						linePosition += 50;
						scoreboardFileText.setPosition(100, linePosition);
					}
					scoreboardOpened = 1;
					scoreboardFileText.setString("PRESS BACKSPACE TO CONTINUE");
					scoreboardFileText.setPosition(20, linePosition);
					scoreboardFileText.setFillColor(sf::Color::Red);
					window.draw(scoreboardFileText);
				}
				scoreboardFile.close();
				scoreboardFile.clear();
				window.display();
			}
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					scoreboard = 0;
					menu = 1;
					scoreboardOpened = 0;
					linePosition= 50;
					scoreboardFileText.setFillColor(sf::Color::White);
					scoreboardFileText.setPosition(100, linePosition);
				}
			}
		}
///////////////////////////////////////////////////////////SINGLEPLAYER/////////////////////////////////////////////////
		else if(alive)
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dirX != -1)
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

		if (itemTimer > 30)
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
				itemTimer = 0;
				std::cout << "SPEED UP";
				break;
			}
			case 1:
			{
				timeSet = 250;
				itemTimer = 0;
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

			itemTimer = 0;

		}
		if (itemSet == false)
		{

			if (itemTimer > 30)
			{
				itemSet = true;
				itemType = rand() % 3;
				item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
				set = false;
				while (set != true)
				{
					set = true;
					item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
					for (int i = 0; i < tailLen - 1; i++)
					{
						if (item.getGlobalBounds() == tail[i].getGlobalBounds())
						{
							item.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
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

			food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
			while (set != false)
			{
				set = false;

				for (int i = 0; i < tailLen - 1; i++)
				{
					if (food.getGlobalBounds() == tail[i].getGlobalBounds())
					{
						food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
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
		}
		////////////////////////////////////////////////////////////1FRAME////////////////////////////////////////////////////////////
		if (elapsed.asMilliseconds() > 100)
		{
			gameTimer += 100;
			HUDtimer += 100;
			clock.restart();
		}

		if (HUDtimer >= 1000)
		{
			HUDtimer = 0;
			timer++;
		}

		if (gameTimer > timeSet)
		{
			itemTimer++;
			std::cout << itemTimer << std::endl;
			snakeMove();
			snakeOutOfBounds();
			for (int i = 0; i < tailLen; i++)
			{
				if (tail[i].getGlobalBounds() == snakeHead.getGlobalBounds())
				{
					alive = 0;
					menu = 1;
					score = 0;
					timer = 0;
					snakeHead.setPosition(0, HUD_SPACE);
					tailLen = 0;
					dirX = 1;
					dirY = 0;
					itemSet = false;
					item.setPosition(-10, -10);
					itemTimer = 0;
				}
			}
			gameTimer = 0;
		}

		////////////////////////////////////////////////////////////DRAW////////////////////////////////////////////////////////////		
		scoreString = to_string(score);
		scoreValue.setString(scoreString);
		timerString = to_string(timer);
		timerValue.setString(timerString);
		window.clear();
		window.draw(HUD);
		window.draw(scoreText);
		window.draw(scoreValue);
		window.draw(timerValue);
		for (int i = 2; i <= 66; i++)
			for (int j = 0; j <= 80; j++)
			{
				tile.setPosition(j*SCALE + 2.5, i*SCALE + 2.5);
				window.draw(tile);
			}
		for (int i = 0; i < tailLen; i++)
		{
			window.draw(tail[i]);
		}
		window.draw(snakeHead);
		if (itemSet == true)
			window.draw(item);

		window.draw(food);
		window.display();
	}
	else if (shop)
	{
		window.clear();
		window.draw(r3a0roe);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				shop = 0;
				menu = 1;
			}
		}
	}
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