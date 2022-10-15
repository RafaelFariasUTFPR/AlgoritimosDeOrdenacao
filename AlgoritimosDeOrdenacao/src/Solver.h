#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <thread>

#include "AlgorithmMaster.h"
#include "RandomGenerator.h"
#include "Global.h"
#include "BubbleSort.h"

void threadBubble(BubbleSort *bubbleSort, int* sps);

class Solver
{
public:
	Solver(Global &_global);

	void generateVector();

	void process();

	void solveBubbleSort();

	void showVector();


	unsigned int sps = 0; // Steps per second

	int targetSps = 200;

	bool isVisual = true;
	int vectorSize = 10000;


private:
	void step();

	
	void printVector();


	std::vector<int> sortingVector = { 1,2,3,4,5 };
	Global* global;
	sf::Clock deltaClock;

	BubbleSort bubbleSort;


	// 0 = None
	// 1 = Bubble Sort
	// 2 = Quick Sort
	// 3 = Radix Sort
	int stepAlgorithm = 0;

	unsigned int screenWidth = WINDOW_WIDTH - MENU_WIDTH;



	bool doOnce = true;
};

