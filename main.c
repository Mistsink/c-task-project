
#include "./controller/studentController.c"
#include "./controller/courseController.c"

#include <stdio.h>

int main() {

        initStudentModal();
        initCourseModal();

        char input[10] = "";
        while (1) {
            render(IndexView);
            printf("Please input the number you'd like to do:\n");
            scanf("%s", input);
            if (checkoutInputNum(input, 6)) {

                //        "1. 学生相关",
                //        "2. 课程相关",
                //        "3. 选课相关",
                //        "4. 重新进入（清屏）"
                //        "5. 退出本系统"

                if (strcmp(input, "1") == 0) {
                    initStudentOS();
                } else if (strcmp(input, "2") == 0) {
                    initCourseOS();
                } else if (strcmp(input, "3") == 0) {
                    seekStudentHandler();
                } else if (strcmp(input, "4") == 0) {
                    continue;
                } else if (strcmp(input, "5") == 0) {
                    exitSystem(0);
                    return 0;   //  只是为了消除 clion 的警告提示，才加的一个return
                } else if (strcmp(input, "6") == 0) {
                    puts("Will refresh screen 2 seconds later");
                    sleep(2);
                    render(IndexView);
                }
            } else {
                puts("Invalid number! Please input valid number:");
            }
        }
    return 0;
}
