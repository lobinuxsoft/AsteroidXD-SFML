#include "health_bar.h"

HealthBar::HealthBar(Vector2f size, int maxValue, Color frontColor, Color backColor)
{
	this->maxValue = maxValue;
	this->curValue = maxValue;

	back = new RectangleShape(size);
	back->setPosition(10, 10);
	back->setFillColor(Color(0, 0, 0, 125));
	back->setOutlineThickness(2);
	back->setOutlineColor(backColor);

	front = new RectangleShape(size);
	front->setPosition(10, 10);
	front->setFillColor(frontColor);
}

HealthBar::~HealthBar()
{
	delete front;
	delete back;
}

void HealthBar::setCurValue(int curValue)
{
	this->curValue = curValue;
}

void HealthBar::draw(RenderWindow& window)
{
	front->setScale({ static_cast<float>(curValue) / maxValue, 1 });

	window.draw(*back);
	window.draw(*front);
}
