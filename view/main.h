//
// Created by firework on 2021/5/19.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

const int TOP = 30;
const int LEFT = 40;

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
#endif //PROJECT_MAIN_H
