#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView() { createUIElements(); }

	PowerupView::~PowerupView() { destroy(); }

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		initializeImage();
	}

	void PowerupView::createUIElements()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initializeImage()
	{
		powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
	}

	void PowerupView::update()
	{
		powerup_image->setPosition(powerup_controller->getCollectiblePosition());
		powerup_image->update();
	}

	void PowerupView::render()
	{
		powerup_image->render();
	}

	const sf::Sprite& PowerupView::getPowerupSprite()
	{
		return powerup_image->getSprite();
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	void PowerupView::destroy()
	{
		delete(powerup_image);
	}
}