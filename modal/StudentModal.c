//
// Created by firework on 2021/5/19.
//


#include "StudentModal.h"
#include <string.h>
#include <stdio.h>

int studentCount_ = 0;
Student *students_[studentLen];

Students *initStudent() {
    for (int i = 0; i < studentLen; i ++)
        students_[i] = newStudent();
    return students_;
};

//  暂时不考虑学生数量过多的情况，仅在一个 studentLen 大小的 数组中存储
ReturnedStudent *addStudent(int id, char name[nameLen], int classNum){
    Student *student = newStudent();
    student->id = id;
    student->classNum = classNum;
    strcpy(student->name, name);

    students_[studentCount()] = student;
    studentCount_ ++;
    //  这里不写 students_[studentCount_ ++] 是为了保险起见，减少风险
    //  其实可以单独为针对 studentCount_ 的操作写几个函数来尽量确保 其原子性及安全性，但是懒

    int index = findLowerBound(id), cnt = studentCount_;
    while (cnt > index) {
        students_[cnt] = students_[cnt - 1];
        cnt --;
    }
    students_[index] = student;

    ReturnedStudent *res = newReturnedStudent();
    res->student = student;
    res->ok = 1;
    return res;
}

ReturnedStudent *removeStudent(int id) {
    int index = findStudent(id), cnt = studentCount();
    ReturnedStudent *res = newReturnedStudent();

    if (index == -1) {
        return res;
    }

    res->student = students_[index];
    res->ok = 1;
    while (index < cnt-1) {
        students_[index] = students_[index + 1];
        index ++;
    }
    studentCount_ --;
    students_[studentCount_] = newStudent();
    return res;
};

ReturnedStudent *updateStudent(int id, char newName[nameLen], int newClassNum){
    int index = findStudent(id);
    ReturnedStudent *res = seekStudent(id);
    if (index == -1) {
        return res;
    }
    res->student->classNum = newClassNum;
    strcpy(res->student->name, newName);
    return res;
};

//  二分
ReturnedStudent *seekStudent(int id) {
    int index = findStudent(id);
    ReturnedStudent * res = newReturnedStudent();

    if (index == -1) {
        return res;
    }
    res->student = students_[index];
    res->ok = 1;
    return res;
};

void seeAllStudent() {
    int cnt = studentCount();
    printf("seeAllStudent\n");
    for (int i = 0; i < cnt; i ++) {
        printf("id:%d \t name:%s \t classNum:%d \n", students_[i]->id, students_[i]->name, students_[i]->classNum);
    }
    printf("all end\n");
};


int studentCount() {
    if (studentCount_ == -1) {
        int i = 0;
        studentCount_ = 0;
        while (students_[i]->status == 1) {
            studentCount_ ++;
            i ++;
        }
    }
    return studentCount_;
}


//  二分
int findStudent(int id) {
    if (studentCount() <= 0) {
        return -1;
    }

    int l = 0, r = studentCount() - 1, mid;

    //  [l ,r]
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (students_[mid]->id == id) {
            return mid;
        }

        else if (students_[mid]->id < id) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int findLowerBound(int id) {
    if (studentCount() <= 0) {
        return -1;
    }

    int i = 0, cnt = studentCount_;

    while (i < cnt && students_[i]->id < id) {
        i ++;
    }
    return i;
}