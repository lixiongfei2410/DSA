//
// Created by er on 2020/4/21.
//

#include <iostream>
#include <algorithm>
#include "student.h"

using namespace std;

//选择排序
template <typename  T>
void SelectiongSort(T *ele,int n){
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
    for(int i = 0;i < n; i++){
        cout << ele[i] << endl;
    }

}

int main(){
    int elem[9] = {2,1,3,4,5,7,6,8,9};
    SelectiongSort<int>(elem,9);

    float elem_float[5] = {1.1, 2.2, 3.3, 5.5, 4.4};
    SelectiongSort(elem_float,5);

    student stu[3] = {{"aa",90 },{"bb",85},{"cc",95}};
    SelectiongSort(stu,3);
    cout << "Hello SelectionSort!" << endl;
    return 0;
}