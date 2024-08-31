#include "../../header/Powerups/Controllers/OutscalBombController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type) {}

        OutscalBombController::~OutscalBombController() {}

        void OutscalBombController::applyPowerup()
        {
            ServiceLocator::getInstance()->getEnemyService()->reset();
        }
    }
}