
#include "./modal/StudentModal.c"

#include <stdio.h>

int main() {
    Students *students = initStudent();

    printf("count:%d\n", studentCount());

    seeAllStudent();

    for (int i = 8;i >= 0; i --)
        addStudent(i, "asd", 1234);

    printf("count:%d\n", studentCount());
    seeAllStudent();

    addStudent(5, "ass", 1342);
    removeStudent(3);
    updateStudent(1, "asfjkg", 1234);
    seeAllStudent();


    return 0;
}
