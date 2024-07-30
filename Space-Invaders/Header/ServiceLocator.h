#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

class ServiceLocator
{
private:

    // Private Attributes:
    GraphicService* graphic_service;
    EventService* event_service;

    // Public Methods
    ServiceLocator();
    ~ServiceLocator();

    // Private Methods:
    void createServices();
    void clearAllServices();

public:

    // Public Methods:
    static ServiceLocator* getInstance();
    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.

    // Methods to Get Specific Services: 
    EventService* getEventService();   // Retrieve the EventService instance
    GraphicService* getGraphicService();   // Retrieve the GraphicService instance
};