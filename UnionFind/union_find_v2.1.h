#ifndef UNION_FIND_V2_1_H
#define UNION_FIND_V2_1_H

class Union_Find_V2_1 {
    private:
        int * data;
        int * chainsize;
        int length;
        
        /* NO COPY ALLOWED */
        Union_Find_V2_1(const Union_Find_V2_1&);
        Union_Find_V2_1& operator=(const Union_Find_V2_1&);
        
        int getParent(int);
        
    public:
        Union_Find_V2_1(int);
        ~Union_Find_V2_1();
        bool isUnion(int, int);
        void Connect(int, int);
        int size();
};

#endif
