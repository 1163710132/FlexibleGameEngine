#include <iostream>

#include "GameEngine.h"
#include "GameObject.h"

#include "WindowComponent.h"

#include "Renderer3dSystem.h"

#include <thread>

int main(int argc, char** argv) {
    auto* engine = new GameEngine();
    engine->load_system(new Renderer3dSystem());
    auto* window = engine->create_game_object();
    auto* window_component = window->add_component<WindowComponent>();
    while(true){
        system("sleep 0.1");
        engine->execute_loop();
    }
    std::cout << "Hello, World!" << std::endl;
    for(auto&& thread: engine->thread_list){
        thread.join();
    }
    getchar();
    return 0;
}
