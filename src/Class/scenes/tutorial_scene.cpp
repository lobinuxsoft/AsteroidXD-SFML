#include "tutorial_scene.h"

TutorialScene::TutorialScene()
{
	font.loadFromFile("resources/fonts/Roboto-Medium.ttf");

	sceneName.setFont(font);
	sceneName.setString("CREDITS");
	sceneName.setCharacterSize(50);
	sceneName.setOrigin(sceneName.getLocalBounds().width * 0.5f, 0);
	sceneName.setPosition(screenWidth * 0.5f, 0);

	tutorialDescriptionText.setFont(font);
	tutorialDescriptionText.setString(tutorialText);
	tutorialDescriptionText.setCharacterSize(20);
	tutorialDescriptionText.setOrigin(tutorialDescriptionText.getLocalBounds().width * 0.5f, 0);
	tutorialDescriptionText.setPosition(screenWidth * 0.5f, screenHeight * 0.1f);

	backButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.9f), "Back to main", 25);
	backButton->setFont(font);
	backButton->setPivot({ 0.5f,0.5f });
}

TutorialScene::~TutorialScene()
{
	delete backButton;
}

void TutorialScene::updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime)
{
	window.draw(sceneName);
	window.draw(tutorialDescriptionText);

	if (backButton->isClick()) sceneState = SceneState::MainMenu;

	backButton->update(window);
}
