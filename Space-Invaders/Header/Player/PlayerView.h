#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player
{
    class PlayerController;
    class PlayerView
    {
    private:
        const float player_sprite_width = 60.f;
        const float player_sprite_height = 60.f;

        PlayerController* player_controller;
        UI::UIElement::ImageView* player_image;

        void createUIElements();
        void initializeImage();
        void destroy();

    public:
        PlayerView();
        ~PlayerView();

        void update();
        void render();
        const sf::Sprite& getPlayerSprite();
        void initialize(PlayerController* controller);
    };
}