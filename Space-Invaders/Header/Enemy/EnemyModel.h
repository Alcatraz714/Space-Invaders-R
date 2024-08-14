#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Entity/EntityConfig.h"

namespace Enemy
{
    enum class EnemyType;
    enum class MovementDirection;
    enum class EnemyState;

    class EnemyModel
    {
    private:
        sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemy_position;

        Entity::EntityType entity_type;
        MovementDirection movement_direction;
        EnemyType enemy_type;
        EnemyState enemy_state;

    public:
        EnemyModel(EnemyType type);
        ~EnemyModel();

        //const settings for enemy
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 50.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 50.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);

        const float vertical_travel_distance = 100.f;
        const float enemy_movement_speed = 250.0f;

        float vertical_movement_speed = 30.0f;
        float horizontal_movement_speed = 100.0f;

        void initialize();

        // Getters and Setters
        sf::Vector2f getEnemyPosition();
        void setEnemyPosition(sf::Vector2f position);
        sf::Vector2f getReferencePosition();
        void setReferencePosition(sf::Vector2f position);
        EnemyState getEnemyState();
        void setEnemyState(EnemyState state);
        EnemyType getEnemyType();
        void setEnemyType(EnemyType type);
        MovementDirection getMovementDirection();
        void setMovementDirection(MovementDirection direction);
        Entity::EntityType getEntityType();
    };
}