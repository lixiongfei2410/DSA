//
// Created by er on 2020/4/21.
//

#ifndef SELECITONSORT_TESTHELPER_H
#define SELECITONSORT_TESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;
namespace SortTestHelper{

    //产生n个元素的随机数组，范围为 [RangL,RangR]
   int *  generateArray(int n ,int RangL,int RangR){
       assert(RangL <= RangR);//断言
       int *arr = new int[n]; //开辟内存
       srand(time(NULL)); //产生随机种子
       for(int i = 0;i < n; i++){
           arr[i] = rand() % (RangR - RangL + 1) + RangL; //注意要 +1
       }
       return arr;
     }

     // 打印函数
     void PrintArray(const int *arr,int n){
       for(int i = 0; i < n; i++){
           cout << arr[i] << " ";
       }
       cout << endl;
   }
   template <typename T>
    bool IsSorted(const T *array,int n ){
       for(int i = 0; i < n -1; i++){
           if(array[i] > array[i+1])
               return false;
       }
       return true;
   }
    //计算时间
    template <typename T>
    void ComputTime(const string &SortName, void(*sort)(T *,int ),T *array,int n){
       time_t start_time = clock();
       sort(array,n);
       time_t end_time = clock();
       assert(IsSorted(array,n));//判断排序是否正确
       cout << SortName << "use time : "<< double(end_time - start_time)/CLOCKS_PER_SEC  << "s" << endl;
   }

};

#endif //SELECITONSORT_TESTHELPER_H
