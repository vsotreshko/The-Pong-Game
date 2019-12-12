#include "iostream"
#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "ball.h"
#include "player.h"
#include "border.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Ball::mesh;
unique_ptr<Texture> Ball::texture;
unique_ptr<Shader> Ball::shader;

map<std::string, int> Ball::material_map;
vector<tinyobj::material_t> Ball::material;

Ball::Ball() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("white.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("ball.obj");

    ifstream mtl("ball.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->scale*=0.5;
    this->position.z = -(this->scale.z / 2);

    speed = {linearRand(-10.0f, 10.0f), linearRand(5.0f, 10.0f), 0.0f};
//    speed = {0.0f,-3.0f,0.0f};

    //// Random start Y speed direction
    if(rand() % 2 == 0) {
        speed.y *= -1;
    }
}

bool Ball::update(Scene &scene, float dt) {
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

                speed.x *= -1;
//                speed.x = (15.0f * - sin(angle)) * player->acceleration;
                speed.y = (10.0f * -sin(angle));
            }

            if ((position.y > 8 && player->bottom) || (position.y < -8 && player->top)) {
                player->score +=1;
                if(player->top) {
                    cout<<"Player TOP +1"<<endl;
                }
                if(player->bottom) {
                    cout<<"Player BOTTOM +1"<<endl;
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

    shader->setUniform("Ambient", vec3(material.data()->ambient[0], material.data()->ambient[1], material.data()->ambient[2]));
    shader->setUniform("Diffuse", vec4(material.data()->diffuse[0], material.data()->diffuse[1], material.data()->diffuse[2], 1.0f));
    shader->setUniform("Specular", vec3(material.data()->specular[0], material.data()->specular[1], material.data()->specular[2]));
    shader->setUniform("Shininess", (material.data()->shininess * 128));

    shader->setUniform("Texture", *texture);
    mesh->render();
}


