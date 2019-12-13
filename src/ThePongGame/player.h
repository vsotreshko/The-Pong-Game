#pragma once
#include <memory>

#include <ppgso/ppgso.h>

#include "src/ThePongGame/Main Objects/scene.h"
#include "src/ThePongGame/Main Objects/object.h"
#include "src/ThePongGame/Score/score_number.h"

/*!
 * Simple asteroid object
 * This sphere object represents an instance of mesh geometry
 * It initializes and loads all resources only once
 * It will move down along the Y axis and self delete when reaching below -10
 */
class Player final : public Object {
private:
    // Static resources (Shared between instances)
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Texture> texture;

    //Things for mtl
    static std::vector<tinyobj::material_t> material;
    static std::map<std::string, int> material_map;

public:
    bool turned;
    bool top;
    bool bottom;
    float acceleration{0.0f};
    int moves;

    int score;
    std::vector<std::unique_ptr<ScoreNumber>> score_signes;

    /*!
     * Create new asteroid
     */
    Player(int position, int moves_);

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

//    /*!
//     * Custom click event for asteroid
//     */
//    void onClick(Scene &scene) override;

    void increaseScore(Scene &scene, float dt, int to_Score);

    void endGame (Scene &scene, int player);
private:
};
