//
// Created by firework on 2021/5/19.
//

#include "../utils/modal/dataStruct.h"

#ifndef PROJECT_STUDENTMODAL_H
#define PROJECT_STUDENTMODAL_H

const int studentLen = 100;


// type
typedef struct ReturnedStudent {
    Student *student;
    int ok;     //  返回的状态，0 失败、1 成功
} ReturnedStudent;

ReturnedStudent * newReturnedStudent() {
    return (ReturnedStudent *) malloc(sizeof(ReturnedStudent));
}

void initStudent();

ReturnedStudent *addStudent(int id, char name[nameLen]);
ReturnedStudent *removeStudent(int id);
ReturnedStudent *updateStudent(int id);
ReturnedStudent *seekStudent(int id);
void *seeAllStudent();
int cnt();
int _cnt();
int studentCount(Student *student[studentLen]);



#endif //PROJECT_STUDENTMODAL_H
