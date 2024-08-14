#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphic/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphics;
        using namespace Global;
        using namespace UIElement;
        using namespace Sound;

        SplashScreenUIController::SplashScreenUIController()
        {
            outscal_logo_view = new ImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscal_logo_view);
        }

        void SplashScreenUIController::initialize()
        {
            initializeOutscalLogo();
        }

        void SplashScreenUIController::update()
        {
            updateTimer();
            showMainMenu();
        }

        void SplashScreenUIController::render()
        {
            outscal_logo_view->render();
        }

        void SplashScreenUIController::initializeOutscalLogo()
        {
            sf::Vector2f position = getLogoPosition();
            outscal_logo_view->initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);

        }

        void SplashScreenUIController::showMainMenu()
        {
            if (elapsed_duration >= splash_screen_duration)
            {
                Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
                GameService::setGameState(GameState::MAIN_MENU);
            }

        }

        void SplashScreenUIController::updateTimer()
        {
            elapsed_duration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        }

        sf::Vector2f SplashScreenUIController::getLogoPosition()
        {
            sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            float x_position = (game_window->getSize().x - logo_width) / 2.0f;
            float y_position = (game_window->getSize().y - logo_height) / 2.0f;

            return sf::Vector2f(x_position, y_position);
        }

        void SplashScreenUIController::show()
        {

        }
    }
}