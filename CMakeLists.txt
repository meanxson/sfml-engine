cmake_minimum_required(VERSION 3.20)
project(sfml_engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(sfml_engine main.cpp
        engine/math/Vector3.cpp
        engine/math/Vector3.h engine/math/Vector2.cpp
        engine/math/Vector2.h engine/math/Vector4.cpp engine/math/Vector4.h engine/Consts.h)

if (APPLE OR UNIX)
    include_directories(/usr/local/include)
else ()
    set(SFML_DIR "C:/Libraries/SFML/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
endif ()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif ()

target_link_libraries(${CMAKE_PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# OpenGL part
if (APPLE)
    set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
    set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
    include_directories(${GLEW_H} ${GLFW_H})

    set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
    link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework GLUT")
elseif (UNIX)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)

    target_link_libraries(${CMAKE_PROJECT_NAME} ${OPENGL_LIBRARIES})
    target_link_libraries(${CMAKE_PROJECT_NAME} ${GLUT_LIBRARY})
endif ()