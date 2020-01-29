//
// Created by chenjs on 1/17/20.
//

#ifndef FLEXIBLEGAMEENGINE_TRANSFORMCOMPONENT_H
#define FLEXIBLEGAMEENGINE_TRANSFORMCOMPONENT_H

#include "Component.h"
#include "Structure.h"

class TransformComponent: public Component {
public:
    REGISTER_COMPONENT(TransformComponent);

    Vector3f position{};
    Vector3f rotation{};
    Vector3f scale{};
public:
    explicit TransformComponent(): Component(){};
};


#endif //FLEXIBLEGAMEENGINE_TRANSFORMCOMPONENT_H
