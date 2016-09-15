#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdlib.h> /* rand */
#include <algorithm> /* min, swap */
#define LESS(x, y) x < y

// Only Sort Integer
// No template
class Algorithm {
    private:
        // Merge Sort
        static void Merge(int *, int *, int, int, int);
        static void MergeSort_helper(int *, int *, int, int);
        // Quick Sort
        static int Partition(int*, int, int);
        static void QuickSort_helper(int *, int, int);
        
    public:
        static void SelectionSort(int *, int);
        static void InsertionSort(int *, int);
        static void ShellSort(int *, int);
        static void MergeSort(int *, int);
        static void MergeSort_BottomUp(int *, int);
        static void QuickSort(int *, int);
};

#endif
