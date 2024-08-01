#pragma once
#include "../../Header/Player/PlayerController.h"

namespace Player
{
	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
	};
}
