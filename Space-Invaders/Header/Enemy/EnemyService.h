#pragma once
namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:

		void Destroy(); // function to delete enemy

		EnemyController* enemy; 	// enemy controller ptr

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy(); 		// Function to spawn enemy

	};
}