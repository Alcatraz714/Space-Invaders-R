#include "../../header/Element/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace UI::UIElement;

		BunkerView::BunkerView() { createUIElements(); }

		BunkerView::~BunkerView() { destroy(); }

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			initializeImage();
		}

		const sf::Sprite& BunkerView::getBunkerSprite()
		{
			return bunker_image->getSprite();
		}

		void BunkerView::createUIElements()
		{
			bunker_image = new ImageView();
		}

		void BunkerView::initializeImage()
		{
			bunker_image->initialize(Config::bunker_texture_path, bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
		}

		void BunkerView::update()
		{
			bunker_image->update();
		}

		void BunkerView::render()
		{
			bunker_image->render();
		}

		void BunkerView::destroy()
		{
			delete(bunker_image);
		}

	}
}