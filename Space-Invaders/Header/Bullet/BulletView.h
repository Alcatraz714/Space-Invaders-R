#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Bullet
{
    class BulletController;
    enum class BulletType;

    class BulletView
    {
    private:
        const float bullet_sprite_width = 18.f;
        const float bullet_sprite_height = 18.f;

        BulletController* bullet_controller;
        UI::UIElement::ImageView* bullet_image;

        void createUIElements();
        void initializeImage();
        sf::String getBulletTexturePath();

        void destroy();

    public:
        BulletView();
        ~BulletView();

        void initialize(BulletController* controller);
        void update();
        void render();

        const sf::Sprite& getBulletSprite();
    };
}