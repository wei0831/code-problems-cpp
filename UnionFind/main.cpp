#include <stdlib.h>
#include <cstdio>
#include "union_find_v1.h"
#include "union_find_v2.h"

int main() {
    /**
     *  0   3 - 4 
     *  |   |
     *  1 - 2   5
     * 
     * 
     * */

    // Version 1
    // Union O(1); Connect O(N)
    Union_Find_V1 test_v1(6);
    printf("V1 Size: %i\n", test_v1.size());
    printf("Connect: (1, 2)\n");
    test_v1.Connect(1,2);
    printf("(1,2) Connected ? %s\n", test_v1.isUnion(1,2)?"True":"False");
    printf("(1,4) Connected ? %s\n", test_v1.isUnion(1,4)?"True":"False");
    printf("Connect: (1, 0)\n");
    test_v1.Connect(1,0);
    printf("Connect: (3, 2)\n");
    test_v1.Connect(3,2);
    printf("Connect: (4, 3)\n");
    test_v1.Connect(4,3);
    printf("(1,4) Connected ? %s\n", test_v1.isUnion(1,4)?"True":"False");
    
    // Version 2
    // Union O(N); Connect O(N)
    Union_Find_V2 test_v2(6);
    printf("V2 Size: %i\n", test_v2.size());
    printf("Connect: (1, 2)\n");
    test_v2.Connect(1,2);
    printf("(1,2) Connected ? %s\n", test_v2.isUnion(1,2)?"True":"False");
    printf("(1,4) Connected ? %s\n", test_v2.isUnion(1,4)?"True":"False");
    printf("Connect: (1, 0)\n");
    test_v2.Connect(1,0);
    printf("Connect: (3, 2)\n");
    test_v2.Connect(3,2);
    printf("Connect: (4, 3)\n");
    test_v2.Connect(4,3);
    printf("(1,4) Connected ? %s\n", test_v2.isUnion(1,4)?"True":"False");
    
    
    return 0;
}
