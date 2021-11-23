#pragma once
#include "SFML/Graphics.hpp"
#include "my_utils/games_utils.h"
#include "my_utils/vector2_utils.h"

using namespace sf;

class Shoot : public CircleShape
{
private:
	const float maxLifeSpawn = 10;
	Vector2f speed;
	int lifeSpawn;
	bool active;

	void move(float deltaTime);
	void screenLimitsLogic();
	float getRadius();
	void updateLifeSpawn(float deltaTime);

public:
	Shoot(Vector2f position, Vector2f speed, int lifeSpawn, bool active, float radius, size_t pointCount = 30U);
	~Shoot() override;

	bool getActive();
	void setActive(bool active);
	void setSpeed(float rotation, float speed);
	void resetLifeSpawn();
	void update(float deltaTime);
};

