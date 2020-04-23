//
// Created by er on 2020/4/21.
//

#include <iostream>
#include <algorithm>
#include "student.h"
#include "TestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "InsertionSort_Advanced.h"
#include "ShellSort.h"

using namespace std;

//冒泡排序
template <typename T>
void BubbleSort(T *arr,int n ){
    for(int i =0;i<n-1;i++)
        for(int j=0;j < n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
}
void TestBubbleSort(){
//    int n =10;
//    int *arr = SortTestHelper::generateArray(n,0,n);
//    SortTestHelper::PrintArray(arr,n);
//    BubbleSort(arr,n);
//    SortTestHelper::PrintArray(arr,n);

    int n = 10000;
    int *arr = SortTestHelper::generateArray(n,0,n);
    int *arr2 = SortTestHelper::CopyIntArray(arr,n);
    int *arr3 = SortTestHelper::CopyIntArray(arr,n);
    int *arr4 = SortTestHelper::CopyIntArray(arr,n);
    int *arr5 = SortTestHelper::CopyIntArray(arr,n);
    SortTestHelper::ComputTime("InsertionSort_Advanced",InsertionSort_Advanced,arr,n);
    SortTestHelper::ComputTime("InsertionSort",InsertionSort,arr2,n);
    SortTestHelper::ComputTime("ShellSort",ShellSort,arr3,n);
    SortTestHelper::ComputTime("SelectionSort",SelectionSort,arr4,n);
    SortTestHelper::ComputTime("BubbleSort",BubbleSort,arr5,n);
    delete[]arr;
    delete[]arr2;
    delete[]arr3;
    delete[]arr4;
    delete[](arr5);
}
int main(){
   // TestSelectionSort();
   //TestInsertionSort();
   //TestInsertionSort_Advanced();
   //TestShellSort();
    TestBubbleSort();
    return 0;
}