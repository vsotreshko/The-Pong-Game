#include "iostream"
#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include <src/ThePongGame/Won Signs/won.h>
#include <src/ThePongGame/Table/smallWall.h>
#include <src/ThePongGame/Table/windLeft.h>
#include <src/ThePongGame/Table/windRight.h>
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
    this->position.z = -(this->scale.z / 2) - 2;

    speed = {linearRand(-5.0f, 5.0f), linearRand(5.0f, 7.0f), 0.5f};

    if(TOP_ball){
        position.y = 4;
        speed.y *= -1;
    }

    if(BOTTOM_ball) {
        position.y = -4;
    }
}

bool Ball::update(Scene &scene, float dt) {
    vec3 gravitation = {0.0f, 0.0f, 0.05f};
    speed += gravitation;

    // Animate position according to time
    position += speed * dt;


    for (auto &obj : scene.objects) {
        if (obj.get() == this) continue;

        auto windLeft = dynamic_cast<WindLeft *>(obj.get());
        if(windLeft) {
            this->speed += windLeft->power;
        }

        auto windRight = dynamic_cast<WindRight *>(obj.get());
        if(windRight) {
            this->speed += windRight->power;
        }

        auto player = dynamic_cast<Player *>(obj.get());
        if (player) {
            if (distance(position.x, player->position.x) <= player->scale.x + (scale.x / 2) &&
                distance(position.y, player->position.y) <= 0.1f + (scale.x / 2) &&
                distance(position.z, player->position.z) <= 0.5f + (scale.x / 2)){

                float dx = (player->position.x * player->scale.x) - (position.x * scale.x);
                float dy = (player->position.y * player->scale.y) - (position.y * scale.y);

                float angle = atan2(dy, dx);

                speed.x = (3.0f * -sin(angle)) * player->acceleration;
                speed.y = (3.0f * -sin(angle));
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
            if (distance(position.x, border->position.x) <= scale.x &&
                distance(position.z, border->position.z) <= scale.z/2 + border->scale.z) {
                speed.x *= (-1);
                speed.z *= (-1);
            }

        }

        auto playground = dynamic_cast<Playground *>(obj.get());
        if (playground) {
            if (distance(position.z, playground->position.z) <= (scale.z / 2)) {
                speed.z *= (-1);
            }

            if ((distance(position.y, playground->position.y) <= (scale.x / 2)) &&
                (distance(position.z, playground->position.z) <= Playground::NET_HEIGHT +  (scale.x / 2))) {
                speed.y *= (-1);
            }
        }

        auto smallWall = dynamic_cast<SmallWall *>(obj.get());
        if (smallWall) {
            if (distance(position.y, smallWall->position.y) <= (scale.x / 2) &&
                distance(position.x, smallWall->position.x) <= smallWall->scale.x){
                speed.y *= (-1);
            }
        }
    }

    // Generate modelMatrix from position, rotation and scale
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

