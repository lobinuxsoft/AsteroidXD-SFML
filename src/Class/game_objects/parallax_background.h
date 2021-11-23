#pragma once
#include <vector>

#include "my_utils/games_utils.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class ParallaxBackground
{

private:
	Shader shader1;
	Shader shader2;

	Texture texture1;
	Texture texture2;

	Sprite sprite1;
	Sprite sprite2;

	float offset1 = 0;
	float offset2 = 0;

	float speed1 = 0.5f;
	float speed2 = 0.75f;

	float scale = 4;

public:
	ParallaxBackground();
	void update(RenderWindow& window, float deltaTime);
};

