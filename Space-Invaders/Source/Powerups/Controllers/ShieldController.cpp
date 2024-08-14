#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../header/Global/ServiceLocator.h"


namespace Powerup
{
    using namespace Global;

    namespace Controller
    {
        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

        void ShieldController::onCollected() {};

        void ShieldController::applyPowerup()
        {
            ServiceLocator::getInstance()->getPlayerService()->enableShield();
        }
    }
}