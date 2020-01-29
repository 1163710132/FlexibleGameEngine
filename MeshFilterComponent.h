//
// Created by chenjs on 1/17/20.
//

#ifndef FLEXIBLEGAMEENGINE_MESHFILTERCOMPONENT_H
#define FLEXIBLEGAMEENGINE_MESHFILTERCOMPONENT_H

#include "Component.h"

#include "Structure.h"

class MeshFilterComponent: public Component {
public:
    REGISTER_COMPONENT(MeshFilterComponent);
public:
    Unique<Mesh> mesh;
};


#endif //FLEXIBLEGAMEENGINE_MESHFILTERCOMPONENT_H
