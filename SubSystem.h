//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_SUBSYSTEM_H
#define FLEXIBLEGAMEENGINE_SUBSYSTEM_H

#include "Symbol.h"

class LoopTask;
class GameObject;
class GameConfig;
class GameEngine;

#define REGISTER_SYSTEM(NAME) \
    static constexpr const char* SYSTEM_NAME = #NAME; \
    static Symbol get_symbol(){ static Symbol symbol{SYSTEM_NAME}; return symbol; };

class SubSystem {
public:
    List<LoopTask*> task_list;
public:
    [[nodiscard]] const List<LoopTask*>& get_task_list() const{
        return task_list;
    }
    virtual void on_game_object_add(GameObject* object) = 0;
    virtual void on_game_object_remove(GameObject* object) = 0;
    virtual void on_system_load(GameEngine* engine) = 0;

protected:
    void add_task(LoopTask* task){
        task_list.push_back(task);
    }
};

class HelloSubSystem: public SubSystem{
    REGISTER_SYSTEM(HelloSubSystem);
};


#endif //FLEXIBLEGAMEENGINE_SUBSYSTEM_H
