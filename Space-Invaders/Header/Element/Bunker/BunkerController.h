#pragma once
#include <SFML/Graphics.hpp>
#include "../../Collision/ICollider.h"
#include "../../header/Element/Bunker/BunkerModel.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerView;

        class BunkerController : public Collision::ICollider
        {
        private:
            BunkerView* bunker_view;
            BunkerData bunker_data;

        public:
            BunkerController();
            ~BunkerController();

            void initialize(BunkerData data);
            void update();
            void render();

            sf::Vector2f getBunkerPosition();

            //sprite get method using getsprite
            const sf::Sprite& getColliderSprite() override;
            void onCollision(ICollider* other_collider) override;
        };
    }
}