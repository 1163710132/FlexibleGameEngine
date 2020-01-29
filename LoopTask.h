//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_LOOPTASK_H
#define FLEXIBLEGAMEENGINE_LOOPTASK_H

#include "Common.h"
#include "Symbol.h"

#define REGISTER_TASK(NAME) \
    explicit NAME(): LoopTask(#NAME){}; \

class GameEngine;

class LoopTask {
private:
    Symbol symbol;
    List<Symbol> dependence_list;
public:
    explicit LoopTask(Symbol symbol): symbol(symbol){};
    [[nodiscard]] Symbol get_symbol() const {
        return symbol;
    }
    [[nodiscard]] const List<Symbol>& get_dependence_list() const{
        return dependence_list;
    }
    virtual void execute(GameEngine* engine) = 0;
    virtual ~LoopTask() = default;

protected:
    void add_dependence(Symbol dependence){
        dependence_list.push_back(dependence);
    }

public:
    static List<LoopTask*> topo_sort(const List<LoopTask*>& task_list);
};

template <typename TSystem>
class TaskTemplate: public LoopTask{
protected:
    TSystem* system;
public:
    explicit TaskTemplate(TSystem* system): LoopTask(TSystem::get_symbol()), system(system){}
};


#endif //FLEXIBLEGAMEENGINE_LOOPTASK_H
