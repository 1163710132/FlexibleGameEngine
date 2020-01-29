//
// Created by chenjs on 1/15/20.
//

#ifndef FLEXIBLEGAMEENGINE_WINDOWCOMPONENT_H
#define FLEXIBLEGAMEENGINE_WINDOWCOMPONENT_H

#include "Component.h"

class WindowComponent: public Component {
public:
    REGISTER_COMPONENT(WindowComponent);
public:
    size_t width = 960;
    size_t height = 540;
    const char* title = "Hello";

    void init() override {

    }
};


#endif //FLEXIBLEGAMEENGINE_WINDOWCOMPONENT_H
