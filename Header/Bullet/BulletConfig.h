#pragma once
namespace Bullet
{
	enum class BulletType
	{
		LASER_BULLET,
		TORPEDO,
		FROST_BULLET,
	};

	enum class MovementDirection
	{
		UP, //player needs to shoot in upward direction
		DOWN, // enemies always shoot in downward direction
	};
}