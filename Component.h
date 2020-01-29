//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_COMPONENT_H
#define FLEXIBLEGAMEENGINE_COMPONENT_H

#include "Common.h"
#include "Symbol.h"

#define REGISTER_COMPONENT(NAME) \
    static constexpr const char* COMPONENT_NAME = #NAME; \
    static Symbol get_symbol(){ \
        static Symbol symbol{COMPONENT_NAME}; \
        return symbol; \
    }; \

class Component {
public:
    static void register_component() = delete;
    virtual void init() = 0;
};

class HelloComponent: public Component{
public:
    REGISTER_COMPONENT(HelloComponent);
};


#endif //FLEXIBLEGAMEENGINE_COMPONENT_H
