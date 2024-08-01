#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

namespace Global
{
    class ServiceLocator
    {
    private:

        // Private Attributes:
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;

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
        Event::EventService* getEventService();   // Retrieve the EventService instance
        Graphics::GraphicService* getGraphicService();   // Retrieve the GraphicService instance
        Player::PlayerService* getPlayerService(); // Retrieve the PlayerService instance
        Time::TimeService* getTimeService(); // Retrieve the TimeService instance
    };
}