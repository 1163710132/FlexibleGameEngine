//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_GAMEENGINE_H
#define FLEXIBLEGAMEENGINE_GAMEENGINE_H

#include "Common.h"
#include "Symbol.h"

class SubSystem;
class GameConfig;
class GameObject;

class GameEngine {
public:
    List<SubSystem*> system_list;
    List<Thread> thread_list;
    GameConfig* config;
    Dictionary<size_t, GameObject*> game_object_table;
    List<GameObject*> object_buffer;
    size_t next_id;
public:
    void load_system(SubSystem* system);
    void new_thread(Delegate<void()> delegate);
    void execute_loop();
    GameObject* create_game_object();
    GameObject* get_game_object(size_t id);
};


#endif //FLEXIBLEGAMEENGINE_GAMEENGINE_H
