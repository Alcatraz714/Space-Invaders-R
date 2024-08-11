#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};

		class UIView
		{
		protected:
			sf::RenderWindow* game_window;
			UIState ui_state;

		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			// to enable/disable render of ui 
			virtual void show();
			virtual void hide();
		};
	}
}