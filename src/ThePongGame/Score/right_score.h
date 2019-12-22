#pragma once
#include <memory>

#include <ppgso/ppgso.h>

#include "src/ThePongGame/Main Objects/scene.h"
#include "src/ThePongGame/Main Objects/object.h"

/*!
 * Simple asteroid object
 * This sphere object represents an instance of mesh geometry
 * It initializes and loads all resources only once
 * It will move down along the Y axis and self delete when reaching below -10
 */
class Right_score final : public Object {
private:
    // Static resources (Shared between instances)
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Texture> texture;

    //Things for mtl
    static std::vector<tinyobj::material_t> material;
    static std::map<std::string, int> material_map;

public:
    Right_score();
    void updateNumber(int number);

    bool update(Scene &scene, float dt) override;
    void render(Scene &scene) override;

private:
};
