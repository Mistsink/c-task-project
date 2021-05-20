//
// Created by firework on 2021/5/19.
//

#include "main.h"
#include "../utils/view/viewUtil.c"
#include <stdio.h>

void render(int viewCategory) {
//    clearScreen();
    renderView(viewCategory);
}

void renderView(int viewCategory) {
    switch (viewCategory) {
        case IndexView:
            return renderIndex();
        case StudentView:
            return renderStudent();
        case CourseView:
            return renderCourse();
        case ChooseView:
            return renderChoose();
    }
}


void renderLabels(char labels[][LabelLen], int labelNum) {
    for (int i = 0; i < labelNum; i ++) {
        renderLeft_();
        printf("|");

        renderPaddingLeft_();
        for (int j = 0; j < LabelLen; j ++) {
            int c = labels[i][j] == '\0' ? ' ' : labels[i][j];
            putchar(c);
        }
        renderPaddingLeft_();
        printf("|\n");
    }
}


void renderCategory_(char labels[][LabelLen], int labelNum) {
    renderTop_();
    renderLeft_();
    putchar('|');
    renderTransverseLine_();
    puts("|");
    renderPaddingTop_();
    renderLabels(labels, labelNum);
    renderPaddingTop_();
    renderLeft_();
    putchar('|');
    renderTransverseLine_();
    puts("|");
}

char IndexViewLabels[][LabelLen] = {
        "1. Student os",
        "2. Course os",
        "3. Choose course os",
        "4. exit system"
};
void renderIndex(){
    renderCategory_(IndexViewLabels, 4);
}


char studentViewLabels[][LabelLen] = {
//        "1. 添加学生信息",
//        "2. 删除学生信息",
//        "3. 查看学生信息",
//        "4. 返回到主页",
//        "5. 退出本系统"
        "1. add student info",
        "2. remove student info",
        "3. check student info",
        "4. back to index",
        "5. exit system"
};


void renderStudent() {
    renderCategory_(studentViewLabels, 5);
}


char CourseViewLabels[][LabelLen] = {
        "1. add course",
        "2. remove course",
        "3. update course",
        "4. check course info",
        "5. back to index",
        "6. exit system"
};
void renderCourse(){
    renderCategory_(CourseViewLabels, 6);
}

char ChooseViewLabels[][LabelLen] = {
        "1. add choose for student",
        "2. remove choose for student",
        "3. update score for student",
        "4. check chose info",
        "5. back to index",
        "6. exit system"
};
void renderChoose(){
    renderCategory_(ChooseViewLabels, 6);
}