#include "../../Header/Powerups/Controllers/OutscalBombController.h"

namespace Powerup
{
    namespace Controller
    {
        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type) {}

        OutscalBombController::~OutscalBombController() {}

        void OutscalBombController::onCollected() {};
    }
}