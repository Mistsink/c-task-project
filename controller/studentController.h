//
// Created by firework on 2021/5/20.
//
#include "../modal/studentModal.h"

#ifndef PROJECT_STUDENTCONTROLLER_H
#define PROJECT_STUDENTCONTROLLER_H

void initStudentOS();

void addStudentHandler();
void removeStudentHandler();
void seekStudentHandler();
void seeAllStudentHandler();

void printStudent(Student *student);
#endif //PROJECT_STUDENTCONTROLLER_H
