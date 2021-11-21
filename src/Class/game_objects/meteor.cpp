#include "meteor.h"

#include "my_utils/games_utils.h"
#include "my_utils/maths_utils.h"
#include "my_utils/vector2_utils.h"

void Meteor::movement(float deltaTime)
{
	if (active) move(speed.x * deltaTime, speed.y * deltaTime);
}

void Meteor::screenLimitsLogic()
{
	if (active)
	{
		Vector2f position = getPosition();

		// Collision logic: player vs walls
		if (position.x > screenWidth + getRadius())
			position.x = -getRadius();
		else if (position.x < -getRadius())
			position.x = screenWidth + getRadius();

		if (position.y > screenHeight + getRadius())
			position.y = -getRadius();
		else if (position.y < -getRadius())
			position.y = screenHeight + getRadius();

		setPosition(position);
	}
}

Meteor::Meteor(Texture& texture, Vector2f position, float rotation, Vector2f scale, Vector2f speed, float maxSpeed, bool active)
{
	this->setTexture(texture);
	this->setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);

	this->speed = speed;
	this->maxSpeed = maxSpeed;
	this->active = active;

	shape = new CircleShape(getRadius());
	shape->setOrigin(Vector2f(getRadius(), getRadius()));
	shape->setFillColor(Color(0, 255, 0, 125));
}

Meteor::~Meteor()
{
	delete shape;
}

void Meteor::setExplosionSfx(SoundBuffer& buffer)
{
	explodeSfx.setBuffer(buffer);
}

float Meteor::getRadius()
{
	return Vector2Length(Vector2f(getGlobalBounds().width * getScale().x, getGlobalBounds().height * getScale().y)) * 0.2f;
}

FloatRect Meteor::getBounds()
{
	return shape->getGlobalBounds();
}

bool Meteor::getActive()
{
	return active;
}

void Meteor::setActive(bool active)
{
	this->active = active;
}

void Meteor::explode()
{
	setActive(false);
	explodeSfx.setPitch(static_cast<float>(RandomRange(0, 45) / 100) + 1);
	explodeSfx.play();
}

void Meteor::setSpeed(Vector2f speed)
{
	this->speed = speed;
}

void Meteor::setSpeedByAngle(float angle, bool inverseDir)
{
	this->speed = Vector2f { (float)cos(angle * DEG2RAD) * maxSpeed * ((inverseDir) ? -1.0f : 1.0f), (float)sin(angle * DEG2RAD) * maxSpeed * ((inverseDir) ? -1.0f : 1.0f) };
}

void Meteor::update(float deltaTime)
{
	movement(deltaTime);
	shape->setPosition(this->getPosition());
	screenLimitsLogic();
}

void Meteor::draw(RenderWindow& window)
{
	if (active)
	{
		window.draw(*this);

#if _DEBUG
		window.draw(*shape);
#endif // _DEBUG

	}
}