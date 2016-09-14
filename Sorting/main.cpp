#include <stdlib.h>
#include <iostream>
#include "algorithm.h"

void initArray(int *, int);
void printArray(int *, int);

int main() {
    const int size = 101;
    int ar[size];
    
    std::cout << "===SelectionSort===" << std::endl;
    initArray(ar, size);
    std::cout << "SelectionSort:: Original Array" << std::endl;
    printArray(ar, size);
    Algorithm::SelectionSort(ar, size);
    std::cout << "SelectionSort:: Sorted Array" << std::endl;
    printArray(ar, size);
    
    std::cout << "===InsertionSort===" << std::endl;
    initArray(ar, size);
    std::cout << "InsertionSort:: Original Array" << std::endl;
    printArray(ar, size);
    Algorithm::InsertionSort(ar, size);
    std::cout << "InsertionSort:: Sorted Array" << std::endl;
    printArray(ar, size);
    
    
    std::cout << "===ShellSort===" << std::endl;
    initArray(ar, size);
    std::cout << "ShellSort:: Original Array" << std::endl;
    printArray(ar, size);
    Algorithm::ShellSort(ar, size);
    std::cout << "ShellSort:: Sorted Array" << std::endl;
    printArray(ar, size);
    
    std::cout << "===MergeSort===" << std::endl;
    initArray(ar, size);
    std::cout << "MergeSort:: Original Array" << std::endl;
    printArray(ar, size);
    Algorithm::MergeSort(ar, size);
    std::cout << "MergeSort:: Sorted Array" << std::endl;
    printArray(ar, size);
    
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
        Algorithm::Swap(ar[j], ar[rand() % (size - j) + j]);
    }
}

void printArray(int* ar, int size){
    std::cout << "[" << ar[0];
    for(int i = 1; i < size; ++i){
        std::cout << "," << ar[i] ;
    }
    std::cout << "]" << std::endl;
}
