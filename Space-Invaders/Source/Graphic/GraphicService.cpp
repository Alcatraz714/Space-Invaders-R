#include "../../Header/Graphic/GraphicService.h"

namespace Graphics
{
	// Constructor: Initializes game window and video mode pointers to null.
	GraphicService::GraphicService() {
		game_window = nullptr; // Initializes game window pointer to null
		video_mode = nullptr; // Initializes video mode pointer to null
	}

	// Destructor: Cleans up resources by calling onDestroy.
	GraphicService::~GraphicService() {
		onDestroy(); // Calls onDestroy method to clean up resources
	}

	// Initializes the graphic service by creating a new game window.
	void GraphicService::initialize() {
		game_window = createGameWindow(); // Assigns a new game window
		game_window->setFramerateLimit(frame_rate); // setting a frame rate limit
	}

	// Creates a new SFML RenderWindow object with specified video mode and title.
	sf::RenderWindow* GraphicService::createGameWindow() {
		setVideoMode(); // Sets up the video mode for the window
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen); // Creates and returns a new RenderWindow object
	}

	// Sets up the video mode for the game window using specified dimensions and system's color depth.
	void GraphicService::setVideoMode() {
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
	}

	// Cleans up allocated memory for video mode and game window to avoid memory leaks.
	void GraphicService::onDestroy() {
		delete(video_mode); // Deletes the video mode object
		delete(game_window); // Deletes the game window object
	}

	// Placeholder function for game update logic.
	void GraphicService::update() { }

	// Placeholder function for game rendering logic.
	void GraphicService::render() { }

	// Checks if the game window is currently open.
	bool GraphicService::isGameWindowOpen() {
		return game_window->isOpen(); // Returns the open status of the game window
	}

	// Returns a pointer to the game window object.
	sf::RenderWindow* GraphicService::getGameWindow() {
		return game_window;
	}

	// Returns the configured window background color.
	sf::Color GraphicService::getWindowColor() {
		return window_color;
	}
}