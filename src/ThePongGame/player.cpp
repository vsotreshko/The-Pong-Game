#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "player.h"
#include "scene.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Player::mesh;
unique_ptr<Texture> Player::texture;
unique_ptr<Shader> Player::shader;

map<std::string, int> Player::material_map;
vector<tinyobj::material_t> Player::material;

Player::Player(int position) {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("player_pong.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("player_pong.obj");

    ifstream mtl("player_pong.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    bottom = false;
    top = false;

    if (position == 0) {
        this->position.y = -7;
        top = true;
    } else if (position == 1) {
        this->position.y = 7;
        bottom = true;
    }
    turned = false;

    score = 0;
    auto scoresign = make_unique<ScoreNumber>();
    if (this->position.y > 0){
        scoresign->position.x = this->position.y - 5;
    }
    if (this->position.y < 0){
        scoresign->position.x = this->position.y + 5;
    }
}

bool Player::update(Scene &scene, float dt) {
    for (auto& obj : this->score_sign) {
        obj->update(scene, dt);
    }

    // Player moves (Keyboard)
    if(scene.keyboard[GLFW_KEY_LEFT]) {
        if (position.x >= 2 && !turned) {
            rotation.z = -PI / 4.0f;
            turned = true;
        } else if (position.x <= 1.5 && turned){
            rotation.z = 0;
            turned = false;
        }

        if (position.x <= (5 - scale.x)) {
//            this->acceleration += dt * 1.2;
//            position.x += 10 * dt * this->acceleration;
            position.x += 0.3;
        }

    } else
        if(scene.keyboard[GLFW_KEY_RIGHT]) {
            if (position.x <= -2 && !turned){
                rotation.z = PI/4.0f;
                turned = true;
            } else if (position.x >= -1.5 && turned){
                rotation.z = 0;
                turned = false;
            }

            if (position.x >= (-5 + scale.x)) {
//                this->acceleration += dt * 1.2;
//                position.x -= 10 * dt * this->acceleration;
                position.x -= 0.3;
            } else {
                // this->acceleration = 1.2;
            }
        }

    generateModelMatrix();
    return true;
}


void Player::render(Scene &scene) {
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

    shader->setUniform("Ambient", vec3(material.data()->ambient[0], material.data()->ambient[1], material.data()->ambient[2]));
    shader->setUniform("Diffuse", vec4(material.data()->diffuse[0], material.data()->diffuse[1], material.data()->diffuse[2], 1.0f));
    shader->setUniform("Specular", vec3(material.data()->specular[0], material.data()->specular[1], material.data()->specular[2]));
    shader->setUniform("Shininess", (material.data()->shininess * 128));

    shader->setUniform("Texture", *texture);
    mesh->render();
}


