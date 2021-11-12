#include "entity.h"

Entity::Entity(Texture& texture, Vector2f position, float rotation, Vector2f scale)
{
	this->sprite.setTexture(texture);

	this->sprite.setOrigin(0.5f, 0.5f);
	this->sprite.setPosition(position);
	this->sprite.setRotation(rotation);
	this->sprite.setScale(scale);
}

void Entity::setPosition(Vector2f position)
{
	this->sprite.setPosition(position);
}

Vector2f Entity::getPosition()
{
	return this->sprite.getPosition();
}

void Entity::setRotation(float rotation)
{
	this->sprite.setRotation(rotation);
}

Sprite Entity::getSprite()
{
	return this->sprite;
}
