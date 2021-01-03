/*
 * CPP Project  due date :03/01/2021
 * Course: C\C++ Programing language
 * Author: Dang Anh Tu 20182938
 * Class: ET-E4
 * Visual Studio 15.9 (2017)
 */
#pragma once

#include <iostream>
#include <random>
using namespace std;
uint8_t random(uint8_t randlimit) {
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0, randlimit);
	return dist(mt);

}