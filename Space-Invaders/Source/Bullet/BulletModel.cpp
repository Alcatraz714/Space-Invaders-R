#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	using namespace Entity;

	BulletModel::BulletModel(BulletType type, EntityType owner_type)
	{
		this->bullet_type = type;
		this->owner_type = owner_type;
	}

	BulletModel::~BulletModel() { }

	void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
	{
		movement_direction = direction;
		bullet_position = position;
	}

	sf::Vector2f BulletModel::getBulletPosition()
	{
		return bullet_position;
	}

	void BulletModel::setBulletPosition(sf::Vector2f position)
	{
		bullet_position = position;
	}

	BulletType BulletModel::getBulletType()
	{
		return bullet_type;
	}

	Entity::EntityType BulletModel::getOwnerEntityType()
	{
		return owner_type;
	}

	MovementDirection BulletModel::getMovementDirection()
	{
		return movement_direction;
	}

	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	float BulletModel::getMovementSpeed()
	{
		return movement_speed;
	}

	void BulletModel::setMovementSpeed(float speed)
	{
		movement_speed = speed;
	}
}