#pragma once
#include "AlgorithmMaster.h"


class BubbleSort :
    public AlgorithmMaster
{
public:
    BubbleSort(std::vector<int>* _sortingVector);

    void solve() override;
    void solveTrhead(int* sps) override;
    
private:
    int i = 0;
    int j = 0;
    bool swapped = false;
};

