// The .hpp file extension is typically used for C++ header files. It is an alternative to the more common .h extension for header files, used to differentiate between C and C++ code or simply as a matter of preference.


#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;


class MergeSort{
    private:
    vector<int>*nums;

    public:
        MergeSort(vector<int> *nums);//this is constructor
        ~MergeSort();//this is destructor
        void sort();//just declaring the functiom
        void recursivesort(int left,int right);
};

#endif
