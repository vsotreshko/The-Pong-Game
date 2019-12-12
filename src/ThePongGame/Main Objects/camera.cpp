#include <glm/glm.hpp>

#include "camera.h"

using namespace std;
using namespace glm;
using namespace ppgso;

Camera::Camera(float fow, float ratio, float near, float far) {
  float fowInRad = (PI/180.0f) * fow;
  projectionMatrix = perspective(fowInRad, ratio, near, far);

    up = {0,1,0};
    back = {0,-2,-1.5};
    position = {0, -12, -5};
}

void Camera::update() {
  viewMatrix = lookAt(position, position-back, up);
}

glm::vec3 Camera::cast(float u, float v) {
  // Create point in Screen coordinates
  glm::vec4 screenPosition{u,v,0.0f,1.0f};

  // Use inverse matrices to get the point in world coordinates
  auto invProjection = glm::inverse(projectionMatrix);
  auto invView = glm::inverse(viewMatrix);

  // Compute position on the camera plane
  auto planePosition = invView * invProjection * screenPosition;
  planePosition /= planePosition.w;

  // Create direction vector
  auto direction = glm::normalize(planePosition - vec4{position,1.0f});
  return vec3{direction};
}

void  Camera::cameraDEFAULT() {
    up = {0,1,0};
    back = {0,-2,-1.5};
    position = {0, -12, -5};
}

void  Camera::cameraUP() {
    up = {0,1,0};
    back = {0,-2.71988,-37.0402};
    position = {0, 0, -15};
}
