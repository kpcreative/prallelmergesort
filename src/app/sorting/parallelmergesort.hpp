// The .hpp file extension is typically used for C++ header files. It is an alternative to the more common .h extension for header files, used to differentiate between C and C++ code or simply as a matter of preference.


#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include<thread>
#include<mutex>
#include<iostream>
using namespace std;


class parallelmergesort{
    private:
    vector<int>*nums;

    public:
       parallelmergesort(vector<int> *nums);//this is constructor
        ~parallelmergesort();//this is destructor
        void sort();//just declaring the functiom
        void recursivesort(int left,int right);
};

#endif