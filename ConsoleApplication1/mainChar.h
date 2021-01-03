/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Position.h"
using namespace sf;
using namespace std;

class Dude {
private:
	uint8_t gravity = 7;
	Position pos;
	Texture t1, t2, t3;
	Sprite dude;
	bool state;
	bool isJumping = false;
	bool isBottom = true;
	uint16_t Dude_Y_BOTTOM;//t1.getSize().y;	
	//const int DUDE_Y_BOTTOM;
	float frame = 0.f;
	float frameSpeed = 0.4f;
	const int changeCount = 5;

public:
	Dude(void) {
		t1.loadFromFile("images/dino7.png");
		t2.loadFromFile("images/dino8.png");
		t3.loadFromFile("images/dino_end2.png");
		Dude_Y_BOTTOM = HEIGHT - t2.getSize().y;
		dude = Sprite(t1);
		state = 1;
		pos.x = 50;
		pos.y = Dude_Y_BOTTOM;
		setPos(pos.x, pos.y);

	}
	void change_state() {
		if (state)
		{
			dude = Sprite(t2);
			state = 0;
		}
		else
		{
			dude = Sprite(t1);
			state = 1;
		}
	}
	uint16_t getX()
	{
		return dude.getPosition().x;
	}
	uint16_t getY()
	{
		return dude.getPosition().y;
	}
	void setPos(int x, int y)
	{
		dude.setPosition(x, y);
	}
	void updatePos() {
		setPos(pos.x, pos.y);
	}
	Sprite *getPointer()
	{
		return &dude;
	}
	void drawTo(RenderWindow &window)
	{
		window.draw(dude);
	}
	//loose end need to fix later !
	uint16_t getSizeX() {
		return t1.getSize().x;
	}
	uint16_t getSizeY() {
		return t1.getSize().y;
	}
	bool moveX(int16_t move) {
		pos.x += move;
		if (pos.x > 0 && pos.x <= 200)
		{
			updatePos();
			return true;
		}
		else
		{
			pos.x -= move;
			return false;
		}
	}
	void jumpHandling(bool key) {
		//Dude jump.
		if (key)
		{
			if (isBottom && !isJumping)
			{
				//make jumping stage;
				isJumping = true;
				isBottom = false;
			}
		}

		//Dude jump(up and down)
		if (isJumping)
		{
			pos.y -= gravity;
		}
		else
		{
			pos.y += gravity;
		}

		//Dude jump limit, Dude bottom limit.
		if (pos.y >= Dude_Y_BOTTOM)
		{
			pos.y = Dude_Y_BOTTOM;
			isBottom = true;
		}
		if (pos.y <= Dude_Y_BOTTOM - 220)
		{
			isJumping = false;
		}
		stepping();
		updatePos();
	}
	void setEndGame() {
		dude = Sprite(t3);
		updatePos();

	}
	void stepping() {
		//TODO REWRITES ASAP
		frame += frameSpeed;
		if (frame > changeCount)
		{
			frame -= changeCount;
			change_state();
		}
	}
};
