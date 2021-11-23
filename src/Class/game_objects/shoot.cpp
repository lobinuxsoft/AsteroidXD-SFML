#include "shoot.h"

void Shoot::move(float deltaTime)
{
	Vector2f position = getPosition();
	position.x += speed.x * deltaTime;
	position.y -= speed.y * deltaTime;
	setPosition(position);
}

void Shoot::screenLimitsLogic()
{
    // Collision logic: shoot vs walls
    if (getPosition().x > screenWidth + getRadius())
    {
        active = false;
        lifeSpawn = 0;
    }
    else if (getPosition().x < -getRadius())
    {
        active = false;
        lifeSpawn = 0;
    }
    if (getPosition().y > screenHeight + getRadius())
    {
        active = false;
        lifeSpawn = 0;
    }
    else if (getPosition().y < -getRadius())
    {
        active = false;
        lifeSpawn = 0;
    }
}

Shoot::Shoot(Vector2f position, Vector2f speed, int lifeSpawn, bool active, float radius, size_t pointCount) : CircleShape{ radius, pointCount }
{
	setPosition(position);
	setOrigin(radius, radius);
	this->speed = speed;
	this->lifeSpawn = lifeSpawn;
	this->active = active;
}

Shoot::~Shoot() { }

bool Shoot::getActive()
{
    return active;
}

void Shoot::setActive(bool active)
{
    this->active = active;
}

void Shoot::setSpeed(float rotation, float speed)
{
    this->speed = Vector2f(1.5f * sin(rotation * DEG2RAD) * speed, 1.5f * cos(rotation * DEG2RAD) * speed);
    setRotation(rotation);
}

void Shoot::resetLifeSpawn()
{
    lifeSpawn = 0;
}

void Shoot::update(float deltaTime)
{
    move(deltaTime);
    screenLimitsLogic();
    updateLifeSpawn(deltaTime);
}

float Shoot::getRadius()
{
    return Vector2Length(Vector2f(getGlobalBounds().width * getScale().x, getGlobalBounds().height * getScale().y)) / 2;
}

void Shoot::updateLifeSpawn(float deltaTime)
{
    // Life of shoot
    if (lifeSpawn >= maxLifeSpawn)
    {
        setPosition({0,0});
        speed = { 0, 0 };
        lifeSpawn = 0;
        active = false;
    }else
    {
        lifeSpawn += deltaTime;
    }
}
