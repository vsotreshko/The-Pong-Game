#ifndef PPGSO_START_SCREEN_H
#define PPGSO_START_SCREEN_H

#include <memory>

#include <ppgso/ppgso.h>
#include <src/ThePongGame/Main Objects/object.h>
#include <src/ThePongGame/Main Objects/scene.h>

class Start_screen : public Object {
private:
    // Static resources (Shared between instances)
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Shader> shader;

    //Things for mtl
    static std::vector<tinyobj::material_t> material;
    static std::map<std::string, int> material_map;

public:
    Start_screen();

    /*!
   * Update asteroid
   * @param scene Scene to interact with
   * @param dt Time delta for animation purposes
   * @return
   */
    bool update(Scene &scene, float dt) override;

    /*!
     * Render asteroid
     * @param scene Scene to render in
     */
    void render(Scene &scene) override;
};


#endif //PPGSO_INTROSCENE_H
