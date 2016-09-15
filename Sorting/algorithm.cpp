#include "algorithm.h"

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
        
        std::swap(ar[i], ar[min]);
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
                std::swap(ar[j], ar[j-1]);
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
              std::swap(ar[j], ar[j-h]); 
           } 
        }
        h /= 3;
    }
}

/**
 *  [1, 5, 6, 8, 2, 3, 7, 9]
 *   |--------|  |--------|
 *       L           R
 *  
 *  Asuming L and R partial array are sortd
 *  
 *  We copy the whole array 
 *  Cut the array into half, 
 *  i as first part's starting 
 *  j as second part's starting
 * 
 *  Then we compare array[i] and array[j] one by one
 *  and update original array
 *  [1, 5, 6, 8, 2, 3, 7, 9]
 *   i        m  j
 *            i
 *            d
 *  Four things can happen starting from array[0] - array[end]
 *  
 *  i > mid : no more items left in L part, take from R part, ++j
 *  j > bound: no more items left in R part, take from L part, ++i
 *  array[i] > array [j]: we take array[j] item as the smaller one, ++j
 *  else : we take array[i] item as the smaller one, ++i
 * 
 *  After all done,
 *  Original Array become [1, 2, 3, 5, 6, 7, 8, 9]
 *  While Copy Array is still [1, 5, 6, 8, 2, 3, 7, 9]
 *   
 * */
void Algorithm::Merge(int * ar, int * aux, int low, int mid, int high){
    // Store in Temp Array
    for(int i = low; i <= high; ++i){
        aux[i] = ar[i];
    }
    
    // Sort
    int l = low;
    int r = mid+1;
    for(int i = low; i <= high; ++i){
        if (l > mid) ar[i] = aux[r++];
        else if(r > high) ar[i] = aux[l++];
        else if(LESS(aux[r], aux[l])) ar[i] = aux[r++];
        else ar[i] = aux[l++];
    }
}

/**
 * Divide and Conquer
 * 
 * Cut array into half, Sort both parts and Merge them.
 * Recursively doing so
 * 
 * */
void Algorithm::MergeSort_helper(int * ar, int * aux, int low, int high){
    if(high <= low) return;
    int mid = low + (high - low) / 2;
    MergeSort_helper(ar, aux, low, mid);
    MergeSort_helper(ar, aux, mid+1, high);
    Merge(ar, aux, low, mid, high);
}

void Algorithm::MergeSort(int * ar, int size){
    int * aux = new int[size];
    Algorithm::MergeSort_helper(ar, aux, 0, size-1);
    delete [] aux;
}

void Algorithm::MergeSort_BottomUp(int * ar, int size){
    int * aux = new int[size];
    
    for(int i = 1; i < size; i <<= 1){
        for(int j = 0; j < size - i; j += i << 1){
            // At the end, we might not have full right partial array
            // So MIN(j + i<<1 - 1, size -1)
            Algorithm::Merge(ar, aux, j, j+i-1, std::min(j+(i << 1)-1, size-1));
        }    
    }
    
    delete [] aux;
}

int Algorithm::Partition(int * ar, int low, int high){
    int i = low;
    int j = high+1;
    
    while(true){
        
        // LEFT PART
        while(LESS(ar[++i], ar[low])){
            if(i == high) break;
        }
        
        // RIGHT PART
        while(LESS(ar[low], ar[--j])){
            if(j == low) break;
        }
        
        // CROSS PTR
        if(i >= j) break;
        std::swap(ar[i], ar[j]);
    }
    
    std::swap(ar[low], ar[j]);
    return j;
}

void Algorithm::QuickSort_helper(int *ar, int low, int high){
    if(high <= low) return;
    int p = Algorithm::Partition(ar, low, high);
    Algorithm::QuickSort_helper(ar, low, p-1);
    Algorithm::QuickSort_helper(ar, p+1, high);
}

void Algorithm::QuickSort(int * ar, int size){
    // Shuffle Array
    for(int i = size-1; i > 0; --i){
        std::swap(ar[i], ar[rand() % (i + 1)]);
    }
    
    Algorithm::QuickSort_helper(ar, 0, size-1);
}
