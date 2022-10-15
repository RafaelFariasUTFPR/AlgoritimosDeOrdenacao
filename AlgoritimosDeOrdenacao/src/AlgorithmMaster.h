#pragma once

#include <vector>
#include <chrono>

#include "Global.h"

class AlgorithmMaster
{
public:
	AlgorithmMaster(std::vector<int>* _sortingVector);

	virtual void solve(){}
	virtual void solveTrhead(int *sps){}


	unsigned long int numberOfSteps = 0;


protected:
	void swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex);
	void spsDelay(int* sps);

	void startSort();
	void finishSort();

	std::vector<int>* sortingVector;
	bool firstIt = true;

	std::chrono::system_clock::time_point initialTime;
	std::chrono::system_clock::time_point endTime;


};

