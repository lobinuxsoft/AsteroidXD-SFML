#include "button.h"

void Button::mouseCollision(Vector2f mousePosition)
{
	hover = text.getGlobalBounds().contains(mousePosition);
	click = hover && Mouse::isButtonPressed(Mouse::Left);
}

Button::Button(Vector2f position, String text, int fontSize, Color normalColor, Color pressColor)
{
	this->normalColor = normalColor;
	this->pressColor = pressColor;
	this->text.setString(text);
	this->text.setPosition(position);
	this->text.setCharacterSize(fontSize);
}

void Button::setPivot(Vector2f pivot)
{
	text.setOrigin(text.getLocalBounds().width * pivot.x, text.getLocalBounds().height * pivot.y);
}

void Button::setFont(Font& font)
{
	text.setFont(font);
}

void Button::setText(String text)
{
	this->text.setString(text);
}

bool Button::isClick()
{
	return click;
}

void Button::update(RenderWindow& window)
{
	mouseCollision(static_cast<Vector2f>(Mouse::getPosition(window)));

	text.setFillColor(hover ? pressColor : normalColor);

	window.draw(text);
}
