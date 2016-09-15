#include <stdlib.h>
#include <iostream>
#include "algorithm.h"


/**
 *             | In-Place | Stable |  Worst  |  Average  |   Best   |
 * Selection        O         X       N^2 /2     N^2 /2      N^2 /2     
 * 
 * Insertion        O         O       N^2 /2     N^2 /4      N
 *  
 * Shell            O         X       N/A        N/A         N
 * 
 * Merge            X         O       NlogN      NlogN       NlogN
 * 
 * 3Way Merge       O         X       N^2 /2     2NlnN       N
 * 
 * Quick            O         X       N^2 /2     2NlnN       NlogN
 * 
 * Heap             O         X       2NlogN     2NlogN      NlogN
 * 
 * */
 
 
void initArray(int *, int);
void sortArray(int *, int, const char *, void (*)(int *, int));
void printArray(int *, int);

int main() {
    const int size = 101;
    int ar[size];
    
    sortArray(ar, size, "SelectionSort", Algorithm::SelectionSort);
    sortArray(ar, size, "InsertionSort", Algorithm::InsertionSort);
    sortArray(ar, size, "ShellSort", Algorithm::ShellSort);
    sortArray(ar, size, "MergeSort", Algorithm::MergeSort);
    sortArray(ar, size, "MergeSort_BottomUp", Algorithm::MergeSort_BottomUp);
    sortArray(ar, size, "QuickSort", Algorithm::QuickSort);

    return 0;
}

void initArray(int* ar, int size){
    for(int i = 0; i < size; ++i){
        ar[i] = i;
    }
    // Same Seed
    srand (0);
    // Shuffle Array
    for(int j = 0; j < size-2; ++j){
        std::swap(ar[j], ar[rand() % (size - j) + j]);
    }
}

void printArray(int* ar, int size){
    std::cout << "[" << ar[0];
    for(int i = 1; i < size; ++i){
        std::cout << "," << ar[i] ;
    }
    std::cout << "]" << std::endl;
}

void sortArray(int * ar, int size, const char * name, void (* sort)(int*, int)){
    std::cout << "===" << name << "===" << std::endl;
    initArray(ar, size);
    std::cout << name << ":: Original Array" << std::endl;
    printArray(ar, size);
    sort(ar, size);
    std::cout << name << ":: Sorted Array" << std::endl;
    printArray(ar, size);
}
