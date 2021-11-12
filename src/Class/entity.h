#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Entity
{
protected:
	Sprite sprite;
	Texture texture;

public:
	Entity(Texture &texture, Vector2f position, float rotation, Vector2f scale);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setRotation(float rotation);
	Sprite getSprite();
};

