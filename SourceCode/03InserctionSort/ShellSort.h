//
// Created by er on 2020/4/23.
//

#ifndef INSERCTIONSORT_SHELLSORT_H
#define INSERCTIONSORT_SHELLSORT_H

//重载了插入排序
template <typename T>
void InsertionSort_Advanced(T *arr,int grap,int n){
    for(int i = grap;i<n;i++){
        int e = arr[i];
        int j;
        for(j = i; j>=grap&&arr[j-grap]>e;j-=grap){ //注意 是j-grap>=0,因为最后一步是j=j-grap;所以j-grap 要保证大于0；
            arr[j] = arr[j-grap];
        }
        arr[j] = e; //此处一直有一个疑问，就是退出循环的条件是j-grap < 0 ;那在此处的j不会是负数吗，实验显示最小为0；还没想通为什么
    }
}
template <typename T>
void ShellSort(T arr,int n){
    for(int grap = n/3;grap>0;grap /=3){
        InsertionSort_Advanced(arr,grap,n);
    }
}

void TestShellSort(){
//    int n =10;
//    int *arr = SortTestHelper::generateArray(n,0,n);
//    SortTestHelper::PrintArray(arr,n);
//    ShellSort(arr,n);
//    SortTestHelper::PrintArray(arr,n);

    int n = 10000;
    int *arr = SortTestHelper::generateArray(n,0,n);
    int *arr2 = SortTestHelper::CopyIntArray(arr,n);
    int *arr3 = SortTestHelper::CopyIntArray(arr,n);
    int *arr4 = SortTestHelper::CopyIntArray(arr,n);

    SortTestHelper::ComputTime("InsertionSort_Advanced",InsertionSort_Advanced,arr,n);
    SortTestHelper::ComputTime("InsertionSort",InsertionSort,arr2,n);
    SortTestHelper::ComputTime("ShellSort",ShellSort,arr3,n);
    SortTestHelper::ComputTime("SelectionSort",SelectionSort,arr4,n);
    delete[]arr;
    delete[]arr2;
    delete[]arr3;
    delete[]arr4;
}
#endif //INSERCTIONSORT_SHELLSORT_H
