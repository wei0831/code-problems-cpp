#ifndef UNION_FIND_V2_H
#define UNION_FIND_V2_H

class Union_Find_V2 {
    private:
        int * data;
        int length;
        
        /* NO COPY ALLOWED */
        Union_Find_V2(const Union_Find_V2&);
        Union_Find_V2& operator=(const Union_Find_V2&);
        
        int getParent(int);
        
    public:
        Union_Find_V2(int);
        ~Union_Find_V2();
        bool isUnion(int, int);
        void Connect(int, int);
        int size();
};

#endif
