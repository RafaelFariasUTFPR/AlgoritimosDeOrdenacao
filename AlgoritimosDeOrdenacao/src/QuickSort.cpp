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
    lastNumberOfSteps++;
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
    lastNumberOfSteps++;
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(low, high);

        // recursive call on the left of pivot
        recursiveQuickSortThread(low, pi - 1);

        // recursive call on the right of pivot
        recursiveQuickSortThread(pi + 1, high);
    }
}

int QuickSort::partition(int low, int high)
{
    // select the rightmost element as pivot
    int pivot = sortingVector->at(high);

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        spsDelay();

        if (sortingVector->at(j) <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(i, j);
        }
    }

    // swap pivot with the greater element at i
    swap(i + 1, high);

    // return the partition point
    return (i + 1);
}