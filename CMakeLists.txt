cmake_minimum_required(VERSION 3.15)
project(FlexibleGameEngine)

set(CMAKE_CXX_STANDARD 20)

#find_package(SDL2)
find_package(glfw3)
find_package(OpenGL)

include_directories(FlexibleGameEngine)

add_executable(FlexibleGameEngine main.cpp GameObject.cpp GameObject.h Symbol.cpp Symbol.h Common.h ObjectClass.cpp ObjectClass.h Component.cpp Component.h ObjectInstance.cpp ObjectInstance.h GameEngine.cpp GameEngine.h SubSystem.cpp SubSystem.h Event.h LoopTask.cpp LoopTask.h ResourceComponent.cpp ResourceComponent.h ResourceSystem.cpp ResourceSystem.h GameConfig.h SpriteComponent.cpp SpriteComponent.h Renderer3dSystem.cpp Renderer3dSystem.h WindowComponent.cpp WindowComponent.h Structure.cpp Structure.h Pixel.h Renderer3dComponent.cpp Renderer3dComponent.h TransformComponent.cpp TransformComponent.h MeshFilterComponent.cpp MeshFilterComponent.h)

target_link_libraries(FlexibleGameEngine glfw pthread ${OPENGL_LIBRARIES})