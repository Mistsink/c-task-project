//
// Created by firework on 2021/5/20.
//

#include "courseModal.h"

#include <string.h>


#ifndef PROJECT_COURSEMODAL_C
#define PROJECT_COURSEMODAL_C
int courseCount_ = 0;
Course *courses_[courseLen];

Courses *initCourseModal() {
    for (int i = 0; i < courseLen; i ++)
        courses_[i] = newCourse();
    return courses_;
};

//  暂时不考虑学生数量过多的情况，仅在一个 courseLen 大小的 数组中存储
ReturnedCourse *addCourse(int id, char name[nameLen], int teacherId){
    if (findCourse(id) != -1) {
        return newReturnedCourse();
    }
    Course *course = newCourse();
    course->id = id;
    course->teacherId = teacherId;
    strcpy(course->name, name);


    int index = findCourseLowerBound(id), cnt = courseCount();
    while (cnt > index) {
        courses_[cnt] = courses_[cnt - 1];
        cnt --;
    }
    courses_[index] = course;
    courseCount_ ++;
    //  这里不写 courses_[courseCount_ ++] 是为了保险起见，减少风险
    //  其实可以单独为针对 courseCount_ 的操作写几个函数来尽量确保 其原子性及安全性，但是懒


    ReturnedCourse *res = newReturnedCourse();
    res->course = course;
    res->ok = 1;
    return res;
}

ReturnedCourse *removeCourse(int id) {
    int index = findCourse(id), cnt = courseCount();
    ReturnedCourse *res = newReturnedCourse();

    if (index == -1) {
        return res;
    }

    res->course = courses_[index];
    res->ok = 1;
    while (index < cnt-1) {
        courses_[index] = courses_[index + 1];
        index ++;
    }
    courseCount_ --;
    courses_[courseCount_] = newCourse();
    return res;
};


//  二分
ReturnedCourse *seekCourse(int id) {
    int index = findCourse(id);
    ReturnedCourse * res = newReturnedCourse();

    if (index == -1) {
        return res;
    }
    res->course = courses_[index];
    res->ok = 1;
    return res;
};

Courses* getAllCourse() {
    return courses_;
};


int courseCount() {
    if (courseCount_ == -1) {
        int i = 0;
        courseCount_ = 0;
        while (courses_[i]->id != -1) {
            courseCount_ ++;
            i ++;
        }
    }
    return courseCount_;
}


//  二分
int findCourse(int id) {
    if (courseCount() <= 0) {
        return -1;
    }

    int l = 0, r = courseCount() - 1, mid;

    //  [l ,r]
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (courses_[mid]->id == id) {
            return mid;
        }

        else if (courses_[mid]->id < id) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int findCourseLowerBound(int id) {
    if (courseCount() <= 0) {
        return 0;
    }

    int i = 0, cnt = courseCount_;

    while (i < cnt && courses_[i]->id < id) {
        i ++;
    }
    return i;
}


#endif //PROJECT_COURSEMODAL_C