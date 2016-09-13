#include "union_find_v1.h"

Union_Find_V1::Union_Find_V1(int size) 
    : data(new int [size]), length(size){
    for(int i = 0; i < size; ++i){
        data[i] = i;
    }
}

Union_Find_V1::~Union_Find_V1(){
    delete[] this->data;
}

int Union_Find_V1::size(){
    return length;
}

bool Union_Find_V1::isUnion(int a, int b){
    return data[a] == data[b];
}

/**
 * INDEX 0 1 2 3 4 5
 *       0 1 2 3 4 5  // Connected to which index
 * 
 * After some connection
 * 
 * INDEX 0 1 2 3 4 5
 *       2 4 2 3 4 5 
 * 
 *     -------
 *     |     |
 *   0 1 2 3 4 5
 *   |   |
 *   -----  
 **/
void Union_Find_V1::Connect(int a, int b){
    int idx = data[b];
    for(int i = 0; i < length; ++i){
        if(data[i] == idx) data[i] = a;
    }
}
