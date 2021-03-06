#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Meteor : public Sprite
{
private:
	CircleShape* shape;
	Sound explodeSfx;
	Vector2f speed;
	float maxSpeed;
	bool active;

	void movement(float deltaTime);
	void screenLimitsLogic();

public:
	Meteor(Texture& texture, Vector2f position, float rotation, Vector2f scale, Vector2f speed, float maxSpeed, bool active);
	~Meteor() override;
	void setExplosionSfx(SoundBuffer& buffer);
	float getRadius();
	FloatRect getBounds();
	bool getActive();
	void setActive(bool active);
	void explode();
	void setSpeed(Vector2f speed);
	void setSpeedByAngle(float angle, bool inverseDir = false);
	void update(float deltaTime);
	void draw(RenderWindow& window);
};

