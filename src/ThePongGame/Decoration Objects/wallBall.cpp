//
// Created by vsotreshko on 21. 12. 2019.
//

#include "wallBall.h"
#include <cmath>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> WallBall::mesh;
unique_ptr<Texture> WallBall::texture;
unique_ptr<Shader> WallBall::shader;

map<std::string, int> WallBall::material_map;
vector<tinyobj::material_t> WallBall::material;

WallBall::WallBall() {

    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("white.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("ball.obj");

    //Load mtl files
    ifstream mtl("ball.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->spawned = false;

    this->age = 0.0f;
    this->duration = 5.0f;
    this->position = {0,4,-5};

    auto childBall1 = make_unique<WallBallChild>();
    auto childBall2 = make_unique<WallBallChild>();
    auto childBall3 = make_unique<WallBallChild>();
    auto childBall4 = make_unique<WallBallChild>();
    auto childBall5 = make_unique<WallBallChild>();
    auto childBall6 = make_unique<WallBallChild>();

    childBall1->position = {0, 0, 1};
    this->rotatingBalls.push_back(move(childBall1));

    childBall2->position = {0, 0, -1};
    this->rotatingBalls.push_back(move(childBall2));

    childBall3->position = {0, 1, 0};
    this->rotatingBalls.push_back(move(childBall3));

    childBall4->position = {0, -1, 0};
    this->rotatingBalls.push_back(move(childBall4));

    childBall5->position = {1, 0, 0};
    this->rotatingBalls.push_back(move(childBall5));

    childBall6->position = {-1, 0, 0};
    this->rotatingBalls.push_back(move(childBall6));


    addKeyFrame(400, {0, 0, rotation.z}, this->scale, {3, this->position.y, this->position.z});
    addKeyFrame(400, {PI * 2, PI * 2, rotation.z}, this->scale, {-3, this->position.y, this->position.z});
}

bool WallBall::update(Scene &scene, float dt) {

    age += dt;

//    rotation += rotMomentum * dt;

    if(!spawned) {
        this->spawned = true;

        for (auto& obj : this->rotatingBalls) {
            scene.objects.push_back(move(obj));
        }
    }

    updateKeyFrame();
    generateModelMatrix();
    return true;
}

void WallBall::render(Scene &scene) {
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

