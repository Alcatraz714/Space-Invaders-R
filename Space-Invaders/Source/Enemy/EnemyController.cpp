#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Sound/SoundService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	void EnemyController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); //update the elapsed duration
	}

	void EnemyController::processBulletFire() //if elapsed duration is equal to or more than the amount of time we want to wait until firing than call the fire method.
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f; //set elapsed duration back to 0.
		}
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));
		float x_position = enemy_model->left_most_position.x + x_offset_distance;
		float y_position = enemy_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	const sf::Sprite& EnemyController::getColliderSprite()
	{
		return enemy_view->getEnemySprite();
	}

	void EnemyController::onCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
		if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
		{
			destroy();
			return;
		}

		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);
		if (player_controller)
		{
			destroy();
			return;
		}
	}

	void EnemyController::destroy()
	{
		ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(enemy_model->getEnemyPosition(),
			Animation::AnimationType::EXPLOSION);

		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

		ServiceLocator::getInstance()->getPlayerService()->increaseEnemiesKilled(1);
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
	}
}