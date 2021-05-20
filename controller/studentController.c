//
// Created by firework on 2021/5/20.
//

#include "studentController.h"
#include "../view/main.c"
#include "../modal/StudentModal.c"
#include "../utils/controller/mainController.c"

#include <stdio.h>
#include <string.h>

void initStudentOS() {
    render(StudentView);
    initStudentModal();

    char input[10] = "";
    while (1) {
        printf("Please input the number you'd like to do:\n");
        scanf("%s", input);
        if (checkoutInputNum(input, 6)) {

            //        "1. 添加学生信息",
            //        "2. 删除学生信息",
            //        "3. 查看学生信息",
            //        "4. 返回到主页",
            //        "5. 退出本系统"
            //        "6. 重新进入（清屏）"

            if (strcmp(input, "1") == 0) {
                addStudentHandler();
            } else if (strcmp(input, "2") == 0) {
                removeStudentHandler();
            } else if (strcmp(input, "3") == 0) {
                checkStudentHandler();
            } else if (strcmp(input, "4") == 0) {
                return;
            } else if (strcmp(input, "5") == 0) {
                return exitSystem(0);
            } else if (strcmp(input, "6") == 0) {
                puts("Will refresh screen 2 seconds later");
                sleep(2);
                render(StudentView);
            }
        } else {
            puts("Invalid number! Please input valid number:");
        }
    }
}


void addStudentHandler() {
    int id, classNum;
    char name[nameLen];
    puts("Please input info of student with the format: '{id}-{classNum}-{name}'");
    puts("ex. 00-01-Jhon");
    scanf("%d-%d-%s", &id, &classNum, name);
    ReturnedStudent *res = addStudent(id, name, classNum);
    if (!res->ok) {
        puts("\nFailed to add student. err: repetitive id.\n");
    } else {
        puts("\nSuccessfully added student");
        printStudent(res->student);
        puts("");
    }
}

void removeStudentHandler() {
    int id;
    puts("Please input id of student to remove with the format: '{id}'");
    puts("ex. 00");
    scanf("%d", &id);
    ReturnedStudent *res = removeStudent(id);
    if (!res->ok) {
        puts("\nFailed to add student. err: id not found.\n");
    } else {
        puts("\nSuccessfully removed student");
        printStudent(res->student);
        puts("");
    }
}

void checkStudentHandler() {
    int id;
    puts("Please input id of student to seek with the format: '{id}'");
    puts("ex. 00");
    scanf("%d", &id);
    ReturnedStudent *res = seekStudent(id);
    if (!res->ok) {
        puts("\nFailed to seek student. err: id not found.\n");
    } else {
        puts("\nSuccessfully seek student");
        printStudent(res->student);
        puts("");
    }
}


void printStudent(Student *student) {
    printf("Student:\nid:%d\tname:%s\tclassNum:%d\n", student->id, student->name, student->classNum);
}