#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "windLeft.h"
#include "windRight.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> WindRight::mesh;
unique_ptr<Texture> WindRight::texture;
unique_ptr<Shader> WindRight::shader;

map<std::string, int> WindRight::material_map;
vector<tinyobj::material_t> WindRight::material;

WindRight::WindRight() {
        // Initialize static resources if needed
        if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
        if (!texture) texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
        if (!mesh) mesh = make_unique<Mesh>("windRight.obj");

        ifstream mtl("windRight.mtl", std::ifstream::binary);
        tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->position.x = -5;
    this->position.y = 9;
    this->position.z = -1;

    power = {-0.05f,0.0f,0.0f};

}

bool WindRight::update(Scene &scene, float dt) {
    age += dt;

    if (age >= 5.0f)
        return false;

    // Generate modelMatrix from position, rotation and scale
    generateModelMatrix();

    return true;
}


void WindRight::render(Scene &scene) {
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


