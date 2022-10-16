#pragma once

#include <vector>
#include <chrono>


#include "Global.h"

class AlgorithmMaster
{
public:
	AlgorithmMaster(std::vector<int>* _sortingVector);

	virtual void solve(){}
	virtual void solveTrhead(){}


	int* sps;

protected:
	void swap(unsigned int firstIndex, unsigned int secondIndex);
	void threadedSwap(unsigned int firstIndex, unsigned int secondIndex);

	void spsDelay();

	void startSort();
	void finishSort();

	std::vector<int>* sortingVector;
	bool firstIt = true;

	std::chrono::system_clock::time_point initialTime;
	std::chrono::system_clock::time_point endTime;


};

