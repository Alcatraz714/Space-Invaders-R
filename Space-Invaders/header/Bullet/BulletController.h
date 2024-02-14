#pragma once
#include "../../header/Bullet/IBullet.h"
#include "../../header/Entity/EntityConfig.h"
#include "../Collision/ICollider.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;

    class BulletController : public IBullet, public Collision::ICollider
    {
    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;

        void updateBulletPosition();

        void processBulletCollision(ICollider* other_collider);
        void processEnemyCollision(ICollider* other_collider);
        void processPlayerCollision(ICollider* other_collider);
        void processBunkerCollision(ICollider* other_collider);

        void moveUp();
        void moveDown();

    public:
        BulletController(BulletType bullet_type, Entity::EntityType owner_type);
        virtual ~BulletController();

        void initialize(sf::Vector2f position, MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getBulletPosition();
        BulletType getBulletType();
        Entity::EntityType getOwnerEntityType();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}