#include "ship.h"

#include "my_utils/games_utils.h"
#include "my_utils/maths_utils.h"
#include "my_utils/vector2_utils.h"

void Ship::lookAtMousePoint()
{
	// Player logic: rotation
	
	if (Vector2Length(mousePos - this->sprite.getPosition()) > 40.f)
	{
		this->sprite.setRotation(Vector2Angle(this->sprite.getPosition(), mousePos) + 90);
		dir = Vector2Normalize(mousePos - this->sprite.getPosition());
	}
}

void Ship::moveForward(float deltaTime)
{
	// Player logic: acceleration
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		// Player logic: speed
		speed.x = dir.x;
		speed.y = -dir.y;

		velocity = velocity + Vector2f((speed.x * acceleration) * deltaTime, (speed.y * acceleration) * deltaTime);

		if (acceleration < 1) acceleration += maxAcceleration * deltaTime;
	}
	else
	{
		acceleration = (acceleration > 0) ? acceleration - deltaTime : 0;
	}

	//SetSoundVolume(engineSfx, (Vector2Length(velocity) * acceleration) * 0.01f);
	//SetSoundPitch(engineSfx, (Vector2Length(velocity) * acceleration) * 0.15f);
	//if (!IsSoundPlaying(engineSfx)) PlaySound(engineSfx);

	velocity = { Clamp(velocity.x, -maxVelocity, maxVelocity), Clamp(velocity.y, -maxVelocity, maxVelocity) };

	sprite.setPosition(Vector2f(sprite.getPosition().x + velocity.x, sprite.getPosition().y - velocity.y));
}

void Ship::screenLimitsLogic()
{
	Vector2f position = sprite.getPosition();

	// Collision logic: player vs walls
	if (position.x > screenWidth + radius) position.x = -radius;
	else if (position.x < -radius) position.x = screenWidth + radius;

	if (position.y > (screenHeight + radius)) position.y = -radius;
	else if (position.y < -radius) position.y = screenHeight + radius;

	sprite.setPosition(position);
}

Ship::Ship(Texture& texture, Vector2f position, float rotation, Vector2f scale)
{
	this->sprite.setTexture(texture);
	this->sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->sprite.setPosition(position);
	this->sprite.setRotation(rotation);
	this->sprite.setScale(scale);
}

float Ship::getRadius()
{
	return Vector2Length(this->sprite.getScale());
}

int Ship::getShield()
{
	return this->shield;
}

int Ship::getMaxShield()
{
	return this->maxShield;
}

void Ship::resetShield()
{
	shield = maxShield;
}

void Ship::resetState()
{
	this->velocity = { 0,0 };
	this->speed = { 0,0 };
	this->acceleration = 0;
	this->shield = maxShield;
}

float Ship::getMaxSpeed()
{
	return this->maxAcceleration;
}

bool Ship::damageShip(Vector2f hitPos)
{
	//SetSoundPitch(shieldSfx, ((float)GetRandomValue(0, 45) / 100) + 1);
	//PlaySound(shieldSfx);
	Vector2f pushDir = this->sprite.getPosition() - hitPos;
	timer = 0.5f;
	//color = RED;
	acceleration = 0;
	velocity.x += Vector2Normalize(pushDir).x;
	velocity.y -= Vector2Normalize(pushDir).y;
	shield--;

	//if (shield <= 0) PlaySound(explodeSfx);

	return shield <= 0;
}

void Ship::update(float deltaTime)
{
	lookAtMousePoint();
	moveForward(deltaTime);
	screenLimitsLogic();
}

void Ship::draw(RenderWindow& window)
{
	mousePos = static_cast<Vector2f>(Mouse::getPosition(window));
	window.draw(sprite);
}
