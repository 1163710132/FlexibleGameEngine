//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_GAMEOBJECT_H
#define FLEXIBLEGAMEENGINE_GAMEOBJECT_H

#include "Common.h"
#include "Symbol.h"

class Component;

class GameObject {
public:
    Dictionary<size_t, Component*> component_table;
    GameObject* parent{};
    size_t id{};
public:
    explicit GameObject(size_t id): id(id){};
    template <typename TComponent>
    TComponent* get_component(){
        Symbol symbol = TComponent::get_symbol();
        if(component_table.contains(symbol.id)){
            return static_cast<TComponent*>(component_table[symbol.id]);
        }
        return nullptr;
    }
    template <typename TComponent>
    bool has_component(){
        Symbol symbol = TComponent::get_symbol();
        return component_table.contains(symbol.id);
    }
    template <typename TComponent, typename... TArgs>
    TComponent* add_component(TArgs&&... args){
        auto* component = new TComponent(std::forward(args)...);
        component_table[TComponent::get_symbol().id] = component;
        return component;
    }
};


#endif //FLEXIBLEGAMEENGINE_GAMEOBJECT_H
