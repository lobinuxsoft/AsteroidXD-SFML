#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "class/game_objects/shoot.h"

using namespace sf;

class HpPowerup : public Sprite
{
private:
	const float maxTimer = 0.25f;
	Texture texture;
	CircleShape* shape;
	Sound soundfx;
	Vector2f speed;
	float maxSpeed;
	bool active = false;
	float timer = maxTimer;

	void screenLimitLogic();
	void movement(float deltaTime);
	void updateTimer(float deltaTime);

public:
	HpPowerup(Texture& texture, Vector2f position, float rotation, Vector2f scale, Vector2f speed, float maxSpeed, bool active);
	~HpPowerup() override;
	void setActive(bool active);
	void setSoundFx(SoundBuffer& buffer);
	bool getActive();
	float getRadius();
	void setSpeedByAngle(float angle);
	FloatRect getBounds();
	void update(float deltaTime);
	void draw(RenderWindow& window);
};

