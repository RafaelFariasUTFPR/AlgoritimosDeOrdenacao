#pragma once
#include "AlgorithmMaster.h"


class BubbleSort :
    public AlgorithmMaster
{
public:
    BubbleSort(std::vector<int>* _sortingVector);

    void solve() override;
    void solveTrhead() override;
    
private:
    bool swapped = false;
};

