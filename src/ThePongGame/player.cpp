#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include <src/ThePongGame/Won Signs/won.h>
#include "player.h"
#include "src/ThePongGame/Main Objects/scene.h"

using namespace std;
using namespace glm;
using namespace ppgso;

const float SPEED = 0.2;

// Static resources
unique_ptr<Mesh> Player::mesh;
unique_ptr<Texture> Player::texture;
unique_ptr<Shader> Player::shader;

map<std::string, int> Player::material_map;
vector<tinyobj::material_t> Player::material;

Player::Player(int position, int moves_) {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("player_pong.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("player_pong.obj");

    ifstream mtl("player_pong.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    bottom = false;
    top = false;

    moves = moves_;

    if (position == 0) {
        this->position.y = -7;
        top = true;
    } else if (position == 1) {
        this->position.y = 7;
        bottom = true;
    }
    turned = false;

    score = 0;
}

bool Player::update(Scene &scene, float dt) {
    if (moves == 1) {
        //Updated rendered player lifes
        for (auto &obj : this->score_signes) {
            obj->update(scene, dt);
        }

        //// MOVE LEFT
        if (scene.keyboard[GLFW_KEY_LEFT]) {
            if (position.x >= 2 && !turned) {
                rotation.z = -PI / 4.0f;
                turned = true;
            } else if (position.x <= 1.5 && turned) {
                rotation.z = 0;
                turned = false;
            }
            if (position.x <= (5 - scale.x)) {
            this->acceleration += dt * 1.2;
            position.x += 10 * dt * this->acceleration;
                position.x += SPEED;
            }
        } else
            //// MOVE RIGHT
            if (scene.keyboard[GLFW_KEY_RIGHT]) {
                if (position.x <= -2 && !turned) {
                    rotation.z = PI / 4.0f;
                    turned = true;
                } else if (position.x >= -1.5 && turned) {
                    rotation.z = 0;
                    turned = false;
                }

                if (position.x >= (-5 + scale.x)) {
                this->acceleration += dt * 1.2;
                position.x -= 10 * dt * this->acceleration;
                    position.x -= SPEED;
                } else {
                     this->acceleration = 1.2;
                }
            } else
                //// MOVE UP
                if (scene.keyboard[GLFW_KEY_UP]){
                    if (position.z >= -3) position.z -= SPEED;
                } else
                    //// MOVE DOWN
                    if (scene.keyboard[GLFW_KEY_DOWN]) {
                        if (position.z <= 0) position.z += SPEED;
                    }

    } else {
        //Updated rendered player lifes
        for (auto &obj : this->score_signes) {
            obj->update(scene, dt);
        }

        //// MOVE LEFT
        if (scene.keyboard[GLFW_KEY_A]) {
            if (position.x >= 2 && !turned) {
                rotation.z = -PI / 4.0f;
                turned = true;
            } else if (position.x <= 1.5 && turned) {
                rotation.z = 0;
                turned = false;
            }

            if (position.x <= (5 - scale.x)) {
                this->acceleration += dt * 1.2;
                position.x += 10 * dt * this->acceleration;
                position.x += SPEED;
            }

        } else
            //// MOVE RIGHT
            if (scene.keyboard[GLFW_KEY_D]) {
                if (position.x <= -2 && !turned) {
                    rotation.z = PI / 4.0f;
                    turned = true;
                } else if (position.x >= -1.5 && turned) {
                    rotation.z = 0;
                    turned = false;
                }

                if (position.x >= (-5 + scale.x)) {
                    this->acceleration += dt * 1.2;
                    position.x -= 10 * dt * this->acceleration;
                    position.x -= SPEED;
                } else {
                     this->acceleration = 1.2;
                }
            } else
                //// MOVE UP
                if (scene.keyboard[GLFW_KEY_W]){
                    if (position.z >= -3) position.z -= SPEED;
                } else
                    //// MOVE DOWN
                if (scene.keyboard[GLFW_KEY_S]) {
                    if (position.z <= 0) position.z += SPEED;
                }
    }

    if (score >= 5) {
        if (top) this->endGame(scene, 0);
        if (bottom) this->endGame(scene, 1);
    }

    generateModelMatrix();
    return true;
}


void Player::render(Scene &scene) {
    //Render player score
    for (auto& obj : this->score_signes) {
        obj->render(scene);
    }

    shader->use();
    shader->setUniform("LightDirection", scene.lightDirection);
    shader->setUniform("LightColor", scene.lightColor);
    shader->setUniform("LightDirection2", scene.lightDirection2);
    shader->setUniform("LightColor2", scene.lightColor2);
    shader->setUniform("AmbientLightColor", scene.ambientLightColor);
    shader->setUniform("CameraPosition", scene.camera->position);
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);

    shader->setUniform("Ambient", vec4(material.data()->ambient[0], material.data()->ambient[0], material.data()->ambient[0], material.data()->ambient[1]));
    shader->setUniform("Diffuse", vec4(material.data()->diffuse[1], material.data()->diffuse[1], material.data()->diffuse[1], material.data()->diffuse[1]));
    shader->setUniform("Specular", vec4(material.data()->specular[1], material.data()->specular[1], material.data()->specular[1], material.data()->specular[1]));
    shader->setUniform("Shininess", (material.data()->shininess * 50));

    shader->setUniform("Texture", *texture);
    mesh->render();
}

void Player::endGame(Scene &scene, int player) {
//    scene.camera->cameraUP();
//    auto won = make_unique<Won>(player);
//    scene.objects.push_back(move(won));
}


