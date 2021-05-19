//
// Created by firework on 2021/5/19.
//

#include <stdlib.h>
#include <string.h>

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
    Course *course = (Course *) malloc(sizeof(Course));
    strcpy(course->name, "");
    course->id = -1;
    course->score = -1;
    strcpy(course->teacher, "");
    return course;
}

typedef struct Student {
    int id;
    int classNum;
    char name[nameLen];
    Course *courses[courseLen];
    double totalScore;          //  学生各科总成绩
    int status;                 //  学生的状态，0 不存在、1 存在、2 已删除
} Student;

Student * newStudent() {
    Student *student = (Student *) malloc(sizeof(Student));
    student->id = -1;
    student->classNum = -1;
    strcpy(student->name, "");
    student->courses[0] = NULL;
    student->totalScore = -1;
    student->status = 0;
    return student;
}

#endif //PROJECT_DATASTRUCT_H
