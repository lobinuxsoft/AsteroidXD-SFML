#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Button
{
private:
	Sound clickSfx;
	Text text;
	int fontSize = 10;
	Color normalColor = Color::White;
	Color pressColor = Color::Red;
	bool hover = false;
	bool click = false;

private:
	void mouseCollision(Vector2f mousePosition);

public:
	Button(
		Vector2f position,
		String text,
		int fontSize = 10,
		Color normalColor = Color::White,
		Color pressColor = Color::Red
	);

	void setPivot(Vector2f pivot);
	void setFont(Font& font);
	void setText(String text);
	void setClickSfx(SoundBuffer& buffer);
	bool isClick();
	void update(RenderWindow& window);
};

