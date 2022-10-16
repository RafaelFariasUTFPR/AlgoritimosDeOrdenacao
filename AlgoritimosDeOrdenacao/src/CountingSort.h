#pragma once
#include "AlgorithmMaster.h"
class CountingSort :
    public AlgorithmMaster
{
public:
    CountingSort(std::vector<int>* _sortingVector);

    void solve() override;
    void solveTrhead() override;

private:


};

