#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
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
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ZapperController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET, enemy_model->getEntityType(),
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}

		void ZapperController::destroy()
		{
			EnemyController::destroy();
		}
	}
}