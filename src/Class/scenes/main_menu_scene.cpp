#include "main_menu_scene.h"

MainMenuScene::MainMenuScene()
{
	music.openFromFile("resources/music/CyberpunkMoonlightSonata.ogg");
	music.setVolume(25);
	music.setLoop(true);

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
	gameVersionText.setPosition(static_cast<float>(screenWidth - 15), static_cast<float>(screenHeight - 15));

	clickBufferSfx.loadFromFile("resources/sfx/select_003.ogg");
	clickPlayBufferSfx.loadFromFile("resources/sfx/confirmation_002.ogg");
	clickTutorialBufferSfx.loadFromFile("resources/sfx/question_003.ogg");

	playButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.5f), "JUGAR", 25);
	playButton->setFont(font);
	playButton->setClickSfx(clickPlayBufferSfx);
	playButton->setPivot({ 0.5f,0.5f });

	tutorialButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.6f), "TUTORIAL", 25);
	tutorialButton->setFont(font);
	tutorialButton->setClickSfx(clickTutorialBufferSfx);
	tutorialButton->setPivot({ 0.5f,0.5f });

	creditsButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.7f), "CREDITS", 25);
	creditsButton->setFont(font);
	creditsButton->setClickSfx(clickBufferSfx);
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

	if (music.getStatus() != SoundSource::Playing) music.play();

	window.draw(gameTitleText);
	window.draw(gameVersionText);

	playButton->update(window);
	tutorialButton->update(window);
	creditsButton->update(window);
	quitButton->update(window);

	if (playButton->isClick())
	{
		music.stop();
		sceneState = SceneState::Gameplay;
	}

	if (tutorialButton->isClick()) sceneState = SceneState::Tutorial;

	if (creditsButton->isClick()) sceneState = SceneState::Credits;

	if (quitButton->isClick())
	{
		sceneState = SceneState::Quit;
	}
}