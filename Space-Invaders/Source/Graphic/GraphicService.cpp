#include "../../Header/Graphic/GraphicService.h"

namespace Graphics
{
	GraphicService::GraphicService() {
		game_window = nullptr;
		video_mode = nullptr;
	}

	GraphicService::~GraphicService() {
		onDestroy();
	}

	void GraphicService::initialize() {
		game_window = createGameWindow();
		setFrameRate(frame_rate);
	}

	sf::RenderWindow* GraphicService::createGameWindow() {
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen); // Creates and returns a new RenderWindow object
	}

	// Sets up the video mode for the game window using specified dimensions and system's color depth.
	void GraphicService::setVideoMode() {
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
	}

	void GraphicService::onDestroy() {
		delete(video_mode); 
		delete(game_window);
	}

	void GraphicService::setFrameRate(int frame_rate_to_set)
	{
		game_window->setFramerateLimit(frame_rate_to_set);
	}
	
	void GraphicService::update() { }

	void GraphicService::render() { }

	bool GraphicService::isGameWindowOpen() {
		return game_window->isOpen();
	}

	sf::RenderWindow* GraphicService::getGameWindow() {
		return game_window;
	}

	sf::Color GraphicService::getWindowColor() {
		return window_color;
	}
}