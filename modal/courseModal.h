//
// Created by firework on 2021/5/20.
//
#include "../utils/modal/dataStruct.h"

#ifndef PROJECT_COURSEMODAL_H
#define PROJECT_COURSEMODAL_H

const int courseLen = 100;

// type
typedef struct ReturnedCourse {
    Course *course;
    int ok;     //  返回的状态，0 失败、1 成功
} ReturnedCourse;

ReturnedCourse * newReturnedCourse() {
    ReturnedCourse * returnedCourse = (ReturnedCourse *) malloc(sizeof(ReturnedCourse));
    returnedCourse->course = NULL;
    returnedCourse->ok = 0;
    return returnedCourse;
}

typedef Course* Courses;

Courses *initCourseModal();

ReturnedCourse *addCourse(int id, char name[nameLen], int teacherId);
ReturnedCourse *removeCourse(int id);
ReturnedCourse *seekCourse(int id);
Courses* getAllCourse();
int courseCount();

int findCourse(int id);
int findCourseLowerBound(int id);

#endif //PROJECT_COURSEMODAL_H
