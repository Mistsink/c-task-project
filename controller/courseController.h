//
// Created by firework on 2021/5/20.
//

#include "../modal/courseModal.h"

#ifndef PROJECT_COURSECONTROLLER_H
#define PROJECT_COURSECONTROLLER_H
void initCourseOS();

void addCourseHandler();
void removeCourseHandler();
void seekCourseHandler();
void seeAllCourseHandler();


void printCourse(Course *course);
#endif //PROJECT_COURSECONTROLLER_H
