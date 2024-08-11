#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerView;
    class PlayerModel;
    enum class PlayerState;

    class PlayerController
    {
    private:

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        void fireBullet();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
    };
}