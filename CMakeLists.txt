cmake_minimum_required(VERSION 3.13)
project(WindowClickText2rd)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(WindowClickText2rd main.cpp paper_wc.h paper_wc.cpp draw_wc.h draw_wc.cpp button_wc.h button_wc.cpp painter_wc.h painter_wc.cpp tool_wc.h tool_wc.cpp picElem_wc.h picElem_wc.cpp evalElem_wc.h)
target_link_libraries(WindowClickText2rd ${GLUT_LIBRARY} ${OPENGL_LIBRARY})