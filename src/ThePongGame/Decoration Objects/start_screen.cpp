#include <glm/gtc/random.hpp>
#include "start_screen.h"
#include <src/ThePongGame/Main Objects/scene.h>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Start_screen::mesh;
unique_ptr<Shader> Start_screen::shader;

map<std::string, int> Start_screen::material_map;
vector<tinyobj::material_t> Start_screen::material;

Start_screen::Start_screen() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!mesh) mesh = make_unique<Mesh>("start_screen.obj");

    //Load mtl files
    ifstream mtl("start_screen.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);
}

bool Start_screen::update(Scene &scene, float dt) {

    rotation.x = PI / 2;

    generateModelMatrix();
    return true;
}

void Start_screen::render(Scene &scene) {
    vec3 ambient = vec3(material.data()->ambient[0], material.data()->ambient[1], material.data()->ambient[2]);
    vec4 diffuse = vec4(material.data()->diffuse[0], material.data()->diffuse[1], material.data()->diffuse[2], 1.0f);
    vec3 specular = vec3(material.data()->specular[0], material.data()->specular[1], material.data()->specular[2]);
    float shininess = material.data()->shininess * 128;

    shader->use();
    shader->setUniform("LightDirection", scene.lightDirection);
    shader->setUniform("LightColor", scene.lightColor);
    shader->setUniform("AmbientLightColor", scene.ambientLightColor);
    shader->setUniform("CameraPosition", scene.camera->position);
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);

    shader->setUniform("MaterialAmbient", {ambient.x, ambient.y, ambient.z});
    shader->setUniform("MaterialDiffuse", {diffuse.x, diffuse.y, diffuse.z, 1.0f});
    shader->setUniform("MaterialSpecular", {specular.x, specular.y, specular.z});
    shader->setUniform("MaterialShininess", shininess);

    mesh->render();
}
