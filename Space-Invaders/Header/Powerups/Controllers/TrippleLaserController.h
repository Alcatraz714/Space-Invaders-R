#pragma once
#include "../../header/Powerups/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TrippleLaserController : public PowerupController
        {
        protected:
            void applyPowerup() override;

        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();
        };
    }
}