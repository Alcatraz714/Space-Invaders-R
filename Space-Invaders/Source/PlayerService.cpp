#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

//init
void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

//take our players input in update, then set the position.
//order is important here
void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	// Handle movement - inputs now handled by eventservice
	EventService* event_service = ServiceLocator::getInstance()->getEventService(); //get the event service object created in service locator

	if (event_service->isKeyboardEvent())
	{
		if (event_service->pressedLeftKey())
		{
			move(-1.0f * getMoveSpeed());
		}

		if (event_service->pressedRightKey())
		{
			move(1.0f * getMoveSpeed());
		}
	}
}

void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::move(float offsetX) {
	position.x += offsetX;
}

//Getter and Setter Functions
sf::Vector2f PlayerService::getPlayerPosition() { return position; }
int PlayerService::getMoveSpeed() { return movement_speed; }