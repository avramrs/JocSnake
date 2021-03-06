#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Snake.h"
#include "Items.h"
using namespace std;


ifstream scoreboardFile;
ofstream scoreboardFileOutput;
ifstream gsaf;
short  HUD_SPACE = 50;

int main()
{
	short WIDTH = 32;
	short HEIGHT = 24;
	short timeSet = 175;							//time== 175 normal//time==100 fast//time==250 slow


	sf::RenderWindow window(sf::VideoMode(800, 600 + HUD_SPACE), "Snake");						//Window
	window.setVerticalSyncEnabled(true);
	/*sf::Texture tileTexture;
	if (!tileTexture.loadFromFile("Grass.png"))
		cout << "ERROR";
	tile.setTexture(&tileTexture);*/
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
	///////////////////MULTIPLAYER/////////////////
	enemySnakeHead.setSize(sf::Vector2f(SCALE, SCALE));
	enemySnakeHead.setPosition(800, 600);
	enemySnakeHead.setFillColor(sf::Color::Red);
	////////////////////SCOREBOARD/////////
	std::string scoreboardVector[12];
	std::string line;
	sf::Text scoreboardFileText("", gameFont);
	scoreboardFileText.setFillColor(sf::Color::White);
	scoreboardFileText.setPosition(100, 50);
	short linePosition = 50;
	sf::Text newHighscoreText("NEW HIGHSCORE", gameFont);
	sf::Text newHighscoreText2("ENTER YOUR NAME", gameFont);
	newHighscoreText2.setPosition(200, 250);
	newHighscoreText2.setFillColor(sf::Color::White);
	newHighscoreText.setPosition(200, 200);
	newHighscoreText.setFillColor(sf::Color::White);
	std::string enteredText;
	sf::Text newName("",gameFont);
	newName.setPosition(200, 300);
	newName.setFillColor(sf::Color::White);
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
		if (menu==true)
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
						alive = 1;
						multiplayer = 1;
						enemySnakeHead.setPosition(775, 575);
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
		else if (newHighScore == true)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						enteredText += static_cast<char>(event.text.unicode);
						newName.setString(enteredText);
					}
				}
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				newHighScore = 0;
				menu = 1;
				scoreboardFile.open("scoreboard.txt");
				for (int i = 0; i < scoreboardLineCount; i++)
				{
					getline(scoreboardFile, line);
					scoreboardVector[i] = line;
					if (i+1 == newHighScoreLine)
					{
						scoreboardVector[i] = enteredText;
						i++;
						scoreString = to_string(score);
						scoreboardVector[i]=scoreString;
						score = 0;
					}
				}
				scoreboardFile.close();
				scoreboardFileOutput.open("scoreboard.txt");
				for (int i = 0; i < scoreboardLineCount; i++)
				{
					line = scoreboardVector[i];
					scoreboardFileOutput << line<<endl;
				}
				scoreboardFileOutput.close();
				enteredText.assign("");
				newName.setString(enteredText);
			}

			window.clear();
			window.draw(newHighscoreText);
			window.draw(newHighscoreText2);
			window.draw(newName);
			window.display();
		}
/////////////////////////////////////////////////////////////////
		else if (scoreboard==true)
		{
			if (scoreboardOpened == false) 
			{
				scoreboardFile.open("scoreboard.txt");
				window.clear();
				if (scoreboardFile.is_open())
				{
					for(int i=0;i<scoreboardLineCount;i++)
					{
						getline(scoreboardFile, line);
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
		else if(alive==true)
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
			if (multiplayer==true)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dirX2 != 1)
				{
					dirX2 = -1;
					dirY2 = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dirX2 != -1)
				{
					dirX2 = 1;
					dirY2 = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dirY2 != 1)                     //DIRECTION
				{
					dirX2 = 0;
					dirY2 = -1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dirY2 != -1)
				{
					dirX2 = 0;
					dirY2 = 1;
				}
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
				timeSet = 75;
				itemTimer = 0;
				std::cout << "SPEED UP";
				break;
			}
			case 1:
			{
				timeSet = 300;
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
				if (multiplayer == true)
					itemType = rand() % 2;
				else
					itemType = rand() % 3;
				switch (itemType)
				{
				case 0:
				{
					item.setFillColor(sf::Color::Black);
					break;
				}
				case 1:
				{
					item.setFillColor(sf::Color::Blue);
					break;
				}
				case 2:
				{
					item.setFillColor(sf::Color::Yellow);
					break;
				}
				}
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
				}
			}
		}


		if (food.getGlobalBounds() == snakeHead.getGlobalBounds())
		{
			if(multiplayer==false)
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
		if(multiplayer==true)
		if (food.getGlobalBounds() == enemySnakeHead.getGlobalBounds())
		{
			food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
			while (set != false)
			{
				set = false;

				for (int i = 0; i < tailLen2 - 1; i++)
				{
					if (food.getGlobalBounds() == enemyTail[i].getGlobalBounds())
					{
						food.setPosition((rand() % WIDTH)*SCALE, (rand() % HEIGHT)*SCALE + HUD_SPACE);
						set = true;

					}
				}
			}
			set = true;
			tailLen2++;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))							//CHEAT
		{
			tailLen++;
			score += 100;
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
			snakeMove(multiplayer);
			snakeOutOfBounds(multiplayer);
			gameTimer = 0;
			////////////////////////////////////////DEATH//////////////////////////////////////////////
			for (int i = 0; i < tailLen; i++)
			{
				if (tail[i].getGlobalBounds() == snakeHead.getGlobalBounds())
				{
					alive = 0;
					if(multiplayer==true)
					winner = 2;//player2 Wins;
				}
				if (enemySnakeHead.getGlobalBounds() == tail[i].getGlobalBounds())
				{
					if(multiplayer==true)
					winner = 1;//player1 Wins;
					alive = 0;
				}
			}
			if (multiplayer)
			{
				for (int i = 0; i < tailLen2; i++)
				{
					if (enemyTail[i].getGlobalBounds() == enemySnakeHead.getGlobalBounds())
					{
						alive = 0;
						winner = 1;//player1 Wins;
					}
					if (snakeHead.getGlobalBounds() == enemyTail[i].getGlobalBounds())
					{
						winner = 2;//player2 Wins;
						alive = 0;
					}
				}
			}
			if (snakeHead.getGlobalBounds() == enemySnakeHead.getGlobalBounds())
			{
				alive = 0;
				winner = 3;
			}
		}
		////////////////////////////////////////////////////////////DRAW////////////////////////////////////////////////////////////		
		scoreString = to_string(score);
		scoreValue.setString(scoreString);
		timerString = to_string(timer);
		timerValue.setString(timerString);
		window.clear();
		window.draw(HUD);
		if (multiplayer == false && winner==0)
		{
			window.draw(scoreText);
			window.draw(scoreValue);
		}
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
		if (multiplayer == true)
		{
			for (int i = 0; i < tailLen2; i++)
			{
				window.draw(enemyTail[i]);
			}
			window.draw(enemySnakeHead);
		}
		if (itemSet == true)
			window.draw(item);
		if (winner != 0)
		{
			if (winner == 1)
			{
				sf::Text PWins("PLAYER 1 WINS", gameFont);
				PWins.setPosition(25, 10);
				window.draw(PWins);
			}
			if (winner == 2)
			{
				sf::Text PWins("PLAYER 2 WINS", gameFont);
				PWins.setPosition(25, 10);
				window.draw(PWins);
			}
			if (winner == 3)
			{
				sf::Text PWins("NOBODY WINS", gameFont);
				PWins.setPosition(25, 10);
				window.draw(PWins);
			}

		}
		window.draw(food);
		window.display();
		if (winner != 0)
		{
			Sleep(5000);
			winner = 0;
		}
		if (alive == 0)
		{
			scoreboardFile.open("scoreboard.txt");
			for (int i = 0; i < scoreboardLineCount; i++)
			{
				getline(scoreboardFile, line);
				if (i%2==0&&i!=0)
				{
					currentScore = stoll (line);
					if (currentScore < score)
					{
						newHighScore = 1;
						newHighScoreLine = i;
						i = scoreboardLineCount;
					}
				}
				
			}
			scoreboardFile.close();
			if (newHighScore != 1)
			{
				menu = 1;
				score = 0;
			}
			timer = 0;
			snakeHead.setPosition(0, HUD_SPACE);
			tailLen = 0;
			dirX = 1;
			dirY = 0;
			itemSet = false;
			item.setPosition(-10, -10);
			itemTimer = 0;
			if (multiplayer == true)
			{
				tailLen2 = 0;
				dirX2 = -1;
				dirY2 = 0;
				multiplayer = false;
				enemySnakeHead.setPosition(800, 600);
			}
		}
	}
	
/////////////////////????////////////////////////////
	else if (shop==true)
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
void snakeMove(bool multiplayer)
{
	for (int i = tailLen - 2; i >= 0; i--)
	{
		tail[i + 1] = tail[i];
	}
	tail[0] = snakeHead;
	snakeHead.move(dirX*SCALE, dirY*SCALE);
	if (multiplayer == true);
	{
		for (int i = tailLen2 - 2; i >= 0; i--)
		{
			enemyTail[i + 1] = enemyTail[i];
		}
		enemyTail[0] = enemySnakeHead;
		enemySnakeHead.move(dirX2*SCALE, dirY2*SCALE);
	}
}
void snakeOutOfBounds(bool multiplayer)
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
	if (multiplayer == true)
	{
		if (enemySnakeHead.getPosition().x < 0)
		{
			enemySnakeHead.setPosition(775, enemySnakeHead.getPosition().y);
		}
		if (enemySnakeHead.getPosition().x > 775)
		{
			enemySnakeHead.setPosition(0, enemySnakeHead.getPosition().y);
		}
		if (enemySnakeHead.getPosition().y < 0 + HUD_SPACE)
		{
			enemySnakeHead.setPosition(enemySnakeHead.getPosition().x, 575 + HUD_SPACE);
		}
		if (enemySnakeHead.getPosition().y > 575 + HUD_SPACE)
		{
			enemySnakeHead.setPosition(enemySnakeHead.getPosition().x, 0 + HUD_SPACE);
		}
	}
}