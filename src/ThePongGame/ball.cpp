#include "iostream"
#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include <src/ThePongGame/Won Signs/won.h>
#include "ball.h"
#include "player.h"
#include "src/ThePongGame/Table/border.h"
#include "src/ThePongGame/Score/score_number.h"
#include "src/ThePongGame/Score/left_score.h"
#include "src/ThePongGame/Score/right_score.h"
#include "src/ThePongGame/Table/playground.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Ball::mesh;
unique_ptr<Texture> Ball::texture;
unique_ptr<Shader> Ball::shader;

map<std::string, int> Ball::material_map;
vector<tinyobj::material_t> Ball::material;

bool TOP_ball = false;
bool BOTTOM_ball = true;

Ball::Ball() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("white.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("ball.obj");

    ifstream mtl("ball.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->scale*=0.5;
    this->position.z = -(this->scale.z / 2) - 1;

    speed = {linearRand(-5.0f, 5.0f), linearRand(5.0f, 7.0f), 1.5f};

    if(TOP_ball){
        position.y = 4;
        speed.y *= -1;
    }

    if(BOTTOM_ball) {
        position.y = -4;
    }

    isJumping = true;
}

bool Ball::update(Scene &scene, float dt) {
    if (isJumping) {
        generateModelMatrix();

        this->startJump(position);
        isJumping = false;
        return true;
    } else {
        if (!isJumping && this->position.z <= -1.5f) {
            this->empltyKeyFrames();
        }

        speed.z += dt * 4;

        // Animate position according to time
        position += speed * dt;


        for (auto &obj : scene.objects) {
            if (obj.get() == this) continue;
            auto player = dynamic_cast<Player *>(obj.get());
            if (player) {
                if (distance(position, player->position) <= player->scale.y) {
                    float dx = (player->position.x * player->scale.x) - (position.x * scale.x);
                    float dy = (player->position.y * player->scale.y) - (position.y * scale.y);

                    float angle = atan2(dy, dx);

                    speed.x = (5.0f * -sin(angle)) * player->acceleration;
                    speed.y = (5.0f * -sin(angle));
                    if(speed.z < 0) speed.z *= -1;
                }

                if ((position.y > 8 && player->top) || (position.y < -8 && player->bottom)) {
                    player->score +=1;
                    if(player->bottom) {
                        cout<<"Player TOP +1"<<endl;
                        cout<<"Actual score:"<<player->score<<endl;
                        auto right_score = dynamic_cast<Right_score *>(obj.get());
                        right_score->updateNumber(player->score);
                        BOTTOM_ball = false;
                        TOP_ball = true;
                    }
                    if(player->top) {
                        cout<<"Player BOTTOM +1"<<endl;
                        cout<<"Actual score:"<<player->score<<endl;
                        auto left_score = dynamic_cast<Left_score *>(obj.get());
                        left_score->updateNumber(player->score);
                        BOTTOM_ball = true;
                        TOP_ball = false;
                    }
                    return false;
                }
            }

            auto border = dynamic_cast<Border *>(obj.get());
            if (border) {
                if (distance(position.x, border->position.x) <= (scale.x)) {
                    speed.x *= (-1);
                }
            }

            auto playground = dynamic_cast<Playground *>(obj.get());
            if (playground) {
                if (distance(position.z, playground->position.z) <= (scale.x)) {
                    speed.z *= (-1);
                }

                if ((distance(position.y, playground->position.y) < scale.x) &&
                    (distance(position.z, playground->position.z) < Playground::NET_HEIGHT)) {
                    speed.y *= (-1);
                }
            }
        }
    }

    // Generate modelMatrix from position, rotation and scale
    updateKeyFrame();
    generateModelMatrix();
    return true;
}


void Ball::render(Scene &scene) {
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
    shader->setUniform("Shininess", (material.data()->shininess * 128));

    shader->setUniform("Texture", *texture);
    mesh->render();
}


void Ball::startJump(glm::vec3 position) {
//    float start_Z = position.z;
    float start_Z = -1.0f;

    addKeyFrame(20, this->rotation, this->scale, {position.x, position.y, 0.0f - scale.x/2});
    addKeyFrame(20, this->rotation, this->scale, {position.x, position.y, start_Z});

    addKeyFrame(30, this->rotation, this->scale, {position.x, position.y, 0.0f - scale.x/2});
    addKeyFrame(30, this->rotation, this->scale, {position.x, position.y, start_Z * 1.5f});
}


