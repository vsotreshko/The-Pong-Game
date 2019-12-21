#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "smallWall.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> SmallWall::mesh;
unique_ptr<Texture> SmallWall::texture;
unique_ptr<Shader> SmallWall::shader;

map<std::string, int> SmallWall::material_map;
vector<tinyobj::material_t> SmallWall::material;

SmallWall::SmallWall(float position) {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("white.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("uvmappedcube.obj");

    ifstream mtl("uvmappedcube.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->scale.x = static_cast<float>(0.5);
    this->scale.y = static_cast<float>(0.1);
    this->scale.z = static_cast<float>(0.5);

    this->position.z = -1.5;

    addKeyFrame(300, this->rotation, this->scale, {position, this->position.y, this->position.z});
    addKeyFrame(300, this->rotation, this->scale, {-position, this->position.y, this->position.z});
}

bool SmallWall::update(Scene &scene, float dt) {
    age += dt;

    float rand = linearRand(8.0f, 15.0f);
    if (age >= rand)
        return false;

    // Generate modelMatrix from position, rotation and scale
    updateKeyFrame();
    generateModelMatrix();
    return true;
}


void SmallWall::render(Scene &scene) {
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


