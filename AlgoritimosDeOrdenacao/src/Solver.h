#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <thread>

#include "AlgorithmMaster.h"
#include "RandomGenerator.h"
#include "Global.h"

#include "BubbleSort.h"
#include "QuickSort.h"
#include "CountingSort.h"

void threadSolve(AlgorithmMaster* algorithm);
void threadGenerate(std::vector<int>* sortingVector, Global* global, int vectorSize);

class Solver
{
public:
	Solver(Global &_global);

	void generateVector();

	void process();

	void solveBubbleSort();
	void solveQuickSort();
	void solveCountingSort();

	void showVector();


	unsigned int sps = 0; // Steps per second

	int targetSps = 4000;

	bool isVisual = true;
	int vectorSize = 1000;


private:
	void step();

	
	void printVector();


	std::vector<int> sortingVector = { 1,2,3,4,5 };
	Global* global;
	sf::Clock deltaClock;

	BubbleSort bubbleSort;
	QuickSort quickSort;
	CountingSort countingSort;


	// 0 = None
	// 1 = Bubble Sort
	// 2 = Quick Sort
	// 3 = Radix Sort
	int stepAlgorithm = 0;

	unsigned int screenWidth = WINDOW_WIDTH - MENU_WIDTH;



	bool doOnce = true;
};

