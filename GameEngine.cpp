//
// Created by chenjs on 1/13/20.
//

#include "GameEngine.h"

#include "SubSystem.h"
#include "LoopTask.h"
#include "GameObject.h"

void GameEngine::execute_loop() {
    for(SubSystem* system: system_list){
        for(GameObject* object: object_buffer){
            system->on_game_object_add(object);
        }
    }
    object_buffer.clear();
    List<LoopTask*> task_list;
    for(auto* sub_system: system_list){
        List<LoopTask*> system_task_list = sub_system->get_task_list();
        task_list.insert(task_list.end(), system_task_list.begin(), system_task_list.end());
    }
    task_list = LoopTask::topo_sort(task_list);
    for(auto* task: task_list){
        task->execute(this);
    }
}

void GameEngine::load_system(SubSystem *system) {
    system->on_system_load(this);
    system_list.push_back(system);
}

void GameEngine::new_thread(Delegate<void()> delegate) {
    thread_list.push_back(Thread(move(delegate)));
}

GameObject *GameEngine::create_game_object() {
    auto* object = new GameObject(next_id++);
    game_object_table[object->id] = object;
    object_buffer.push_back(object);
    return object;
}

GameObject *GameEngine::get_game_object(size_t id) {
    return game_object_table[id];
}
