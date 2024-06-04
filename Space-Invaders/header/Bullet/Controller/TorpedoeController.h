#pragma once
#include "../../header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class TorpedoeController : public BulletController
        {
        private:
            const float torpedo_movement_speed = 200.f;

        public:
            TorpedoeController(BulletType bullet_type, Entity::EntityType owner_type);
            ~TorpedoeController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}