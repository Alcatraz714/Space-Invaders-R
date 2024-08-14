#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Player/PlayerController.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() { createUIElements(); }

	PlayerView::~PlayerView() { destroy(); }

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller; //to later use it for setting position
		initializeImage();
	}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->update();
	}

	void PlayerView::render()
	{
		player_image->render();
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getSprite();
	}

	void PlayerView::destroy()
	{
		delete(player_image);
	}
}