#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "ground.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Ground::mesh;
unique_ptr<Texture> Ground::texture;
unique_ptr<Shader> Ground::shader;

map<std::string, int> Ground::material_map;
vector<tinyobj::material_t> Ground::material;

Ground::Ground() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("uvmappedcube.obj");

    ifstream mtl("uvmappedcube.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->position.x = 0;
    this->position.y = 0;
    this->position.z = 4.5;
    this->scale.x = static_cast<float>(10);
    this->scale.y = static_cast<float>(10);
    this->scale.z = static_cast<float>(0.5);
}

bool Ground::update(Scene &scene, float dt) {

    // Generate modelMatrix from position, rotation and scale
    generateModelMatrix();
    return true;
}


void Ground::render(Scene &scene) {
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


