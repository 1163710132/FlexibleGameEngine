//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_SPRITECOMPONENT_H
#define FLEXIBLEGAMEENGINE_SPRITECOMPONENT_H

#include "Component.h"

class SpriteComponent: public Component {
public:
    const char* path{};
    void init() override;
};


#endif //FLEXIBLEGAMEENGINE_SPRITECOMPONENT_H
