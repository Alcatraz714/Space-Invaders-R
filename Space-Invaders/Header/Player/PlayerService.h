#pragma once
#include "../../Header/Player/PlayerController.h"

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
