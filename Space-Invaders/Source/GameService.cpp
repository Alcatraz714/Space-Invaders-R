#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

// Constructor: Initializes pointers to null.
GameService::GameService() {
	service_locator = nullptr; // Set service locator to null
	game_window = nullptr; // Set game window to null
}

// Destructor: Calls the destroy function to clean up resources.
GameService::~GameService() {
	destroy(); // Clean up and release resources
}

// Prepares the game service for use by obtaining the service locator instance and initializing services.
void GameService::ignite() {
	service_locator = ServiceLocator::getInstance(); // Get ServiceLocator
	initialize(); // Initialize services.
}

//initialize service locator and other variables
void GameService::initialize()
{
	service_locator->initialize();
	initializeVariables();
}

void GameService::initializeVariables()
{
	game_window = service_locator->getGraphicService()->getGameWindow(); //set game window (it was null before this)
}

void GameService::destroy()
{
	// don't need to do anything here for now.
}

// Updates the game logic by delegating to the service locator's update method.
void GameService::update() {

	service_locator->update(); // Call update on the service locator which then updates all its managed services
}

// Clears the window then display it.
void GameService::render() {
	// Clears the game window with the background color provided by the graphic service
	game_window->clear(service_locator->getGraphicService()->getWindowColor());
	service_locator->render(); // Render the current frame using the service locator
	game_window->display(); // Display the rendered frame on the game window
}

// Checks if the game is still running by querying the graphic service's window open status.
bool GameService::isRunning() {
	// Returns true if the game window is open, indicating the game is still running
	return service_locator->getGraphicService()->isGameWindowOpen();
}

