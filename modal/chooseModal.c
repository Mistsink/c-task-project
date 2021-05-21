//
// Created by firework on 2021/5/20.
//

#include "chooseModal.h"
#include "studentModal.c"
#include "courseModal.c"

#ifndef PROJECT_CHOOSEMODAL_C
#define PROJECT_CHOOSEMODAL_C

ReturnedChoose *addChoose(int studentId, int courseId) {
    int stuIndex = findStudent(studentId);
    if (stuIndex == -1) {
        return newReturnedChoose();
    }
    int courseIndex = findCourse(courseId);
    if (courseIndex == -1) {
        return newReturnedChoose();
    }
    ReturnedChoose * res = newReturnedChoose();
    ReturnedStudent *returnedStudent = addStudentCourse(studentId, courseId);
    res->student = returnedStudent->student;
    res->ok = returnedStudent->ok;
    return res;
}
ReturnedChoose *seekStudentScore(int studentId) {
    int stuIndex = findStudent(studentId);
    if (stuIndex == -1) {
        return newReturnedChoose();
    }
    ReturnedStudent *returnedStudent = seekStudent(studentId);
    ReturnedChoose *res = newReturnedChoose();
    res->student = returnedStudent->student;
    res->ok = returnedStudent->ok;
    return res;
}
ReturnedChoose *updateScore(int studentId, int courseId, int score) {
    int stuIndex = findStudent(studentId);
    if (stuIndex == -1) {
        return newReturnedChoose();
    }
    if (!hasStudentCourse(stuIndex, courseId)) {
        return newReturnedChoose();
    }

    ReturnedStudent * returnedStudent = updateStudentScore(studentId, courseId, score);
    ReturnedChoose *res = newReturnedChoose();

    res->student = returnedStudent->student;
    res->ok = returnedStudent->ok;
    return res;
};

#endif //PROJECT_CHOOSEMODAL_C