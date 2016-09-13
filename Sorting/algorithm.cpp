#include "algorithm.h"

void Algorithm::Swap(int& a, int& b){
    int s = a;
    a = b;
    b = s;
}

/**
 *  Pick 0 - n
 *  Each time find min item in current till the last item
 *  Swap the min with current
 *  
 *  WorstCase: O(n^2)
 *  Memory: O(1)
 * */
void Algorithm::SelectionSort(int * ar, int n){
    for(int i = 0; i < n; ++i){
        int min = i;
        
        for(int j = i+1; j < n; ++j){
            if(LESS(ar[j], ar[min])){
                min = j;
            }
        }
        
        Algorithm::Swap(ar[i], ar[min]);
    }
}

/**
 *  Pick 0 - n
 *  Each time compare current item with previous items
 *  Keep swapping till reach the correct position
 * 
 *  WorstCase: O(n^2)
 *  Memory: O(1)
 *  Note:
 *    Slightly better than selection if the input array is partial sorted.
 *    O(n) complexity for sorted array (Best Case)
 * */
void Algorithm::InsertionSort(int * ar, int n){
    for(int i = 0; i < n; ++i){
        for(int j = i; j > 0; --j){
            if(LESS(ar[j], ar[j-1]))
                Algorithm::Swap(ar[j], ar[j-1]);
            else
                break;
        }
    }
}

/**
 *  Start from h = Largest (3x + 1) < size/3
 *  Insertion Sort from * to -
 *  Decreament h by 2/3
 * 
 *  h = 4
 *  0 1 2 3 4 5 6
 *  -       *
 *    -       *
 *      -       *
 * 
 *  h = 1
 *  0 1 2 3 4 5 6
 *  *       
 *  - *       
 *  - - *       
 *  - - - * 
 *  - - - - *
 *  - - - - - *
 *  - - - - - - -*
 *  
 *  WorstCase: O(n^(3/2))
 *  Memory: O(1)
 * 
 * */
void Algorithm::ShellSort(int * ar, int n){
    int h = 1;
    int onethird = n / 3;
    
    // Sequence
    // 1, 4, 13, 40 ...
    while(h < onethird){
        h = 3 * h + 1;
    }
    while(h >= 1){
        for(int i = h; i < n; ++i){
           for(int j = i; j >= h && LESS(ar[j], ar[j-h]); j -= h){
              Algorithm::Swap(ar[j], ar[j-h]); 
           } 
        }
        h /= 3;
    }
}
