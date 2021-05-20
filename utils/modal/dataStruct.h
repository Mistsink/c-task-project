//
// Created by firework on 2021/5/19.
//

#include <stdlib.h>
#include <string.h>

#ifndef PROJECT_DATASTRUCT_H
#define PROJECT_DATASTRUCT_H

const int nameLen = 20;

typedef struct CourseStudent {
    int studentId;
    struct CourseStudent *next;
} CourseStudent;
CourseStudent * newCourseStudent() {
    CourseStudent * courseStudent = (CourseStudent *) malloc(sizeof(CourseStudent));
    courseStudent->studentId = -1;
    courseStudent->next = NULL;
    return courseStudent;
}

typedef struct Course {
    int id;
    char name[nameLen];
    CourseStudent *student;
    int teacherId;
} Course;

Course * newCourse() {
    Course *course = (Course *) malloc(sizeof(Course));
    strcpy(course->name, "");
    course->id = -1;
    course->student = newCourseStudent();
    course->teacherId = -1;
    return course;
}

typedef struct StudentCourse {
    int courseId;
    struct StudentCourse * next;
} StudentCourse;
StudentCourse * newStudentCourse() {
    StudentCourse * studentCourse = (StudentCourse *) malloc(sizeof(StudentCourse));
    studentCourse->courseId = -1;
    studentCourse->next = NULL;
    return studentCourse;
}

typedef struct Student {
    int id;
    int classNum;
    char name[nameLen];
    StudentCourse *course;
    double totalScore;          //  学生各科总成绩
    int status;                 //  学生的状态，0 不存在、1 存在、2 已删除
} Student;

Student * newStudent() {
    Student *student = (Student *) malloc(sizeof(Student));
    student->id = -1;
    student->classNum = -1;
    strcpy(student->name, "");
    student->course = newStudentCourse();
    student->totalScore = -1;
    student->status = 0;
    return student;
}

#endif //PROJECT_DATASTRUCT_H
