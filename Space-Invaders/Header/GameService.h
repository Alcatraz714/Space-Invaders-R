#pragma once


class GameService
{
private:
	void initialize();		// Handles game initialization.
	void destroy();			// Handles cleanup tasks.

public:
	GameService();			// Constructor for initializing the GameService object.
	~GameService();	        // Destructor for cleaning up resources upon object deletion.

	void ignite();			// Initiates the game.
	void update();			// Updates the game logic and game state.
	void render();			// Renders each frame of the game.
	bool isRunning();		// Checks if the game is currently running.
};