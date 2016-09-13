#ifndef UNION_FIND_V1_H
#define UNION_FIND_V1_H

class Union_Find_V1 {
    private:
        int * data;
        int length;
        
        // NO COPY ALLOWED
        Union_Find_V1(const Union_Find_V1&);
        Union_Find_V1& operator=(const Union_Find_V1&);

    public:
        Union_Find_V1(int);
        ~Union_Find_V1();
        bool isUnion(int, int);
        void Connect(int, int);
        int size();
};

#endif
