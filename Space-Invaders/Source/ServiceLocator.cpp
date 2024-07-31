#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphic_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	createServices();
}
ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphic_service = new GraphicService();
	event_service = new EventService();
	player_service = new PlayerService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphic_service);
	delete(event_service);
	delete(player_service);
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	graphic_service->initialize();
	event_service->initialize();
	player_service->initialize();
}

void ServiceLocator::update()
{
	graphic_service->update();
	event_service->update();
	player_service->update();
}

void ServiceLocator::render()
{
	graphic_service->render();
	player_service->render();
	//no event service because nothing to render
}

GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
EventService* ServiceLocator::getEventService() { return event_service; }
PlayerService* ServiceLocator::getPlayerService() { return player_service; }
