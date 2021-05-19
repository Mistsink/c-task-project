//
// Created by firework on 2021/5/19.
//

#include "main.h"
#include "../utils/view/view_util.h"

void render(int viewCategory) {
    clearScreen();
    renderView(viewCategory);
}

void renderView(int viewCategory) {
    switch (viewCategory) {
        case IndexView:
            return renderIndex();
        case StudentView:
            return renderStudent();
        case CourseView:
            return renderCourse();
        case ChooseView:
            return renderChoose();
    }
}