#pragma once

#include <iostream>
#include <vector>
#include <math.h>

#include "AlgorithmMaster.h"
#include "RandomGenerator.h"
#include "Global.h"

class Solver
{
public:
	Solver(Global &_global);

	void generateVector();

	void process();

	int sps; // Steps per second

	int targetSps = 30;

	bool isVisual = true;
	int vectorSize = 10000;

private:
	void step();

	std::vector<int> sortingVector;
	Global* global;
	sf::Clock deltaClock;

};

