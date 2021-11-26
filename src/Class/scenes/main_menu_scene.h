#pragma once
#include "scene.h"

#include "class/game_objects/ship.h"
#include "class/ui_objects/button.h"

using namespace std;

class MainMenuScene : public Scene
{
private:
	//Vector2f mousePosition;
	Font font;

	Text gameTitleText;
	Text gameVersionText;

	SoundBuffer clickBufferSfx;
	SoundBuffer clickPlayBufferSfx;
	SoundBuffer clickTutorialBufferSfx;

	Music music;

	Button* playButton;
	Button* tutorialButton;
	Button* creditsButton;
	Button* quitButton;

public:
	MainMenuScene();
	~MainMenuScene() override;

	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;
};

