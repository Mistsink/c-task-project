//
// Created by firework on 2021/5/19.
//

#include <stdlib.h>

#ifndef PROJECT_DATASTRUCT_H
#define PROJECT_DATASTRUCT_H

const int nameLen = 20;
const int courseLen = 10;

typedef struct Course {
    int id;
    char name[nameLen];
    double score;
    char teacher[nameLen];

} Course;

Course * newCourse() {
    return (Course *) malloc(sizeof(Course));
}

typedef struct Student {
    int id;
    char name[nameLen];
    Course courses[courseLen];
    double totalScore;          //  学生各科总成绩
    int status;                 //  学生的状态，1 存在、2 已删除
} Student;

Student * newStudent() {
    return (Student *) malloc(sizeof(Student));
}

#endif //PROJECT_DATASTRUCT_H
