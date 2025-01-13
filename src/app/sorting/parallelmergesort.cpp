#include "parallelmergesort.hpp"
#include<iostream>
#include<thread>
#include<algorithm>
using namespace std;

parallelmergesort::parallelmergesort(vector<int>*nums)
{
    this->nums=nums;
}

parallelmergesort::~parallelmergesort(){}
//recursive approach will be same the thing is that when we are going to solve left and right then  that would be different
//in normal mergesort phle left hota then right call hota ok na
//pr parallel me ham ye paralley solve krna chah rhe hai left and right ko

void parallelmergesort::recursivesort(int left,int right)
{

    //agr ham ye use nhi kiye to 1000000 tak ka number na thread crash ho jiga
    //as cpu ke pas v limit hota hai ki kitna thread prallely genrate krke use kr ske
    //isliye hame threshold janna hga iska and iseme threshold put krna hga threa ka ki isse cross hua thread to normal recusrion hi chlana uske bad
    

    const int THRESHOLD=5000;
    if(right-left < THRESHOLD)  //it mean if no of element in array are less than threshold then that array sizing is so small then there multithreading will not make much sense
    //so wha pe aur jada thread spin nhi kr rha hunga
    //i will use the inbuilt sort fucntion to sort that part 

    {
        std::sort(nums->begin()+left,nums->begin()+right+1);
        return;


    }
    if(left>=right)
    {
        return;
    }
    int mid=left+ (right-left)/2;
    //when we are calling this recusrsive call then we have to call them in different thread

    thread thread_1([this,left,mid] {this->recursivesort(left,mid); });
    thread thread_2([this,mid,right] {this->recursivesort(mid+1,right); });
    //normal recursive
    // this->recursivesort(left,mid);
    // this->recursivesort(mid+1,right);

    //now we have to join this thread also as we want left and right part of the array to be run and get merge
    //this join will wait for both the thread to comp,ete the task left and right
    //and this is how parallely left and right recursive will happen parallely

    thread_1.join();
    thread_2.join();
     std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }

}

void parallelmergesort::sort(){
     if ((*nums).size() == 0) {
        exit(1);
    }

    std::thread thread_1([this] { this->recursivesort(0, (*nums).size() - 1); });
    thread_1.join();
//     for(int i=0;i<(*nums).size();i++)
// {
//   cout<<(*nums)[i]<<endl;
// }
}