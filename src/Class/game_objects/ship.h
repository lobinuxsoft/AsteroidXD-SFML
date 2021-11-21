#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "class/game_objects/shoot.h"

using namespace sf;

class Ship : public Sprite
{
private:
    const int maxShield = 100;
    const float maxVelocity = 0.05f;
    const int bulletsAmount = 100;
    const float waitToShoot = 0.0025f;
    float shootCountDown = waitToShoot;

    CircleShape* shape;

    vector<Shoot*> shoots;

    Sound engineSfx;
    Sound shieldSfx;
    Sound explodeSfx;
    Sound laserSfx;

    Vector2f velocity{ 0,0 };
    Vector2f dir{ 0,0 };
    Vector2f speed{ 0,0 };
    Vector2f mousePos{ 0,0 };
    float maxAcceleration = 100.0f;
    int shield = maxShield;
    float acceleration = 0.0f;
    float timer = 0.0f;

private:
    void lookAtMousePoint();
    void moveForward(float deltaTime);
    void screenLimitsLogic();
    void shootBullet();
    void bulletsUpdate(float deltaTime);

public:
    Ship(Texture& texture, Vector2f position, float rotation, Vector2f scale);
    ~Ship();
    void setEngineSfx(SoundBuffer& buffer);
    void setShieldSfx(SoundBuffer& buffer);
    void setExplodeSfx(SoundBuffer& buffer);
    void setLaserSfx(SoundBuffer& buffer);

    int getShield();
    int getMaxShield();
    void resetShield();
    void resetState();
    FloatRect getBounds();
    float getRadius();
    float getMaxSpeed();
    bool damageShip(Vector2f hitPos = { 0,0 });
    bool intersectBulletsWithBound(FloatRect bound);
    void update(float deltaTime);
    void draw(RenderWindow& window);
};

