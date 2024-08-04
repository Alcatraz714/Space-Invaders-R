#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Event;
	using namespace Time;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			moveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			moveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.x -= enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x <= left_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentPosition);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void EnemyController::moveRight()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.x += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x >= right_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentPosition);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
		{
			if (enemy_model->getReferencePosition().x <= left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
			else enemy_model->setMovementDirection(MovementDirection::LEFT);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}