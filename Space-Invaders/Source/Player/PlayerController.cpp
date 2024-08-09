#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include<algorithm>

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Bullet;

	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
	}
	//the controller is responsible for calling the lifecycle methods for the other two
	void PlayerController::initialize()
	{
		player_model->initialize();

		//This will give an error right now since we haven't included the controller in the view.
		player_view->initialize(this); // 'this' refers to the class we are currently inside
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update(); // we update() the view
	}

	void PlayerController::render()
	{
		player_view->render(); // render the view
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::processPlayerInput()
	{
		
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}
		
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
		{
			fireBullet();
		}
	}	

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::fireBullet()
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
			player_model->getPlayerPosition() + player_model->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}
}