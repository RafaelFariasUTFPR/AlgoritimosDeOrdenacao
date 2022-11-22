#include "QuickSort.h"


QuickSort::QuickSort(std::vector<int>* _sortingVector) : AlgorithmMaster(_sortingVector)
{

}

void QuickSort::solve()
{
    startSort();
    recursiveQuickSort(0, sortingVector->size()-1);
    finishSort();
}

void QuickSort::solveTrhead()
{
    startSort();
    recursiveQuickSortThread(0, sortingVector->size() - 1);
    finishSort();
}

void QuickSort::recursiveQuickSort(int low, int high)
{
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(low, high);

        // recursive call on the left of pivot
        recursiveQuickSort(low, pi - 1);

        // recursive call on the right of pivot
        recursiveQuickSort(pi + 1, high);
    }
}
void QuickSort::recursiveQuickSortThread(int low, int high)
{
    if (low < high) {
        int pi = partition(low, high);

        recursiveQuickSortThread(low, pi - 1);

        recursiveQuickSortThread(pi + 1, high);
    }
}

int QuickSort::partition(int low, int high)
{
    int pivot = sortingVector->at(high);

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        spsDelay();

        if (sortingVector->at(j) <= pivot) {

            i++;
            lastNumberOfSteps++;
            swap(i, j);
        }
    }

    swap(i + 1, high);

    return (i + 1);
}