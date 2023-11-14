cmake_minimum_required(VERSION 3.26)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp)


add_executable(Stack_static chapter03/Stack/Static/Stack_static.cpp)
add_executable(Stack_static_share chapter03/Stack/Static/Stack_static_share.cpp)
add_executable(Stack_dynamic chapter03/Stack/Dynamic/Stack_dynamic_withoutHead.cpp)
add_executable(test chapter03/Stack/test.cpp)
add_executable(Queue_static chapter03/Queue/static/Queue_static_Sacrifice.cpp)
add_executable(Queue_static_tag chapter03/Queue/static/Queue_static_tag.cpp)
add_executable(Link_Single_withoutHead chapter02/Dynamic/Link_Single_withoutHead.cpp)
add_executable(Link_Single_head chapter02/Dynamic/Link_Single_head.cpp)
add_executable(Queue_dynamic_head chapter03/Queue/dynamic/Queue_dynamic_head.cpp)
add_executable(Queue_dynamic_withoutHead chapter03/Queue/dynamic/Queue_dynamic_withoutHead.cpp)
add_executable(Queue_dynamic_Double chapter03/Queue/dynamic/Queue_dynamic_Double.cpp)
add_executable(Queue_train chapter03/Queue/experiment/Queue_train.cpp)
add_executable(circleQueue_static chapter03/Queue/experiment/circleQueue_static.cpp)
add_executable(Queue_static_communcate chapter03/Queue/experiment/Queue_static_communcate.cpp)