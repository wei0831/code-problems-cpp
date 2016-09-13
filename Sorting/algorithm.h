#ifndef ALGORITHM_H
#define ALGORITHM_H

#define LESS(x, y) x < y

// Only Sort Integer
// No template
class Algorithm {
    private:
   
    public:
        static void Swap(int&, int&);
        static void SelectionSort(int *, int);
        static void InsertionSort(int *, int);
        static void ShellSort(int *, int);
};

#endif
