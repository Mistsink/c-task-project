//
// Created by firework on 2021/5/20.
//

#include "../modal/studentModal.h"
#include "../modal/chooseModal.h"

#ifndef PROJECT_CHOOSECONTROLLER_H
#define PROJECT_CHOOSECONTROLLER_H
void initChooseOS();

void addChooseHandler();
void updateScoreHandler();
void seekChooseHandler();

void printChoose(ReturnedChoose *returnedChoose);
#endif //PROJECT_CHOOSECONTROLLER_H
