#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Collision/CollisionService.h"
#include "../../Header/AnimationSystem/AnimationService.h"


// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

namespace Global
{
    class ServiceLocator
    {
    private:

        // Private Attributes:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Gameplay::GameplayService* gameplay_service;
        Player::PlayerService* player_service;
        Enemy::EnemyService* enemy_service;
        Element::ElementService* element_service;
        Bullet::BulletService* bullet_service;
        Powerup::PowerupService* powerup_service;
        Sound::SoundService* sound_service;
        Collision::CollisionService* collision_service;
        Animation::AnimationService* animation_service;

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
        UI::UIService* getUIService(); // Retrive the UIService instance
        Enemy::EnemyService* getEnemyService(); // Retrive the EnemyService instance
        Gameplay::GameplayService* getGameplayService(); // Retrive the GameplayService instance
        Element::ElementService* getElementService(); // Retrive the ElementService instance
        Sound::SoundService* getSoundService(); // Retrive the SoundService instance 
        Bullet::BulletService* getBulletService(); // Retrive the BulletService instance
        Powerup::PowerupService* getPowerupService(); // Retrive the PowerupService instance
        Collision::CollisionService* getCollisionService(); // Retrive the CollisionService instance
        Animation::AnimationService* getAnimationService(); // Retrive the AnimationService instance
        void deleteServiceLocator();
    };
}