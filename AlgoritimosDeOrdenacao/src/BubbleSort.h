#pragma once
#include "AlgorithmMaster.h"
#include <thread>

void threadedSort(std::vector<int>* sortingVector);

class BubbleSort :
    public AlgorithmMaster
{
public:
    BubbleSort();

    void solve(std::vector<int>* sortingVector) override;
    bool solveStep(std::vector<int>* sortingVector) override;
    bool solveStepa(std::vector<int>* sortingVector);

private:
    int i = 0;
    int j = 0;
    bool swapped = false;
};

