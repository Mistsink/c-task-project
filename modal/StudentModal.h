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
    ReturnedStudent * returnedStudent = (ReturnedStudent *) malloc(sizeof(ReturnedStudent));
    returnedStudent->student = NULL;
    returnedStudent->ok = 0;
    return returnedStudent;
}

typedef Student* Students;

Students *initStudentModal();

ReturnedStudent *addStudent(int id, char name[nameLen], int classNum);
ReturnedStudent *removeStudent(int id);
ReturnedStudent *updateStudent(int id, char newName[nameLen], int newClassNum);
ReturnedStudent *seekStudent(int id);
void seeAllStudent();
int studentCount();

int findStudent(int id);
int findLowerBound(int id);


#endif //PROJECT_STUDENTMODAL_H
