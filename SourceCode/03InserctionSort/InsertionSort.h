//
// Created by er on 2020/4/21.
//

#ifndef INSERCTIONSORT_INSERTIONSORT_H
#define INSERCTIONSORT_INSERTIONSORT_H

#include <iostream>
#include <algorithm>
#include "TestHelper.h"
#include "SelectionSort.h"

using namespace std;

// 插入排序
/*注意点：
 * @i  i从1开始，首个元素不用动
 * @j  j>0  因为是 和 j-1 相比，所以不是从0开始
 * */

/*
 * 插入排序可以提前结束内循环，理论上比选择排序要快，但是当前版本由于交换过程，使得过程比选择排序慢很多
 * 后面有优化的版本
 * 循环部分可以写成
 * for(int j = i;j > 0&&arr[j]<arr[j-1]; j--) {
 *     swap(arr[j],arr[j-1]);
 * }
 * */
template <typename T>
void InsertionSort(T *arr,int n){
    for(int i = 1; i < n; i++){
        for(int j = i;j > 0; j--){  // j从i的位置开始向前扫描比较，依次前移
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            } else
                break;
        }
    }
}

void TestInsertionSort()
{
    int n = 10000;
    int *arr = SortTestHelper::generateArray(n,0,n);
    int *arr2 = SortTestHelper::CopyIntArray(arr,n);
    SortTestHelper::ComputTime("InsertionSort",InsertionSort,arr,n);
    SortTestHelper::ComputTime("SelectionSort",SelectionSort,arr2,n);
    //InsertionSort(arr,n);
    // SortTestHelper::PrintArray(arr,n);
    delete []arr;
    delete []arr2;
}

#endif //INSERCTIONSORT_INSERTIONSORT_H
