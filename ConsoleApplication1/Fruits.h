/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#pragma once
#include "common.h"
#include"myrandom.h"
uint16_t fruitSpace[] = { 30,70,100,150,300 };

class Fruits
{
private:
	Texture t4;
	Sprite fruits[4];
	Position_visiblity pos[4];
	uint8_t fruitsSpaceIndex[3];
	const uint16_t Y = HEIGHT - 200;
	int textureSizeX;
	//t4.loadFromFile("images/hansantinizer.png");
public:
	Fruits() {
		t4.loadFromFile("images/hansantinizer.png");
		for (int i = 0; i < 4;i++)
			fruits[i] = Sprite(t4);
		// t4.getSize().y;
		//pos[0].x = WIDTH -20;
		shufflePos();
		setFruitsPos(WIDTH);
		textureSizeX = (int)t4.getSize().x;
	}
	void shufflePos() {

		showAll();
		for (int i = 0;i < 3;i++) {
			fruitsSpaceIndex[i] = random(5);

		}
		setFruitsPos(pos[0].x);
	}
	void setFruitsPos(int16_t x/*, uint16_t y*/) {
		pos[0].x = x;
		fruits[0].setPosition(pos[0].x, Y);
		for (int i = 1;i < 4;i++) {
			pos[i].x = pos[i - 1].x + fruitSpace[fruitsSpaceIndex[i - 1]];
			//cout << pos[i].x << endl;
			fruits[i].setPosition(pos[i].x, Y);
		}

	}
	void drawTo(RenderWindow &window) {
		for (int i = 0;i < 4;i++)
			window.draw(fruits[i]);
	}
	void drawTo(RenderWindow &window, bool* arr) {
		for (int i = 0;i < 4;i++)
			if (arr[i])
				window.draw(fruits[i]);
	}

	void drawWithCodition(RenderWindow &window) {
		for (int i = 0;i < 4;i++)
			if (pos[i].visibility)
				window.draw(fruits[i]);
	}
	void automove(int16_t speed) {
		pos[0].x -= speed;
		setFruitsPos(pos[0].x);
		if (endofLine()) {
			pos[0].x = WIDTH;
			shufflePos();
		}
		//	cout << textureSizeX << endl;

	}
	bool endofLine() {
		if (pos[3].x <= -textureSizeX)

			return true;
		else
			return false;
	}
	Sprite *getPointer() {
		return fruits;
	}
	bool disapear(uint8_t index) {
		if (pos[index].visibility) {
			pos[index].visibility = false;
			return true;
		}
		else
			return false;
	}
	void showAll() {
		for (int i = 0;i < 4;i++)
			pos[i].visibility = true;
	}
};

