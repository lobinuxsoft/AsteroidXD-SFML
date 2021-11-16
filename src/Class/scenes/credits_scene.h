#pragma once
#include "scene.h"

#include "Class/ui_objects/button.h"

class CreditsScene : public Scene
{
private:
	Font font;
	Text sceneName;

	Button* matiasButton;
	Button* ramiroButton;
	Button* kenneyButton1;
	Button* kenneyButton2;
	Button* kenneyButton3;
	Button* kenneyButton4;
	Button* ansimuzButton;
	Button* jothButton;
	Button* multyPeopleButton;

	Button* backButton;

public:
	CreditsScene();
	~CreditsScene();

	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;

};

