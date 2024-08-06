#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:

		const float spawn_interval = 2.f;

		std::vector<EnemyController*> enemy_list;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);
		void destroy();

	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy(); 		// Function to spawn enemy
		void destroyEnemy(EnemyController* enemy_controller);
	};
}