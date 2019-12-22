#ifndef _PPGSO_SCENE_H
#define _PPGSO_SCENE_H

#include <memory>
#include <map>
#include <list>

#include "object.h"
#include "camera.h"


class Scene {
  public:
    void update(float time);

    void render();

    std::vector<Object*> intersect(const glm::vec3 &position, const glm::vec3 &direction);

    // Camera object
    std::unique_ptr<Camera> camera;

    // All objects to be rendered in scene
    std::list< std::unique_ptr<Object> > objects;

    // Keyboard state
    std::map< int, int > keyboard;

    // Lights, in this case using only simple directional diffuse lighting
    glm::vec3 lightDirection = normalize(glm::vec3{-1.5f, -0.82f, -0.57f});
    glm::vec3 lightDirection2 = normalize(glm::vec3{1.5f, -0.82f, -0.57f});

    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 lightColor2 = glm::vec3(1.0f, 1.0f, 1.0f);

    glm::vec3 ambientLightColor = glm::vec3(0.05f, 0.05f, 0.05f);
};

#endif // _PPGSO_SCENE_H
