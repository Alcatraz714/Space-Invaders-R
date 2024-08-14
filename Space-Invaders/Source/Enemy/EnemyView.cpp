#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	EnemyView::EnemyView() { createUIElements(); }

	EnemyView::~EnemyView() { destroy(); }

	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		initializeImage();
	}

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;

		case::Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;

		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
		}
	}

	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	void EnemyView::destroy()
	{
		delete (enemy_image);
	}
}