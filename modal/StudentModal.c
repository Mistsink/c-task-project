//
// Created by firework on 2021/5/19.
//

#include "StudentModal.h"
#include <string.h>

ReturnedStudent *addStudent(int id, char name[nameLen]){
    Student *student = newStudent();
    student->id = id;
    strcpy(student->name, name);
    ReturnedStudent *res = newReturnedStudent();
    res->student = student;
    res->ok = 1;
    return res;
}

ReturnedStudent *removeStudent(int id) {

};
ReturnedStudent *updateStudent(int id);
ReturnedStudent *seekStudent(int id) {

};
void *seeAllStudent();

int cnt() {
    return 9;
}
int _cnt() {
    return 9;
}

int studentCount(Student *student[studentLen]) {
    return 2;
}