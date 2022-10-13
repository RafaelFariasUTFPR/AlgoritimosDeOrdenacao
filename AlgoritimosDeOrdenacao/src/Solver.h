#pragma once

#include <iostream>
#include <vector>

#include "AlgorithmMaster.h"
#include "RandomGenerator.h"

class Solver
{
public:
	Solver();

	void generateVector();

	int sps = 0; // Steps per second

	bool isVisual = true;
	int vectorSize = 1000;

private:
	std::vector<int> sortingVector;
};

