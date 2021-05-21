//
// Created by firework on 2021/5/20.
//

#include "../utils/modal/dataStruct.h"

#ifndef PROJECT_CHOOSEMODAL_H
#define PROJECT_CHOOSEMODAL_H


// type
typedef struct ReturnedChoose {
    Student *student;
    int ok;     //  返回的状态，0 失败、1 成功
} ReturnedChoose;

ReturnedChoose * newReturnedChoose() {
    ReturnedChoose * returnedChoose = (ReturnedChoose *) malloc(sizeof(ReturnedChoose));
    returnedChoose->student = NULL;
    returnedChoose->ok = 0;
    return returnedChoose;
}

ReturnedChoose *addChoose(int studentId, int courseId);
ReturnedChoose *seekStudentScore(int studentId);
ReturnedChoose *updateScore(int studentId, int courseId, int score);

#endif //PROJECT_CHOOSEMODAL_H
