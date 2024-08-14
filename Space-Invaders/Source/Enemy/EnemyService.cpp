#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService() { std::srand(static_cast<unsigned>(std::time(nullptr))); }

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (EnemyController* enemy : enemy_list)
			enemy->update();

		destroyFlaggedEnemies();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list)
			enemy->render();
	}

	void EnemyService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());

		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); // increase timer
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy(); //spawn 
			spawn_timer = 0.0f; // reset
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 4;  //since we only have 2 enemies right now
		return static_cast<Enemy::EnemyType>(randomType);
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete (enemy_list[i]);
		}
		enemy_list.clear();
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}
}