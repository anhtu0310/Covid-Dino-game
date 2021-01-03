/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#include"collision.h"
#include"common.h"
#include<sstream>
#include"Fruits.h"
#include"Obsticle.h"
#include"mainChar.h"
#include<Windows.h>
#include <conio.h>
bool runtheGameMode1(void);
bool runtheGameMode2(void);
int main() {
	while (1)
	{
		int ex;
		system("CLS"); // clear screen
		cout<<"Plese enter a number\n";
		cout<<
			"  1. Run Game Mode 1  \n"
			"  2. Run Game Mode 2\n"
			"  3. How to play?\n"
			"  5. Exit\n";
		cout<<"Select: ";
		cin>>ex;
		switch (ex)
		{
		case 1:
			while (runtheGameMode1())
			{
			}
			runtheGameMode1();
			break;
		case 2:
			while (runtheGameMode2())
			{

			}
			break;
		case 3:
			cout <<
				"  MODE1: use SPACE or UP to control the character  \n"
				"  MODE2: use UP LEFT RIGHT to navigate\n"
				"  Try to avoid sick people\n"
				"  Stay Healthy,eat fruits !\n"
				"  Type any character and press ENTER to exit \n";
			cin >> ex;
			break;
		case 4:
			return 0;
		default:
			cout<<"please enter a valid number"<<endl;
			break;
		}
	}

	return 0;
}


bool runtheGameMode1(void)
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "The COVID Game");// create window
	window.setFramerateLimit(60);	//set limit frame rate

	uint8_t movingSpeed = 4;
	bool running = true;

	uint16_t score = 0;
	uint16_t tempScore = 0;
	Font arial;
	arial.loadFromFile("ArialUnicodeMS.ttf");

	ostringstream ssScore;
	ssScore << "Score: " << score;

	Text lblScore;
	lblScore.setCharacterSize(25);
	lblScore.setPosition({ 0, 0 });
	lblScore.setFont(arial);
	lblScore.setFillColor(sf::Color::Black);
	lblScore.setString(ssScore.str());
	//cout << ssScore.str() << endl;

	Text endGame;
	endGame.setCharacterSize(25);
	endGame.setPosition({ 170, 70 });
	endGame.setFont(arial);
	endGame.setFillColor(sf::Color::Black);
	endGame.setString("GAME OVER \nPress:\n\tSpace to retry\n\tESC to escape");

	Dude dude;
	Fruits fruits;
	Obsticle obs;
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed|| Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
				return 0;
			}
		}

		if (!running) {
			Sleep(500);
			while (1)
			{
				window.pollEvent(e);
				if (Keyboard::isKeyPressed(Keyboard::Escape) || e.type == Event::Closed)
				{
					window.close();
					return false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					window.close();
					return true;
				}
			}
		}
		//jump logic.
		dude.jumpHandling(Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Up));
		//Dude step.

		fruits.automove(movingSpeed);
		obs.automove(movingSpeed);

		eatingFruits(dude.getPointer(), &fruits, &score);
		if (falling(dude.getPointer(), &obs)) {
			running = false;
			dude.setEndGame();
		}

		if (score - tempScore >= 300) {
			tempScore = score;
			movingSpeed++;
		}

		//draw.
		window.clear(Color::White);
		dude.drawTo(window);
		fruits.drawWithCodition(window);

		ssScore.str("");
		ssScore << "Score " << score;
		lblScore.setString(ssScore.str());
		obs.drawTo(window);
		window.draw(lblScore);
		if (!running)
			window.draw(endGame);
		window.display();
		//Sleep(100);
	}
	return 1;
}


bool runtheGameMode2(void)
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "The COVID Game");// create window
	window.setFramerateLimit(60);	//set limit frame rate

	uint8_t movingSpeed = 4;
	uint8_t XmoveSpeed = 4;
	bool running = true;

	uint16_t score = 0;
	uint16_t tempScore = 0;
	Font arial;
	arial.loadFromFile("ArialUnicodeMS.ttf");

	ostringstream ssScore;
	ssScore << "Score: " << score;

	Text lblScore;
	lblScore.setCharacterSize(25);
	lblScore.setPosition({ 0, 0 });
	lblScore.setFont(arial);
	lblScore.setFillColor(sf::Color::Black);
	lblScore.setString(ssScore.str());
	//cout << ssScore.str() << endl;

	Text endGame;
	endGame.setCharacterSize(25);
	endGame.setPosition({ 170, 70 });
	endGame.setFont(arial);
	endGame.setFillColor(sf::Color::Black);
	endGame.setString("GAME OVER \nPress:\n\tSpace to retry\n\tESC to escape");

	Dude dude;
	Fruits fruits;
	Obsticle obs;
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed|| Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
				return 0;
			}
		}

		if (!running) {
			Sleep(500);
			while (1)
			{
				window.pollEvent(e);
				if (Keyboard::isKeyPressed(Keyboard::Escape) || e.type == Event::Closed)
				{
					window.close();
					return false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					window.close();
					return true;
				}
			}
		}
		//process keyboard input.
		uint16_t dudeX = dude.getX();
		dude.jumpHandling(Keyboard::isKeyPressed(Keyboard::Up));

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			dude.moveX(-XmoveSpeed);

		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (!dude.moveX(XmoveSpeed)) {
				fruits.automove(movingSpeed);
				obs.automove(movingSpeed);
			}

		}
		//Dude step.

		//fruits.automove(movingSpeed);
		//obs.automove(movingSpeed);

		eatingFruits(dude.getPointer(), &fruits, &score);
		if (falling(dude.getPointer(), &obs)) {
			running = false;
			dude.setEndGame();

		}

		if (score - tempScore >= 300) {
			tempScore = score;
			movingSpeed++;
		}

		//draw.
		window.clear(Color::White);
		dude.drawTo(window);
		fruits.drawWithCodition(window);

		ssScore.str("");
		ssScore << "Score " << score;
		lblScore.setString(ssScore.str());
		obs.drawTo(window);
		window.draw(lblScore);
		if (!running)
			window.draw(endGame);
		window.display();
		//Sleep(100);
	}
	return 1;
}
//void isCloseWindow()
//{
//	Event e;
//	while (window.pollEvent(e))
//	{
//		if (e.type == Event::Closed)
//		{
//			window.close();
//		}
//	}
//}
