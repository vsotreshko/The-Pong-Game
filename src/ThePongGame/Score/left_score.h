#pragma once
#include <memory>

#include <ppgso/ppgso.h>

#include "src/ThePongGame/Main Objects/scene.h"
#include "src/ThePongGame/Main Objects/object.h"

class Left_score final : public Object {
private:
    // Static resources (Shared between instances)
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Texture> texture;

    //Things for mtl
    static std::vector<tinyobj::material_t> material;
    static std::map<std::string, int> material_map;

public:
    Left_score();

    void updateNumber(int number);

    bool update(Scene &scene, float dt) override;
    void render(Scene &scene) override;


private:
};
