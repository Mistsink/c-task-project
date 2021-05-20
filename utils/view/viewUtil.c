//
// Created by firework on 2021/5/19.
//

#include "viewUtil.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef PROJECT_VIEW_UTIL_C
#define PROJECT_VIEW_UTIL_C


void clearScreen() {
    system("clear");
}


void renderLeft_() {
    for (int i = 0;i < LEFT; i ++)
        putchar(' ');
}
void renderPaddingLeft_() {
    for (int i = 0;i < PADDING; i ++)
        printf(" ");
}
void renderPaddingTop_() {
    for (int j = 0; j < PADDING_TOP; j ++) {
        renderLeft_();
        putchar('|');
        int len = PADDING * 2 + LabelLen;
        for (int i = 0; i < len; i++) {
            putchar(' ');
        }
        puts("|");
    }
}
void renderTop_() {
    for (int i = 0; i < TOP; i ++)
        printf("\n");
}
void renderTransverseLine_() {
    int len = PADDING * 2 + LabelLen;
    for (int i = 0; i < len ; i ++)
        putchar('-');
}

#endif //PROJECT_VIEW_UTIL_C