#include "../../Header/Powerups/Controllers/ShieldController.h"

namespace Powerup
{
    namespace Controller
    {
        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

        void ShieldController::onCollected() {};
    }
}