//
// Created by firework on 2021/5/20.
//

#include "controllerUtil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#ifndef PROJECT_CONTROLLERUTIL_C
#define PROJECT_CONTROLLERUTIL_C


int checkoutInputNum(char *input, int maxNum) {
    for (int i = 1; i <= maxNum; i ++) {
        char a = '0';
        a += i;

        char t[2] = {a};
        if (strcmp(input, t) == 0) {
            return 1;
        }
    }
    return 0;
}

void exitSystem(int exitSymbol) {
    puts("you will exit system after 3 seconds.");
    puts("well");
    sleep(1);
    puts("ok");
    sleep(1);
    puts("good bye ~");
    sleep(1);

    exit(exitSymbol);
}

#endif //PROJECT_CONTROLLERUTIL_C