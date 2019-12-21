//
// Created by vsotreshko on 8. 12. 2019.
//

/*!TODO
 * 1) Отображение счета на сцене при создании Player (0  0)
 * 2) Изменение чисел счета при изменении счета
 * 3) Добавить PowerUps
 * 4) Прыжки мяча (координата Z)
 */

#include <iostream>
#include <memory>
#include <list>

#include <ppgso/ppgso.h>
#include <src/ThePongGame/Decoration Objects/background.h>
#include <cmake-build-debug/shaders/texture_vert_glsl.h>
#include <cmake-build-debug/shaders/texture_frag_glsl.h>

#include "src/ThePongGame/Main Objects/camera.h"
#include "src/ThePongGame/Main Objects/scene.h"
#include "src/ThePongGame/Table/playground.h"
#include "src/ThePongGame/Decoration Objects/ground.h"
#include "src/ThePongGame/Table/border.h"
#include "player.h"
#include "src/ThePongGame/Decoration Objects/wall.h"
#include "ball.h"
#include "src/ThePongGame/Score/score_signs.h"
#include "src/ThePongGame/Score/left_score.h"
#include "src/ThePongGame/Score/right_score.h"
#include "src/ThePongGame/Decoration Objects/start_screen.h"
#include <glm/gtc/random.hpp>
#include <src/ThePongGame/Decoration Objects/wallBall.h>
#include <src/ThePongGame/Table/smallWall.h>


using namespace std;
using namespace glm;
using namespace ppgso;

const unsigned int SIZE = 1000;

class SceneWindow : public Window {
private:
    Scene scene;
    Shader program = {texture_vert_glsl, texture_frag_glsl};

    void initScene() {
        scene.objects.clear();

        auto camera = make_unique<Camera>(60.0f, 1.0f, 0.1f, 100.0f);
        camera->position.z = -17.82f;
        camera->position.y = -0.060f;
        camera->position.x = 77.220f;

        camera->back.y = -2.71988f;
        camera->back.z = -37.0402f;

        camera->up.y = 1.0f;
        scene.camera = move(camera);

        auto background = make_unique<Background>();
        background->position.x = 0.0f;
        background->position.y = 0.0f;
        background->position.z = 0.0f;
        scene.objects.push_back(move(background));

        auto start_screen = make_unique<Start_screen>();
        start_screen->position.x = 76.99f;
        start_screen->position.y = 1.29f;
        start_screen->position.z = -5.0f;
        scene.objects.push_back(move(start_screen));
    }

public:
    bool animate = true;

    SceneWindow() : Window{"The Pong Game", SIZE, SIZE} {
        //hideCursor();
        glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

        // Initialize OpenGL state
        // Enable Z-buffer
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        // Enable polygon culling
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);

        initScene();
    }

    void onKey(int key, int scanCode, int action, int mods) override {
        scene.keyboard[key] = action;

        //// Add ball to the Game
        if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) {
            initGameScene();
        }

        //// Add ball to the Game
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
            auto ball = make_unique<Ball>();
            scene.objects.push_back(move(ball));
        }

        //// Pause Game
        if (key == GLFW_KEY_P && action == GLFW_PRESS) {
            animate = !animate;
        }

        /*
        * Camera
        */
        //// Rotate camera
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_3]){
            scene.camera->flag = !scene.camera->flag;
        }

        //// Change camera position on UP
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_2]){
            scene.camera->cameraUP();
        }

        //// Change camera position on DEFAULT
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_1]){
            scene.camera->cameraDEFAULT();
        }

        //// Move camera POSITION 0X
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->position.x += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->position.x -= 0.1;

        //// Move camera POSITION 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->position.y += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->position.y -= 0.1;

        //// Move camera POSITION 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->position.z += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_P] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->position.z -= 0.1;

        //// Move camera BACK 0X
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->back.x += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->back.x -= 0.1;

        //// Move camera BACK 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->back.y += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->back.y -= 0.1;

        //// Move camera BACK 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->back.z += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_B] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->back.z -= 0.1;

        //// Move camera UP 0X
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->up.x += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->up.x -= 0.1;

        //// Move camera UP 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->up.y += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->up.y -= 0.1;

        //// Move camera UP 0Y
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_EQUAL]) scene.camera->up.z += 0.1;
        if(scene.keyboard[GLFW_KEY_C] && scene.keyboard[GLFW_KEY_U] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_MINUS]) scene.camera->up.z -= 0.1;

        /*!
         * Light
         */
        //// Move MAIN Light DIRECTION 0X
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection.x += 0.05;
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection.x -= 0.05;

        //// Move MAIN Light POSITION 0Y
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection.y += 0.05;
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection.y -= 0.05;

        //// Move MAIN Light POSITION 0Y
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection.z += 0.05;
        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection.z -= 0.05;

        //// Move SECOND Light DIRECTION 0X
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection2.x += 0.1;
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_X] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection2.x -= 0.1;

        //// Move SECOND Light POSITION 0Y
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection2.y += 0.1;
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_Y] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection2.y -= 0.1;

        //// Move SECOND Light POSITION 0Y
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_EQUAL]) scene.lightDirection2.z += 0.1;
        if(scene.keyboard[GLFW_KEY_J] && scene.keyboard[GLFW_KEY_Z] && scene.keyboard[GLFW_KEY_MINUS]) scene.lightDirection2.z -= 0.1;

        if(scene.keyboard[GLFW_KEY_L] && scene.keyboard[GLFW_KEY_P]){
            cout << "X= " << scene.lightDirection.x << endl;
            cout << "Y= " << scene.lightDirection.y << endl;
            cout << "Z= " << scene.lightDirection.z << endl;
        }
    }

    void onIdle() override {
        // Track time
        static auto time = (float) glfwGetTime();


        // Compute time delta
        float dt = animate ? (float) glfwGetTime() - time : 0;

        time = (float) glfwGetTime();

        // Set gray background
        glClearColor(0.5f, 0.5f, 0.5f, 0);
        // Clear depth and color buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
        glEnable ( GL_LIGHTING ) ;
        glEnable ( GL_LIGHT0 ) ;

        // Update and render all objects
        scene.update(dt);
        scene.render();
    }

    void initGameScene () {
        scene.objects.clear();
        animate = true;

        //// Create a camera
        auto camera = make_unique<Camera>(80.0f, 1.0f, 0.1f, 100.0f);
        scene.camera = move(camera);

        //// Add SCORE to the scene
        auto score_signs = make_unique<ScoreSigns>();
        scene.objects.push_back(move(score_signs));

        auto score_left = make_unique<Left_score>();
        scene.objects.push_back(move(score_left));

        auto score_right = make_unique<Right_score>();
        scene.objects.push_back(move(score_right));

        //// Add wall to the scene
        auto wall = make_unique<Wall>();
        scene.objects.push_back(move(wall));

        //// Add BOTTOM player to the scene (position: 0 - TOP, 1 - BOTTOM)
        auto player_top = make_unique<Player>(0, 1);
        scene.objects.push_back(move(player_top));

        //// Add TOP player to the scene
        auto player_bottom = make_unique<Player>(1, -1);
        scene.objects.push_back(move(player_bottom));

        //// Add playground to the scene
        auto playground = make_unique<Playground>();
        scene.objects.push_back(move(playground));

        //// Add ground to the scene
        auto ground = make_unique<Ground>();
        scene.objects.push_back(move(ground));

        //// Add LEFT border to the scene
        auto border_left = make_unique<Border>(5.75, 0);
        scene.objects.push_back(move(border_left));

        //// Add LEFT border to the scene
        auto border_right = make_unique<Border>(-5.75, 0);
        scene.objects.push_back(move(border_right));

        auto wallBall = make_unique<WallBall>();
        scene.objects.push_back(move(wallBall));
    }
};

int main() {
    // Initialize our window
    SceneWindow window;

    // Main execution loop
    while (window.pollEvents()) {}

    cout<<"Succesfully Done!"<<endl;
    return EXIT_SUCCESS;
}