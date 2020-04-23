//
// Created by er on 2020/4/21.
//

#include <iostream>
#include <algorithm>
#include "student.h"
#include "TestHelper.h"

using namespace std;

//选择排序
template <typename  T>
void SelectionSort(T *ele,int n){
    for(int i = 0; i < n; i++)
    {
        int   eleIndex = i;
        // 寻找最小值的索引
        for(int j = i+1; j < n ; j++)
        {
            if(ele[j] < ele[eleIndex] ) {
                eleIndex = j;
            }
        }
        //将最小值移动到未排序的最前面
        swap(ele[i],ele[eleIndex]);
    }
    //添加打印函数
//    for(int i = 0;i < n; i++){
//        cout << ele[i] << endl;
//    }

}

int main(){
    int elem[9] = {2,1,3,4,5,7,6,8,9};
    SelectionSort<int>(elem,9);

    float elem_float[5] = {1.1, 2.2, 3.3, 5.5, 4.4};
    SelectionSort(elem_float,5);

    student stu[3] = {{"aa",90 },{"bb",85},{"cc",95}};
    SelectionSort(stu,3);

    int n = 10000;
    int *array = SortTestHelper::generateArray(n,0,n);//产生随机数组
  //  SortTestHelper::PrintArray(array,n);
    SortTestHelper::ComputTime("SelectionSort",SelectionSort,array,n);
  //  SortTestHelper::PrintArray(array,n);
    delete[]array;//释放
    cout << "Hello SelectionSort_Advanced!" << endl;
    return 0;
}