#include "hp_powerup.h"

void HpPowerup::screenLimitLogic()
{
	Vector2f position = getPosition();

	if (position.x > screenWidth + Vector2Length(getScale()))
		position.x = -Vector2Length(getScale());
	else if (position.x < -Vector2Length(getScale()))
		position.x = screenWidth + Vector2Length(getScale());

	if (position.y > (screenHeight + Vector2Length(getScale())))
		position.y = -Vector2Length(getScale());
	else if (position.y < -Vector2Length(getScale()))
		position.y = screenHeight + Vector2Length(getScale());

	setPosition(position);
}

void HpPowerup::movement(float deltaTime)
{
	if (active) move(speed.x * deltaTime, speed.y * deltaTime);
}

void HpPowerup::updateTimer(float deltaTime)
{
	if (!active)
	{
		if (timer > 0)
		{
			timer -= deltaTime;
		}
		else
		{
			this->setSpeedByAngle(RandomRange(0, 360));
			setActive(true);
		}
	}
}

HpPowerup::HpPowerup(Texture& texture, Vector2f position, float rotation, Vector2f scale, Vector2f speed, float maxSpeed, bool active)
{
	this->setTexture(texture);
	this->setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);
	this->setColor(Color::Green);

	this->speed = speed;
	this->maxSpeed = maxSpeed;
	this->active = active;

	shape = new CircleShape(getRadius());
	shape->setOrigin(Vector2f(getRadius(), getRadius()));
	shape->setFillColor(Color(0, 255, 0, 125));
}

HpPowerup::~HpPowerup()
{
	delete shape;
}

void HpPowerup::setActive(bool active)
{
	if (this->active && !active)
	{
		soundfx.play();
		this->timer = maxTimer;
	}
	this->active = active;
}

void HpPowerup::setSoundFx(SoundBuffer& buffer)
{
	soundfx.setBuffer(buffer);
}

bool HpPowerup::getActive()
{
	return active;
}

float HpPowerup::getRadius()
{
	return Vector2Length(Vector2f(getGlobalBounds().width * getScale().x, getGlobalBounds().height * getScale().y)) * 0.15f;
}

void HpPowerup::setSpeedByAngle(float angle)
{
	this->speed = Vector2f{ static_cast<float>(cos(angle * DEG2RAD)) * maxSpeed, static_cast<float>(sin(angle * DEG2RAD)) * maxSpeed };
}

FloatRect HpPowerup::getBounds()
{
	return shape->getGlobalBounds();
}

void HpPowerup::update(float deltaTime)
{
	screenLimitLogic();
	movement(deltaTime);
	this->shape->setPosition(getPosition());
	updateTimer(deltaTime);
}

void HpPowerup::draw(RenderWindow& window)
{
	if (active)
	{
		window.draw(*this);

#if _DEBUG
		window.draw(*shape);
#endif // _DEBUG

	}
}
