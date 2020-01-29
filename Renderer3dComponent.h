//
// Created by chenjs on 1/16/20.
//

#ifndef FLEXIBLEGAMEENGINE_RENDERER3DCOMPONENT_H
#define FLEXIBLEGAMEENGINE_RENDERER3DCOMPONENT_H

#include "Component.h"
#include "Structure.h"

class Renderer3dComponent: public Component {
public:
    REGISTER_COMPONENT(Renderer3dComponent);
    List<Triangle<Vertex1p>> vertex_list;

public:
    explicit Renderer3dComponent(): Component(){

    }
};


#endif //FLEXIBLEGAMEENGINE_RENDERER3DCOMPONENT_H
