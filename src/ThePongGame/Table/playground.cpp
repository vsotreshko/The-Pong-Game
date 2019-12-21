#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "playground.h"
#include "smallWall.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Playground::mesh;
unique_ptr<Texture> Playground::texture;
unique_ptr<Shader> Playground::shader;

map<std::string, int> Playground::material_map;
vector<tinyobj::material_t> Playground::material;

Playground::Playground() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("pong_table.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("pong_table.obj");

    ifstream mtl("pong_table.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);
}

bool Playground::update(Scene &scene, float dt) {
    time += dt;

    if(time > 10.0f) {
        time = 0.0f;

        float randomPosition = linearRand(-7.0f, 7.0f);
        auto smallWall = make_unique<SmallWall>(randomPosition);
        scene.objects.push_back(move(smallWall));
    }

    // Generate modelMatrix from position, rotation and scale
    generateModelMatrix();
    return true;
}


void Playground::render(Scene &scene) {

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


