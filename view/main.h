//
// Created by firework on 2021/5/19.
//
#include "../utils/view/viewUtil.h"
#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H


const int IndexView = 0;
const int StudentView = 1;
const int CourseView = 2;
const int ChooseView = 3;

void render(int);

void renderView(int);

void renderIndex();
void renderStudent();
void renderCourse();
void renderChoose();

void renderLabels(char labels[][LabelLen], int labelNum);
#endif //PROJECT_MAIN_H
