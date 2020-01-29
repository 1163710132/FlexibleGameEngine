//
// Created by chenjs on 1/15/20.
//

#ifndef FLEXIBLEGAMEENGINE_RENDERER3DSYSTEM_H
#define FLEXIBLEGAMEENGINE_RENDERER3DSYSTEM_H

#include "SubSystem.h"
#include "LoopTask.h"
#include "Structure.h"
#include "MeshFilterComponent.h"

class Renderer3dSystem: public SubSystem {
public:
    REGISTER_SYSTEM(Renderer3dSystem);
public:
    void* window_handle{};
    Dictionary<size_t, MeshFilterComponent*> mesh_filter_table;
public:
    explicit Renderer3dSystem();

    void on_game_object_add(GameObject *object) override;

    void on_game_object_remove(GameObject *object) override;

    void on_system_load(GameEngine *engine) override;
};

class Renderer3dTask: public TaskTemplate<Renderer3dSystem>{
public:
    explicit Renderer3dTask(Renderer3dSystem* system): TaskTemplate<Renderer3dSystem>(system){};
    void execute(GameEngine *engine) override;
};

#endif //FLEXIBLEGAMEENGINE_RENDERER3DSYSTEM_H
