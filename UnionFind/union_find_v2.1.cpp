#include "union_find_v2.1.h"

Union_Find_V2_1::Union_Find_V2_1(int size) 
    : data(new int [size]), chainsize(new int [size]), length(size){
    for(int i = 0; i < size; ++i){
        data[i] = i;
    }
    for(int i = 0; i < size; ++i){
        chainsize[i] = 1;
    }
}

Union_Find_V2_1::~Union_Find_V2_1(){
    delete[] this->data;
    delete[] this->chainsize;
}

int Union_Find_V2_1::size(){
    return length;
}

int Union_Find_V2_1::getParent(int index){
    while(data[index] != index){
        // Improvement: Flatten 
        data[index] = data[data[index]];
        index = data[index];
    }
    return index;
}

bool Union_Find_V2_1::isUnion(int a, int b){
    return getParent(a) == getParent(b);
}

void Union_Find_V2_1::Connect(int a, int b){
    int i = getParent(a);
    int j = getParent(b);
    
    // Improvement: Weighted Connect
    if(i == j) return;
    if(chainsize[i] < chainsize[j]){
        data[i] = j;
        chainsize[j] += chainsize[i];
    }
    else{
        data[j] = i;
        chainsize[i] += chainsize[j];  
    }
}
