//
// Created by er on 2020/4/21.
//
#include <iostream>
#include <string>
#ifndef SORT_STUDENT_H
#define SORT_STUDENT_H
using namespace std;
struct student{
    string name;
    int score;//成绩

    bool operator<(const student &OtherStudent){
        return score < OtherStudent.score;
    }

    friend ostream& operator<<(ostream &os,const student &stu){
        os << stu.name << " "<<stu.score ;
        return os;
    }
};

#endif //SORT_STUDENT_H
