//
// Created by firework on 2021/5/19.
//

#include "main.h"
#include "../utils/view/viewUtil.c"
#include <stdio.h>
#ifndef PROJECT_MAIN_C
#define PROJECT_MAIN_C

void render(int viewCategory) {
    clearScreen();
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
    renderTop_();

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
        //        "4. 查看全部学生信息",
        //        "5. 返回到主页",
        //        "6. 重新进入（清屏）"
        //        "7. 退出本系统"
        "1. add student info",
        "2. remove student info",
        "3. check student info",
        "4. see all students info",
        "5. back to index",
        "6. refresh screen",
        "7. exit system"
};


void renderStudent() {
    renderCategory_(studentViewLabels, 7);
}


char CourseViewLabels[][LabelLen] = {
        //      1. 添加课程
        ////    2. 删除课程
        ////    3. 查看课程
        ////    4. 查看全部课程
        //        "5. 返回到主页",
        //        "6. 重新进入（清屏）"
        //        "7. 退出本系统"
        "1. add course",
        "2. remove course",
        "3. check course info",
        "4. check all course info",
        "5. back to index",
        "6. refresh screen",
        "7. exit system"
};
void renderCourse(){
    renderCategory_(CourseViewLabels, 7);
}

char ChooseViewLabels[][LabelLen] = {
        "1. add choose for student",
        "2. remove choose for student",
        "3. update score for student",
        "4. check chose info",
        "5. back to index",
        "6. refresh screen",
        "7. exit system"

};
void renderChoose(){
    renderCategory_(ChooseViewLabels, 7);
}


#endif //PROJECT_MAIN_C