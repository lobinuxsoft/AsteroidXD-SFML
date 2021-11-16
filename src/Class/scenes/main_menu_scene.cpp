#include "main_menu_scene.h"

MainMenuScene::MainMenuScene()
{
	//mousePosition = Vector2f(0, 0);
	font.loadFromFile("resources/fonts/Roboto-Medium.ttf");

	gameTitleText.setFont(font);
	gameTitleText.setString(gameName);
	gameTitleText.setCharacterSize(50);
	gameTitleText.setOrigin(gameTitleText.getLocalBounds().width * 0.5f, 0);
	gameTitleText.setPosition(screenWidth * 0.5f, 0);

	gameVersionText.setFont(font);
	gameVersionText.setString(gameVersion);
	gameVersionText.setCharacterSize(15);
	gameVersionText.setOrigin(gameVersionText.getLocalBounds().width, gameVersionText.getLocalBounds().height);
	gameVersionText.setPosition(screenWidth - 15, screenHeight - 15);

	playButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.5f), "JUGAR NIVEL" + to_string(gameLevel), 25);
	playButton->setFont(font);
	playButton->setPivot({ 0.5f,0.5f });

	tutorialButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.6f), "TUTORIAL", 25);
	tutorialButton->setFont(font);
	tutorialButton->setPivot({ 0.5f,0.5f });

	creditsButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.7f), "CREDITS", 25);
	creditsButton->setFont(font);
	creditsButton->setPivot({ 0.5f,0.5f });

	quitButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.8f), "QUIT", 25);
	quitButton->setFont(font);
	quitButton->setPivot({ 0.5f,0.5f });
}

MainMenuScene::~MainMenuScene()
{
	delete playButton;
	delete tutorialButton;
	delete creditsButton;
	delete quitButton;
}

void MainMenuScene::updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime)
{
	//mousePosition = static_cast<Vector2f>(Mouse::getPosition(window));

	window.draw(gameTitleText);
	window.draw(gameVersionText);

	playButton->update(window);
	tutorialButton->update(window);
	creditsButton->update(window);
	quitButton->update(window);

	if (playButton->isClick()) sceneState = SceneState::Gameplay;

	if (tutorialButton->isClick()) sceneState = SceneState::Tutorial;

	if (creditsButton->isClick()) sceneState = SceneState::Credits;

	if (quitButton->isClick())
	{
		sceneState = SceneState::Quit;
	}
}