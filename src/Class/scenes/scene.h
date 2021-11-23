#pragma once
#include "SFML/Graphics.hpp"
#include "my_utils/games_utils.h"

using namespace sf;

class Scene
{
public:
	Scene() { };
	virtual ~Scene() { };
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) = 0;
};

