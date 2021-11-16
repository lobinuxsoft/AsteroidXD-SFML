#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Ship
{
private:
    const int maxShield = 100;
    const float maxVelocity = 3;

    Sprite sprite;

    Sound engineSfx;
    Sound shieldSfx;
    Sound explodeSfx;

    Vector2f velocity{ 0,0 };
    Vector2f dir{ 0,0 };
    Vector2f speed{ 0,0 };
    Vector2f mousePos{ 0,0 };
    float maxAcceleration = 150.0f;
    int shield = maxShield;
    float acceleration = 0.0f;
    float timer = 0.0f;

private:
    void lookAtMousePoint();
    void moveForward(float deltaTime);
    void screenLimitsLogic();

public:
    Ship(Texture& texture, Vector2f position, float rotation, Vector2f scale);
    ~Ship();
    void setEngineSfx(SoundBuffer& buffer);
    void setShieldSfx(SoundBuffer& buffer);
    void setExplodeSfx(SoundBuffer& buffer);
    float getRadius();
    int getShield();
    int getMaxShield();
    void resetShield();
    void resetState();
    float getMaxSpeed();
    bool damageShip(Vector2f hitPos = { 0,0 });
    void update(float deltaTime);
    void draw(RenderWindow& window);
};

