#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

		ThunderSnakeController::~ThunderSnakeController() { }

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(getInitialMovementDirection());
			enemy_model->horizontal_movement_speed = thunder_snake_horizontal_movement_speed;
		}

		MovementDirection ThunderSnakeController::getInitialMovementDirection()
		{
			static MovementDirection initial_direction = MovementDirection::RIGHT;

			switch (initial_direction)
			{
			case Enemy::MovementDirection::LEFT:
				initial_direction = MovementDirection::RIGHT;
				return initial_direction;

			case Enemy::MovementDirection::RIGHT:
				initial_direction = MovementDirection::LEFT;
				return initial_direction;
			}
		}

		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			case::Enemy::MovementDirection::LEFT_DOWN:
				moveDiagonalLeft();
				break;

			case::Enemy::MovementDirection::RIGHT_DOWN:
				moveDiagonalRight();
				break;
			}
		}

		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveDiagonalLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveDiagonalRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_model->vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::TORPEDO,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN, enemy_model->getEntityType());
		}

		void ThunderSnakeController::destroy()
		{
			EnemyController::destroy();
		}
	}
}