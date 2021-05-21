//
// Created by firework on 2021/5/20.
//

#include "chooseController.h"

#include "../view/main.c"
#include "../modal/chooseModal.c"
#include "../utils/controller/controllerUtil.c"

#ifndef PROJECT_CHOOSECONTROLLER_C
#define PROJECT_CHOOSECONTROLLER_C

void initChooseOS() {
    render(ChooseView);

    char input[10] = "";
    while (1) {
        printf("Please input the number you'd like to do:\n");
        scanf("%s", input);
        if (checkoutInputNum(input, 6)) {

            //      "1. add choose for student",
            //        "2. update score for student",
            //        "3. seek chose for student",
            //        "4. back to index",
            //        "5. refresh screen",
            //        "6. exit system"

            if (strcmp(input, "1") == 0) {
                addChooseHandler();
            } else if (strcmp(input, "2") == 0) {
                updateScoreHandler();
            } else if (strcmp(input, "3") == 0) {
                seekChooseHandler();
            } else if (strcmp(input, "4") == 0) {
                return;
            } else if (strcmp(input, "5") == 0) {
                puts("Will refresh screen 2 seconds later");
                sleep(2);
                render(ChooseView);
            } else if (strcmp(input, "6") == 0) {
                return exitSystem(0);
            }
        } else {
            puts("Invalid number! Please input valid number:");
        }
    }
}

void addChooseHandler() {
    int stuId, courseId;
    puts("Please input info of studentId and courseId with the format: '{stuId}-{courseId}'");
    puts("ex. 00-01");
    scanf("%d-%d", &stuId, &courseId);
    ReturnedChoose *res = addChoose(stuId, courseId);
    if (!res->ok) {
        puts("\nFailed to choose course for student. err: id not found.\n");
    } else {
        puts("\nSuccessfully choose course for student.");
        puts("Chose:");
        printChoose(res);
        puts("");
    }
};
void updateScoreHandler() {
    int stuId, courseId, score;
    puts("Please input info of studentId and courseId with the format: '{stuId}-{courseId}-{score}'");
    puts("ex. 00-01-98");
    scanf("%d-%d-%d", &stuId, &courseId, &score);
    ReturnedChoose *res = updateScore(stuId, courseId, score);
    if (!res->ok) {
        puts("\nFailed to update score for student. err: id not found.\n");
    } else {
        puts("\nSuccessfully update score for student.");
        puts("Chose:");
        printChoose(res);
        puts("");
    }
};
void seekChooseHandler() {
    int stuId;
    puts("Please input info of studentId with the format: '{stuId}'");
    puts("ex. 00");
    scanf("%d", &stuId);
    ReturnedChoose *res = seekStudentScore(stuId);
    if (!res->ok) {
        puts("\nFailed to seek student's scores. err: id not found.\n");
    } else {
        puts("\nSuccessfully choose seek student's scores.");
        puts("Chose:");
        printChoose(res);
        puts("");
    }
};

void printChoose(ReturnedChoose *returnedChoose) {
    int stuId = returnedChoose->student->id;
    StudentCourse *studentCourse = returnedChoose->student->course;
    while (studentCourse->next != NULL) {
        printf("studentId:%d, courseId:%d, score:%d\n", stuId, studentCourse->courseId, studentCourse->score);
        studentCourse = studentCourse->next;
    }
};


#endif //PROJECT_CHOOSECONTROLLER_C