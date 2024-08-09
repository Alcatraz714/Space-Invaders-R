#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        //const sf::String subzero_texture_path = "assets/textures/subzero.png";
        //const sf::String zapper_texture_path = "assets/textures/zapper.png";

        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;

        sf::RenderWindow* game_window;
        sf::Texture enemy_texture;
        sf::Sprite enemy_sprite;

        void initializeEnemySprite(EnemyType type);
        void scaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);
        void update();
        void render();
    };
}