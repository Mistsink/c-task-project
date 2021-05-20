//
// Created by firework on 2021/5/20.
//

#include "courseController.h"
#include "../view/main.c"
#include "../modal/courseModal.c"
#include "../utils/controller/controllerUtil.c"

#ifndef PROJECT_COURSECONTROLLER_C
#define PROJECT_COURSECONTROLLER_C
void initCourseOS() {
    render(CourseView);

    char input[10] = "";
    while (1) {
        printf("Please input the number you'd like to do:\n");
        scanf("%s", input);
        if (checkoutInputNum(input, 6)) {

            //      1. 添加课程
            ////    2. 删除课程
            ////    3. 查看课程
            ////    4. 查看全部课程
            //        "5. 返回到主页",
            //        "6. 重新进入（清屏）"
            //        "7. 退出本系统"

            if (strcmp(input, "1") == 0) {
                addCourseHandler();
            } else if (strcmp(input, "2") == 0) {
                removeCourseHandler();
            } else if (strcmp(input, "3") == 0) {
                seekCourseHandler();
            } else if (strcmp(input, "4") == 0) {
                seeAllCourseHandler();
            } else if (strcmp(input, "5") == 0) {
                return;
            } else if (strcmp(input, "6") == 0) {
                puts("Will refresh screen 2 seconds later");
                sleep(2);
                render(CourseView);
            } else if (strcmp(input, "7") == 0) {
                return exitSystem(0);
            }
        } else {
            puts("Invalid number! Please input valid number:");
        }
    }
};

void addCourseHandler() {
    int id, teacherId;
    char name[nameLen];
    puts("Please input info of course with the format: '{id}-{name}-{teacherName}'");
    puts("ex. 00-01-Jhon");
    scanf("%d-%d-%s", &id, &teacherId, name);
    ReturnedCourse *res = addCourse(id, name, teacherId);
    if (!res->ok) {
        puts("\nFailed to add course. err: repetitive id.\n");
    } else {
        puts("\nSuccessfully added course");
        puts("course:");
        printCourse(res->course);
        puts("");
    }
};
void removeCourseHandler() {
    int id;
    puts("Please input id of course to remove with the format: '{id}'");
    puts("ex. 00");
    scanf("%d", &id);
    ReturnedCourse *res = removeCourse(id);
    if (!res->ok) {
        puts("\nFailed to add course. err: id not found.\n");
    } else {
        puts("\nSuccessfully removed course");
        puts("course:");
        printCourse(res->course);
        puts("");
    }
};
void seekCourseHandler() {
    int id;
    puts("Please input id of course to seek with the format: '{id}'");
    puts("ex. 00");
    scanf("%d", &id);
    ReturnedCourse *res = seekCourse(id);
    if (!res->ok) {
        puts("\nFailed to seek course. err: id not found.\n");
    } else {
        puts("\nSuccessfully seek course");
        puts("course:");
        printCourse(res->course);
        puts("");
    }
};
void seeAllCourseHandler() {
    Courses* courses = getAllCourse();
    Course course;
    int cnt = courseCount();
    if (cnt == 0) {
        puts("There is no course.\n");
        return;
    }
    for (int i = 0; i < cnt; i ++) {
        course = *courses[i];
        puts("course:");
        printCourse(&course);
    }
    puts("");
};


void printCourse(Course *course) {
    printf("id:%d\tname:%s\tteacherId:%d\n", course->id, course->name, course->teacherId);
};

#endif //PROJECT_COURSECONTROLLER_C