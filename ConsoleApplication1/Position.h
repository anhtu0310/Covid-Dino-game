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

class Position
{

public:
	int x;
	int y;

};

class Position_visiblity :public Position
{
public:
	bool visibility = true;
};
// TODO: an inheritace class
