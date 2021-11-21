#include "ship.h"

#include "my_utils/games_utils.h"
#include "my_utils/maths_utils.h"
#include "my_utils/vector2_utils.h"

void Ship::lookAtMousePoint()
{
	// Player logic: rotation
	
	if (Vector2Length(mousePos - this->getPosition()) > 40.f)
	{
		this->setRotation(Vector2Angle(this->getPosition(), mousePos) + 90);
		dir = Vector2Normalize(mousePos - this->getPosition());
	}
}

void Ship::moveForward(float deltaTime)
{
	// Player logic: acceleration
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		// Player logic: speed
		speed.x = dir.x;
		speed.y = -dir.y;

		velocity = velocity + Vector2f((speed.x * acceleration), (speed.y * acceleration)) * deltaTime;

		if (acceleration < 1) acceleration += maxAcceleration * deltaTime;
	}
	else
	{
		acceleration = (acceleration > 0) ? acceleration - deltaTime : 0;
	}

	//engineSfx.setVolume((Vector2Length(velocity) * acceleration) * 0.1f);
	//engineSfx.setVolume(1.0f);
	engineSfx.setPitch(abs((Vector2Length(velocity) * acceleration)) * 0.5f);

	if(engineSfx.getStatus() != SoundSource::Status::Playing)
		engineSfx.play();

	velocity = { Clamp(velocity.x, -maxVelocity, maxVelocity), Clamp(velocity.y, -maxVelocity, maxVelocity) };

	setPosition(Vector2f(getPosition().x + velocity.x, getPosition().y - velocity.y));
}

void Ship::screenLimitsLogic()
{
	Vector2f position = getPosition();

	// Collision logic: player vs walls
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

void Ship::shootBullet()
{
	if (shootCountDown <= 0)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			for (int i = 0; i < bulletsAmount; i++)
			{
				if (!shoots[i]->getActive())
				{
					shoots[i]->setPosition(
						Vector2f(
							getPosition().x + static_cast<float>(sin(getRotation() * DEG2RAD) * getRadius()),
							getPosition().y - static_cast<float>(cos(getRotation() * DEG2RAD) * getRadius())
						)
					);

					shoots[i]->setActive(true);
					shoots[i]->setSpeed(getRotation(), getMaxSpeed() * 20);

					laserSfx.setPitch(static_cast<float>(RandomRange(80, 120)) / 100.0f);
					laserSfx.play();
					shootCountDown = waitToShoot;
					break;
				}
			}
		}
	}
}

void Ship::bulletsUpdate(float deltaTime)
{
	if (shootCountDown > 0)
	{
		shootCountDown -= deltaTime;
	}

	// Shot logic
	for (int i = 0; i < bulletsAmount; i++)
	{
		if (shoots[i]->getActive())
		{
			shoots[i]->update(deltaTime);
		}
	}
}

Ship::Ship(Texture& texture, Vector2f position, float rotation, Vector2f scale)
{
	this->setTexture(texture);
	this->setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->setPosition(position);
	this->setRotation(rotation);
	this->setScale(scale);

	shape = new CircleShape(getRadius());
	shape->setOrigin(Vector2f(getRadius(), getRadius()));
	shape->setFillColor(Color(0, 255, 0, 125));

	for (size_t i = 0; i < bulletsAmount; i++)
	{
		shoots.push_back(new Shoot({ 0,0 }, { 0,0 }, 0, false, 5));
	}
}

Ship::~Ship()
{
	delete shape;

	for (Shoot* s : shoots)
	{
		delete s;
	}
	shoots.clear();

	if (engineSfx.getStatus() == SoundSource::Status::Playing) engineSfx.stop();
}

void Ship::setEngineSfx(SoundBuffer& buffer)
{
	engineSfx.setBuffer(buffer);
	engineSfx.setLoop(true);
}

void Ship::setShieldSfx(SoundBuffer& buffer)
{
	shieldSfx.setBuffer(buffer);
}

void Ship::setExplodeSfx(SoundBuffer& buffer)
{
	explodeSfx.setBuffer(buffer);
}

void Ship::setLaserSfx(SoundBuffer& buffer)
{
	laserSfx.setBuffer(buffer);
}

int Ship::getShield()
{
	this->shield = this->shield > 0 ? this->shield : 0;
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

	for (Shoot* s : shoots)
	{
		s->resetLifeSpawn();
	}
}

FloatRect Ship::getBounds()
{
	return shape->getGlobalBounds();
}

float Ship::getRadius()
{
	return Vector2Length(Vector2f(getGlobalBounds().width * getScale().x, getGlobalBounds().height * getScale().y)) / 2;
}

float Ship::getMaxSpeed()
{
	return this->maxAcceleration;
}

bool Ship::damageShip(Vector2f hitPos)
{
	shieldSfx.setPitch(static_cast<float>(RandomRange(0, 45)/100) + 1);
	shieldSfx.play();
	Vector2f pushDir = Vector2Normalize(this->getPosition() - hitPos);
	timer = 0.02f;
	setColor(Color::Red);
	acceleration = 0;
	velocity.x += pushDir.x * 0.01f;
	velocity.y -= pushDir.y * 0.01f;

	velocity = { Clamp(velocity.x, -maxVelocity, maxVelocity), Clamp(velocity.y, -maxVelocity, maxVelocity) };

	shield--;

	if (shield <= 0)
	{
		explodeSfx.play();
	}

	return shield <= 0;
}

bool Ship::intersectBulletsWithBound(FloatRect bound)
{
	for (int i = 0; i < bulletsAmount; i++)
	{
		if (shoots[i]->getActive() && shoots [i]->getGlobalBounds().intersects(bound))
		{
			shoots[i]->setActive(false);
			shoots[i]->resetLifeSpawn();
			return true;
		}
	}
	return false;
}

void Ship::update(float deltaTime)
{
	if (timer > 0)
	{
		timer -= deltaTime;
	}
	else
	{
		setColor(Color::White);
	}

	lookAtMousePoint();
	moveForward(deltaTime);
	screenLimitsLogic();

	shootBullet();

	bulletsUpdate(deltaTime);

	shape->setPosition(getPosition());
}

void Ship::draw(RenderWindow& window)
{
	mousePos = static_cast<Vector2f>(Mouse::getPosition(window));
	window.draw(*this);

	for (int i = 0; i < bulletsAmount; i++)
	{
		if(shoots[i]->getActive())
		{
			window.draw(*shoots[i]);
		}
	}

#if _DEBUG
	window.draw(*shape);
#endif // _DEBUG

}
