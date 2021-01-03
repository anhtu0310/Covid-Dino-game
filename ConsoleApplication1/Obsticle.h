/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#pragma once
#include"common.h"
const uint16_t arr[] = { 50,300,500 };

class Obsticle {
private:
	Texture t3;
	Sprite obsticle[2];
	Position pos[2];
	uint8_t obtiscleSpaceIndex[NUMBER_OF_OBSTICLE - 1];
	uint16_t OBST_Y_BOTTOM;
	//	static const int TREE_Y_BOTTOM = HEIGHT - t3.getSize().y;

public:
	Obsticle() {
		t3.loadFromFile("images/N1.png");
		obsticle[0] = Sprite(t3);
		obsticle[1] = Sprite(t3);
		pos[0].x = WIDTH ;
		OBST_Y_BOTTOM = HEIGHT - t3.getSize().y;
		pos[0].y = OBST_Y_BOTTOM ;
		shufflePos();
		setObsticlesPos(pos[0].x);
	}
	void shufflePos() {
		for (int i = 0;i < NUMBER_OF_OBSTICLE - 1;i++) {
			obtiscleSpaceIndex[i] = random(3);
			cout << obtiscleSpaceIndex[i] << endl;;
		}
	}
	void setObsticlesPos(int16_t x/*, uint16_t y*/) {
		pos[0].x = x;
		obsticle[0].setPosition(pos[0].x, pos[0].y);
		for (int i = 1;i < NUMBER_OF_OBSTICLE;i++) {
		///	cout <<obtiscleSpaceIndex[i - 1] << endl;
			pos[i].x = pos[i - 1].x + arr[obtiscleSpaceIndex[i - 1]];
			obsticle[i].setPosition(pos[i].x, OBST_Y_BOTTOM);
		}
	}
	void drawTo(RenderWindow &window) {
		for (int i = 0;i < NUMBER_OF_OBSTICLE;i++)
			window.draw(obsticle[i]);
	}
	void automove(int16_t speed) {
		pos[0].x -= speed;
		setObsticlesPos(pos[0].x);
		if (endofLine()) {
			pos[0].x = WIDTH;
			shufflePos();
		}

	}
	bool endofLine() {
		for (int i = 0;i < NUMBER_OF_OBSTICLE;i++)
			if (pos[NUMBER_OF_OBSTICLE - 1].x <= -50)
				return true;
			else
				return false;
	}
	Sprite *getPointer() {
		return obsticle;
	}
};
