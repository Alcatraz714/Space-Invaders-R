#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::player_lives;
	int PlayerModel::enemies_killed;
	int PlayerModel::bullets_fired;

	PlayerModel::PlayerModel() { entity_type = Entity::EntityType::PLAYER; }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); } // reset the player

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		//lives set to max of 3 at restart
		player_lives = max_player_lives;

		enemies_killed = 0;
		bullets_fired = 0;
		//powerups
		b_shield = false;
		b_rapid_fire = false;
		b_tripple_laser = false;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	Entity::EntityType PlayerModel::getEntityType()
	{
		return entity_type;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapid_fire;
	}

	bool PlayerModel::isTrippleLaserEnabled()
	{
		return b_tripple_laser;
	}

	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapid_fire = value;
	}

	void PlayerModel::setTrippleFireState(bool value)
	{
		b_tripple_laser = value;
	}
}