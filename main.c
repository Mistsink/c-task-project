
#include "./modal/StudentModal.c"

#include <stdio.h>

int main() {
    Student *students[studentLen];
    for (int i = 0; i < 10; i ++)
        students[i] = newStudent();
    int a = studentCount(students);
    printf("count:%d", a);
    printf("count:%s\n", students[0]->name);

    printf("asdkjh");
    return 0;
}
