#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		ZapperController::ZapperController(EnemyType type) : EnemyController(type){ }

		ZapperController::~ZapperController() { }

		void ZapperController::initialize()
		{
			EnemyController::initialize();;
		}

		void ZapperController::move()
		{
			// Switch statement based on the movement direction of the enemy
			switch (enemy_model->getMovementDirection())
			{
				// If the movement direction is LEFT
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

				// If the movement direction is RIGHT
			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

				// If the movement direction is DOWN
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ZapperController::moveLeft()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			// Update the position to move left
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// Check if the enemy reached the leftmost position
			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				// Set movement direction to DOWN and update reference position
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				// Update the enemy position
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::moveRight()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			// Update the position to move right
			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// Check if the enemy reached the rightmost position
			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				// Set movement direction to DOWN and update reference position
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				// Update the enemy position
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::moveDown()
		{
			// Get the current position of the enemy
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			// Update the position to move down
			currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// Check if the enemy reached the reference position plus vertical travel distance
			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				// Check if the enemy reference position is on the left side
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
				{
					// Set movement direction to RIGHT
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					// Set movement direction to LEFT
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				// Update the enemy position
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN, enemy_model->getEntityType());
		}

		void ZapperController::destroy()
		{
			EnemyController::destroy();
		}
	}
}