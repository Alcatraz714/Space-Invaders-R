#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Graphics;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackgroundSprite();
	}

	void GameplayView::initializeBackgroundSprite()
	{
		if (background_texture.loadFromFile(Config::background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			scaleBackgroundSprite();
		}
	}

	void GameplayView::scaleBackgroundSprite()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}

	void GameplayView::update() { }

	void GameplayView::render() { game_window->draw(background_sprite); }
}