#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            const float thunder_snake_horizontal_movement_speed = 190.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDiagonalLeft();
            void moveDiagonalRight();

            void fireBullet() override;

            void destroy() override;

            MovementDirection getInitialMovementDirection();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
        };
    }
}