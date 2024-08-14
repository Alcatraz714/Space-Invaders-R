#pragma once
#include "../../Header/Powerups/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class ShieldController : public PowerupController
        {
        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();

            void onCollected() override;
            void applyPowerup();
        };
    }
}