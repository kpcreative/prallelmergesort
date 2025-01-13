//this cocnept will tell you how the bog doffrence in time it is when we sort 10^7 ELEMENT USING MERGE SORT AND PARALLEL MERGE SORT USING THREAD







#include<iostream>
#include "sorting/mergesort.hpp"
#include "sorting/parallelmergesort.hpp"
using namespace std;
#include <chrono>
int main()
{
    const int SIZE=10000000;
    vector<int>nums(SIZE);
      vector<int>nums1(SIZE);
    for(int i=0;i<SIZE;i++)
    {
        nums[i]=rand()%100000000;
         nums1[i]=rand()%10000000;

    }
    MergeSort* mergesort=new MergeSort(&nums);//it will return the pointer to the mergesort instance ka memoery
   auto start=chrono::high_resolution_clock::now();//time taken by this mergesort algo
   mergesort->sort();
   auto end=std::chrono::high_resolution_clock::now();
  chrono::duration<double> mergesorttimetaken=end-start;
   cout<<"Merge sort algo takes time:"<<mergesorttimetaken.count()<<" seconds"<<endl;
   delete mergesort;//at last by destructor delete it jo vmemory is pointed jo memory is allocated at this instance


       parallelmergesort* parallelmergesort1=new parallelmergesort(&nums1);//it will return the pointer to the mergesort instance ka memoery
    start=chrono::high_resolution_clock::now();//time taken by this mergesort algo
   parallelmergesort1->sort();
    end=std::chrono::high_resolution_clock::now();
  mergesorttimetaken=end-start;   //upr me define hai isliye phir se nhi likhe 
   cout<<"Parallel Merge sort algo takes time:"<<mergesorttimetaken.count()<<" seconds"<<endl;
   delete parallelmergesort1;//at last by destructor delete it jo vmemory is pointed jo memory is allocated at this instance
}
