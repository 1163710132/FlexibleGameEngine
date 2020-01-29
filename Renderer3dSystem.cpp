//
// Created by chenjs on 1/15/20.
//

#include "Renderer3dSystem.h"

#include "GameObject.h"
#include "WindowComponent.h"
#include "Structure.h"
#include "MeshFilterComponent.h"

#include <GLFW/glfw3.h>

void Renderer3dSystem::on_game_object_add(GameObject *object) {
    if(object->has_component<WindowComponent>()){
        assert(window_handle == nullptr);
        auto* window_component = object->get_component<WindowComponent>();
        GLFWwindow* window = glfwCreateWindow(
                window_component->width, window_component->height, window_component->title,
                nullptr, nullptr);
        glfwShowWindow(window);
        window_handle = window;
    }
    if(object->has_component<MeshFilterComponent>()){
        mesh_filter_table[object->id] = object->get_component<MeshFilterComponent>();
    }
}

void Renderer3dSystem::on_game_object_remove(GameObject *object) {
    if(object->has_component<WindowComponent>()){
        window_handle = nullptr;
    }
    if(object->has_component<MeshFilterComponent>()){
        mesh_filter_table.erase(object->id);
    }
}

void Renderer3dSystem::on_system_load(GameEngine *engine) {
    glfwInit();
}

Renderer3dSystem::Renderer3dSystem() {
    add_task(new Renderer3dTask(this));
}

void Renderer3dTask::execute(GameEngine *engine) {
    if(system->window_handle != nullptr){
        auto* window = (GLFWwindow*)system->window_handle;
        glfwMakeContextCurrent(window);
        //BEGIN DO RENDER
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for(auto [id, mesh_filter]: system->mesh_filter_table){
            Mesh& mesh = *mesh_filter->mesh;
            glBegin(GL_TRIANGLES);
            for(uint32_t vertex_index: mesh.triangle_list){
                auto [a, b, c] = mesh.vertex_list[mesh.triangle_list[vertex_index]];
                glVertex3f(a, b, c);
            }
            glEnd();
        }
        //END DO RENDER
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}
