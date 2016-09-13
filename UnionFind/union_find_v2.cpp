#include "union_find_v2.h"

Union_Find_V2::Union_Find_V2(int size) 
    : data(new int [size]), length(size){
    for(int i = 0; i < size; ++i){
        data[i] = i;
    }
}

Union_Find_V2::~Union_Find_V2(){
    delete[] this->data;
}

int Union_Find_V2::size(){
    return length;
}

int Union_Find_V2::getParent(int index){
    while(data[index] != index){
        index = data[index];
    }
    return index;
}

bool Union_Find_V2::isUnion(int a, int b){
    return getParent(a) == getParent(b);
}

void Union_Find_V2::Connect(int a, int b){
    data[getParent(b)] = getParent(a);
}
