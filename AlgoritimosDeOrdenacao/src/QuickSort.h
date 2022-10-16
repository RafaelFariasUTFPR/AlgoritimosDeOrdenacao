#pragma once
#include "AlgorithmMaster.h"
class QuickSort :
    public AlgorithmMaster
{
public:
    QuickSort(std::vector<int>* _sortingVector);

    void solve() override;
    void solveTrhead() override;

private:
    void recursiveQuickSort(int low, int high);
    void recursiveQuickSortThread(int low, int high);

    int partition(int low, int high);


};

