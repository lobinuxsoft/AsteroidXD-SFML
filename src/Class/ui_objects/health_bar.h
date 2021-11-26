#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class HealthBar
{
private:
	int maxValue;
	int curValue;

	RectangleShape* front;
	RectangleShape* back;

public:
	HealthBar(Vector2f size, int maxValue, Color frontColor, Color backColor);
	~HealthBar();
	void setCurValue(int curValue);
	void draw(RenderWindow& window);
};

