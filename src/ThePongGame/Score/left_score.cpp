#include <glm/gtc/random.hpp>

#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "left_score.h"

using namespace std;
using namespace glm;
using namespace ppgso;

// Static resources
unique_ptr<Mesh> Left_score::mesh;
unique_ptr<Texture> Left_score::texture;
unique_ptr<Shader> Left_score::shader;

map<std::string, int> Left_score::material_map;
vector<tinyobj::material_t> Left_score::material;

Left_score::Left_score() {
    // Initialize static resources if needed
    if (!shader) shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
    if (!mesh) mesh = make_unique<Mesh>("score_0.obj");

    ifstream mtl("score_0.mtl", std::ifstream::binary);
    tinyobj::LoadMtl(this->material_map, this->material, mtl);

    this->position.x = 1.5;
    this->position.y = 9;
    this->position.z = -2;
}

bool Left_score::update(Scene &scene, float dt) {

    // Generate modelMatrix from position, rotation and scale
    generateModelMatrix();
    return true;
}


void Left_score::render(Scene &scene) {
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

    shader->setUniform("Ambient", vec4(material.data()->ambient[0], material.data()->ambient[1], material.data()->ambient[2], 1.0f));
    shader->setUniform("Diffuse", vec4(material.data()->diffuse[0], material.data()->diffuse[1], material.data()->diffuse[2], 1.0f));
    shader->setUniform("Specular", vec4(material.data()->specular[0], material.data()->specular[1], material.data()->specular[2], 1.0f));
    shader->setUniform("Shininess", (material.data()->shininess * 128));

    shader->setUniform("Texture", *texture);
    mesh->render();
}


void Left_score::updateNumber(int number) {
    switch (number)
    {
        case 1:
            this->shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
            this->texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
            this->mesh = make_unique<Mesh>("score_1.obj");
            break;

        case 2:
            this->shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
            this->texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
            this->mesh = make_unique<Mesh>("score_2.obj");
            break;

        case 3:
            this->shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
            this->texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
            this->mesh = make_unique<Mesh>("score_3.obj");
            break;

        case 4:
            this->shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
            this->texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
            this->mesh = make_unique<Mesh>("score_4.obj");
            break;

        case 5:
            this->shader = make_unique<Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
            this->texture = make_unique<Texture>(image::loadBMP("wood.bmp"));
            this->mesh = make_unique<Mesh>("score_5.obj");
            break;

        default: // code to be executed if n doesn't match any cases
            break;
    }
}


