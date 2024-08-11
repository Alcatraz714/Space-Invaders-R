#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController :public Interface::IUIController
		{

		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;
			const float play_button_y_position = 500.f;
			const float instructions_button_y_position = 700.f;
			const float quit_button_y_position = 900.f;
			const float background_alpha = 85.f;
			UIElement::ImageView* background_image;

			// UI Elements
			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			// Buttons and scaling
			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize();
			void update();
			void render();
			void show() override;
		};
	}
}