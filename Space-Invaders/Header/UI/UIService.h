#pragma once
#include "../../Header/UI/MainMenu/MainMenuUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}