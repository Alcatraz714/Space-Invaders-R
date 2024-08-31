#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerups/PowerupConfig.h"
#include "../../header/Player/PlayerModel.h"

namespace Player
{
    class PlayerView;

    enum class PlayerState;

    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_tripple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freez_duration;

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        bool processBulletCollision(ICollider* other_collider);
        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezDuration();
        void freezPlayer();

        void updateFireDuration();
        void processBulletFire();
        void FireBullet(bool b_tripple_laser = false);
        void FireBullet(sf::Vector2f position);

        void updatePowerupDuration();

        void disableShield();
        void disableRapidFire();
        void disableTrippleLaser();



    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        void reset();

        void decreasePlayerLive();
        inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
        inline void increaseBulletsFired(int val) { PlayerModel::bullets_fired += val; }

        void enableShield();
        void enableRapidFire();
        void enableTrippleLaser();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}