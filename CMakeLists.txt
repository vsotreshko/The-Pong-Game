# This CMake script is designed for CLion IDE and QTCreator projects on Windows
# It should find bundled binary dependencies automatically when using MinGW compiler
# On Linux and Mac the dependencies (glm, glew, glfw) need to be installed manually

cmake_minimum_required(VERSION 3.1)
project(ppgso CXX)

#
# CONFIGURATION
#

# Basic CMake settings
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/_install)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)


# Use add_resources function to convert .glsl to a .cpp files which will be compiled into a separate static library
include(add_resources)

#
# DEPENDENCIES
#

# Set up external dependencies for Windows users
if (MINGW)
  set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/dependencies/include/")
  set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/dependencies/lib/mingw")
elseif (MSVC)
  set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/dependencies/include/")
  set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/dependencies/lib/vc2015")
  set(USE_STRICT_COMPILE_WARNINGS OFF CACHE BOOL "" FORCE)
endif ()

# Warnings for Debug mode
option(USE_STRICT_COMPILE_WARNINGS "Use strict compilation warnings in debug mode." ON)
# These compile flags should apply for GCC and Clang compilers
set(STRICT_COMPILE_FLAGS "-Wpedantic -Wall -Wno-c++98-compat -Wextra -Wno-sign-conversion -Wno-unused-parameter")
if (USE_STRICT_COMPILE_WARNINGS)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${STRICT_COMPILE_FLAGS}")
endif ()

# Find required packages
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)

# Optional packages
find_package(OpenMP)
if(OPENMP_FOUND)
  list(APPEND CMAKE_CXX_FLAGS ${OpenMP_CXX_FLAGS})
endif()

# Set default installation destination
if (NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "../_install")
endif ()

#
# Shaders / Materials
#

set(PPGSO_SHADER_SRC
        shader/color_vert.glsl shader/color_frag.glsl
        shader/convolution_vert.glsl shader/convolution_frag.glsl
        shader/diffuse_vert.glsl shader/diffuse_frag.glsl
        shader/texture_vert.glsl shader/texture_frag.glsl
        )
add_resources(shaders ${PPGSO_SHADER_SRC})

# PPGSO library
add_library(ppgso STATIC
        ppgso/mesh.cpp
        ppgso/tiny_obj_loader.cpp
        ppgso/shader.cpp
        ppgso/image.cpp
        ppgso/image_bmp.cpp
        ppgso/image_raw.cpp
        ppgso/texture.cpp
        ppgso/window.cpp
        "src/ThePongGame/Won Signs/won.cpp" "src/ThePongGame/Won Signs/won.h")

# Make sure GLM uses radians and GLEW is a static library
target_compile_definitions(ppgso PUBLIC -DGLM_FORCE_RADIANS -DGLEW_STATIC)

# Link to GLFW, GLEW and OpenGL
target_link_libraries(ppgso PUBLIC ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
# Pass on include directories
target_include_directories(ppgso PUBLIC
        ppgso
        ${GLFW_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR})

#
# TARGETS
#

# ThePongGame
add_executable(ThePongGame
        src/ThePongGame/main.cpp
        "src/ThePongGame/Main Objects/object.cpp"
        "src/ThePongGame/Main Objects/object.h"
        "src/ThePongGame/Main Objects/camera.cpp"
        "src/ThePongGame/Main Objects/camera.h"
        "src/ThePongGame/Main Objects/scene.cpp"
        "src/ThePongGame/Main Objects/scene.h"
        src/ThePongGame/Table/playground.cpp
        src/ThePongGame/Table/playground.h
        "src/ThePongGame/Decoration Objects/ground.cpp"
        "src/ThePongGame/Decoration Objects/ground.h"
        src/ThePongGame/Table/border.cpp
        src/ThePongGame/Table/border.h
        src/ThePongGame/player.cpp
        src/ThePongGame/player.h
        "src/ThePongGame/Decoration Objects/wall.cpp"
        "src/ThePongGame/Decoration Objects/wall.h"
        src/ThePongGame/ball.cpp
        src/ThePongGame/ball.h
        src/ThePongGame/Score/score_signs.cpp
        src/ThePongGame/Score/score_signs.h
        src/ThePongGame/Score/score_number.cpp
        src/ThePongGame/Score/score_number.h
        src/ThePongGame/Score/left_score.cpp src/ThePongGame/Score/left_score.h src/ThePongGame/Score/right_score.cpp src/ThePongGame/Score/right_score.h "src/ThePongGame/Decoration Objects/start_screen.cpp" "src/ThePongGame/Decoration Objects/start_screen.h" "src/ThePongGame/Decoration Objects/background.cpp" "src/ThePongGame/Decoration Objects/background.h" "src/ThePongGame/Decoration Objects/wallBall.cpp" "src/ThePongGame/Decoration Objects/wallBall.h" "src/ThePongGame/Decoration Objects/wallBallChild.cpp" "src/ThePongGame/Decoration Objects/wallBallChild.h" src/ThePongGame/Table/smallWall.cpp src/ThePongGame/Table/smallWall.h src/ThePongGame/Table/windRight.cpp src/ThePongGame/Table/windRight.h src/ThePongGame/Table/windLeft.cpp src/ThePongGame/Table/windLeft.h)
target_link_libraries(ThePongGame ppgso shaders)
install(TARGETS ThePongGame DESTINATION .)

#
# INSTALLATION
#
file(COPY "data/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(DIRECTORY data/ DESTINATION .)
