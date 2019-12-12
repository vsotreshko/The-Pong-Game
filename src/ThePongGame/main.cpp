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
#include <map>
#include <list>

#include <ppgso/ppgso.h>

#include "camera.h"
#include "scene.h"
#include "playground.h"
#include "ground.h"
#include "border.h"
#include "player.h"
#include "wall.h"
#include "ball.h"
#include "score_signs.h"

using namespace std;
using namespace glm;
using namespace ppgso;

const unsigned int SIZE = 1000;

class SceneWindow : public Window {
private:
    Scene scene;
    bool animate = true;

    void initScene() {
        scene.objects.clear();

        //// Create a camera
        auto camera = make_unique<Camera>(80.0f, 1.0f, 0.1f, 100.0f);
        camera->position.x = 0;
        camera->position.y = -12;
        camera->position.z = -5;

        camera->up.x = 0;
        camera->up.y = 1;
        camera->up.z = 0;

        camera->back.x = 0;
        camera->back.y = -2;
        camera->back.z = -1.5;
        scene.camera = move(camera);

        //// Add playground to the scene
        auto playground = make_unique<Playground>();
        scene.objects.push_back(move(playground));

        //// Add ground to the scene
        auto ground = make_unique<Ground>();
        scene.objects.push_back(move(ground));

        //// Add wall to the scene
        auto wall = make_unique<Wall>();
        scene.objects.push_back(move(wall));

        //// Add LEFT border to the scene
        auto border_left = make_unique<Border>(5.75, 0);
        scene.objects.push_back(move(border_left));

        //// Add LEFT border to the scene
        auto border_right = make_unique<Border>(-5.75, 0);
        scene.objects.push_back(move(border_right));

        //// Add TOP player to the scene (position: 0 - TOP, 1 - BOTTOM)
        auto player_top = make_unique<Player>(0);
        scene.objects.push_back(move(player_top));

        //// Add BOTTOM player to the scene
        auto player_bottom = make_unique<Player>(1);
        scene.objects.push_back(move(player_bottom));

        //// Add TOP player SCORE to the scene
        auto score_signs = make_unique<ScoreSigns>();
        scene.objects.push_back(move(score_signs));
    }

public:
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

    /*!
     * Handles pressed key when the window is focused
     * @param key Key code of the key being pressed/released
     * @param scanCode Scan code of the key being pressed/released
     * @param action Action indicating the key state change
     * @param mods Additional modifiers to consider
     */
    void onKey(int key, int scanCode, int action, int mods) override {
        scene.keyboard[key] = action;

        // Reset
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
            auto ball = make_unique<Ball>();
            scene.objects.push_back(move(ball));
        }

        // Pause
        if (key == GLFW_KEY_P && action == GLFW_PRESS) {
            animate = !animate;
        }
    }

    /*!
     * Handle cursor position changes
     * @param cursorX Mouse horizontal position in window coordinates
     * @param cursorY Mouse vertical position in window coordinates
     */
    void onCursorPos(double cursorX, double cursorY) override {
        scene.cursor.x = cursorX;
        scene.cursor.y = cursorY;
    }

    /*!
     * Handle cursor buttons
     * @param button Mouse button being manipulated
     * @param action Mouse bu
     * @param mods
     */
    void onMouseButton(int button, int action, int mods) override {
        if(button == GLFW_MOUSE_BUTTON_LEFT) {
            scene.cursor.left = action == GLFW_PRESS;

            if (scene.cursor.left) {
                // Convert pixel coordinates to Screen coordinates
                float u = (scene.cursor.x / width - 0.5f) * 2.0f;
                float v = - (scene.cursor.y / height - 0.5f) * 2.0f;

                // Get mouse pick vector in world coordinates
                auto direction = scene.camera->cast(u, v);
                auto position = scene.camera->position;

                // Get all objects in scene intersected by ray
                auto picked = scene.intersect(position, direction);

                // Go through all objects that have been picked
                for (auto &obj: picked) {
                    // Pass on the click event
                    obj->onClick(scene);
                }
            }
        }
        if(button == GLFW_MOUSE_BUTTON_RIGHT) {
            scene.cursor.right = action == GLFW_PRESS;
        }
    }

    /*!
     * Window update implementation that will be called automatically from pollEvents
     */
    void onIdle() override {
        // Track time
        static auto time = (float) glfwGetTime();

        // Compute time delta
        float dt = animate ? (float) glfwGetTime() - time : 0;

        time = (float) glfwGetTime();

        // Set gray background
        glClearColor(.5f, .5f, .5f, 0);
        // Clear depth and color buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update and render all objects
        scene.update(dt);
        scene.render();
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