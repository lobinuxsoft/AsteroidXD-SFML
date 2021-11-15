#pragma once
#include "scene.h"

#include "class/game_objects/ship.h"
#include "class/ui_objects/button.h"

using namespace std;

class MainMenuScene : public Scene
{
private:
	Vector2f mousePosition;
	Font font;

	Text gameTitleText;
	Text gameVersionText;

	Button* playButton;
	Button* tutorialButton;
	Button* creditsButton;
	Button* quitButton;

public:
	MainMenuScene();
	~MainMenuScene();

	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;
};

