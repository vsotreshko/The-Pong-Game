#pragma once
#include <memory>
#include <list>
#include <map>
#include <vector>

#include <glm/glm.hpp>

class Scene;

struct t_keyframe {
    glm::vec3 keyframePosition = {0, 0, 0};
    glm::vec3 keyframeRotation = {0, 0, 0};
    glm::vec3 keyframeScale = {1, 1, 1};
    float duration = 100;
};

class Object {

protected:
    float keyframeDuration = 0;
    int processedKeyframes = 0;

    std::vector<t_keyframe> keyframeAnimation;

public:
    Object() = default;
    Object(const Object&) = default;
    Object(Object&&) = default;
    virtual ~Object() {};

    virtual bool update(Scene &scene, float dt) = 0;
    virtual void render(Scene &scene) = 0;
    virtual void onClick(Scene &scene) {};

    void addKeyFrame(int duration, glm::vec3 keyFrameRotation, glm::vec3 keyFrameScale, glm::vec3 keyFramePosition);

    // Object properties
    glm::vec3 position{0,0,0};
    glm::vec3 rotation{0,0,0};
    glm::vec3 scale{1,1,1};

    glm::mat4 modelMatrix{1};
    float duration;

    float effectDuration;
protected:

    void generateModelMatrix();
    void updateKeyFrame();
    void empltyKeyFrames();

    glm::vec3 linearInterpolation(glm::vec3 a, glm::vec3 b, float t);
};

