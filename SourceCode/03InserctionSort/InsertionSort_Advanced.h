//
// Created by er on 2020/4/21.
//

#ifndef INSERCTIONSORT_INSERTIONSORT_ADVANCED_H
#define INSERCTIONSORT_INSERTIONSORT_ADVANCED_H

#include <iostream>
#include <algorithm>
#include "student.h"
#include "TestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
/*插入排序改进版
 * 说明：
 * 之前版本是每次都交换，而现在是依次后移，找到很合适的位置插入
 * 依次比较当前元素和之前元素的大小，比当前元素arr[i]大的话依次后移，arr[i]继续和前一个比较的比较
 * */
template <typename T>
void InsertionSort_Advanced(T *arr, int n){
    for(int i =1; i< n; i++){
        int j=0;
        T e = arr[i];
        for(j=i;j>0;j--){
            if(arr[j-1]>e) { // 注意是j-1
                arr[j] = arr[j - 1];
            } else
        break;
        }
        arr[j] = e;
    }

}

void TestInsertionSort_Advanced(){
    int n = 10000;
    int *arr = SortTestHelper::generateArray(n,0,n);
    int *arr2 = SortTestHelper::CopyIntArray(arr,n);
    int *arr3 = SortTestHelper::CopyIntArray(arr,n);
    SortTestHelper::ComputTime("InsertionSort_Advanced",InsertionSort_Advanced,arr,n);
    SortTestHelper::ComputTime("InsertionSort",InsertionSort,arr2,n);
    SortTestHelper::ComputTime("SelectionSort",SelectionSort,arr3,n);
    delete[]arr;
    delete[]arr2;
    delete[]arr3;
    //SortTestHelper::PrintArray(arr,n);
    // InsertionSort_Advanced<int>(arr,n);
//   SortTestHelper::PrintArray(arr,n);
//   cout << "Hello Sort!" << endl;

}
#endif //INSERCTIONSORT_INSERTIONSORT_ADVANCED_H
