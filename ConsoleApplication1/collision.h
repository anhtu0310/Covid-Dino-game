/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#pragma once
#include"common.h"
#include"Fruits.h"
#include"Obsticle.h"
#include"mainChar.h"

//void falling(Sprite* mainchar, Obsticle *obj, uint16_t* score);
//void eatingFruits(Sprite* mainchar, Fruits *obj, uint16_t* score);
//bool collisionDetect(Sprite* obj1, Sprite* obj2);

bool collisionDetect(Sprite* obj1, Sprite* obj2) {
	return obj1->getGlobalBounds().intersects(obj2->getGlobalBounds());
}

void eatingFruits(Sprite* mainchar, Fruits *obj, uint16_t* score) {
	Sprite *temp = obj->getPointer();
	for (int i = 0;i < 4;i++) {
		if (collisionDetect(mainchar, temp)) {
			if (obj->disapear(i)) {// THIS IS A VERY BAD WAY TO IMPLEMENT THIS FUCTION BUT FORGIVE ME I'M IN A HURRY
				*score += 50;
				/*	ssScore.str("");
					ssScore << "Score " << score;
					lblScore.setString(ssScore.str())*/;
			}
		}
		temp++;
	}
}

bool falling(Sprite* mainchar, Obsticle *obj) {
	Sprite *temp = obj->getPointer();
	for (int i = 0;i < NUMBER_OF_OBSTICLE;i++) {
		if (collisionDetect(mainchar, temp)) {
			return true;
		}
		temp++;
	}
	return false;
}
