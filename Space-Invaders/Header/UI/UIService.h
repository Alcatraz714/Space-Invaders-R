#pragma once
#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;

		void createControllers();
		void initializeControllers();
		Interface::IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}