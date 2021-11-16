#include "credits_scene.h"

CreditsScene::CreditsScene()
{
	font.loadFromFile("resources/fonts/Roboto-Medium.ttf");

	sceneName.setFont(font);
	sceneName.setString("CREDITS");
	sceneName.setCharacterSize(50);
	sceneName.setOrigin(sceneName.getLocalBounds().width * 0.5f, 0);
	sceneName.setPosition(screenWidth * 0.5f, 0);

	gameVersionText.setFont(font);
	gameVersionText.setString(gameVersion);
	gameVersionText.setCharacterSize(15);
	gameVersionText.setOrigin(gameVersionText.getLocalBounds().width, gameVersionText.getLocalBounds().height);
	gameVersionText.setPosition(screenWidth - 15, screenHeight - 15);

	matiasButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.2f), "Matias Galarza (Pilot)", 25);
	matiasButton->setFont(font);
	matiasButton->setPivot({ 0.5f,0.5f });

	ramiroButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.25f), "Ramiro Guzman (Co-Pilot)", 25);
	ramiroButton->setFont(font);
	ramiroButton->setPivot({ 0.5f,0.5f });

	kenneyButton1 = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.3f), "Simple Space by Kenney", 25);
	kenneyButton1->setFont(font);
	kenneyButton1->setPivot({ 0.5f,0.5f });

	kenneyButton2 = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.35f), "Crosshair Pack by Kenney", 25);
	kenneyButton2->setFont(font);
	kenneyButton2->setPivot({ 0.5f,0.5f });

	kenneyButton3 = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.4f), "Sci-Fi Sounds by Kenney", 25);
	kenneyButton3->setFont(font);
	kenneyButton3->setPivot({ 0.5f,0.5f });

	kenneyButton4 = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.45f), "Interface Sounds by Kenney", 25);
	kenneyButton4->setFont(font);
	kenneyButton4->setPivot({ 0.5f,0.5f });

	ansimuzButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.5f), "Space Background by Ansimuz", 25);
	ansimuzButton->setFont(font);
	ansimuzButton->setPivot({ 0.5f,0.5f });

	jothButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.55f), "Cyberpunk Moonlight Sonata by Joth", 25);
	jothButton->setFont(font);
	jothButton->setPivot({ 0.5f,0.5f });

	multyPeopleButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.6f), "Fight by Ville Nousiainen / Xythe / mutkanto", 25);
	multyPeopleButton->setFont(font);
	multyPeopleButton->setPivot({ 0.5f,0.5f });

	backButton = new Button(Vector2f(screenWidth * 0.5f, screenHeight * 0.9f), "Back to main", 25);
	backButton->setFont(font);
	backButton->setPivot({ 0.5f,0.5f });
}

CreditsScene::~CreditsScene()
{
	delete matiasButton;
	delete ramiroButton;
	delete kenneyButton1;
	delete kenneyButton2;
	delete kenneyButton3;
	delete kenneyButton4;
	delete ansimuzButton;
	delete jothButton;
	delete multyPeopleButton;
	delete backButton;
}

void CreditsScene::updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime)
{
	window.draw(sceneName);
	window.draw(gameVersionText);

	if (matiasButton->isClick())
	{
		string op = std::string("start ").append("https://www.linkedin.com/in/lobinux/");
		system(op.c_str());
	}

	if (ramiroButton->isClick())
	{
		string op = std::string("start ").append("https://www.linkedin.com/in/ramiro-guzman/");
		system(op.c_str());
	}

	if (kenneyButton1->isClick())
	{
		string op = std::string("start ").append("https://kenney.nl/assets/simple-space");
		system(op.c_str());
	}

	if (kenneyButton2->isClick())
	{
		string op = std::string("start ").append("https://kenney.nl/assets/crosshair-pack");
		system(op.c_str());
	}

	if (kenneyButton3->isClick())
	{
		string op = std::string("start ").append("https://kenney.nl/assets/sci-fi-sounds");
		system(op.c_str());
	}

	if (kenneyButton4->isClick())
	{
		string op = std::string("start ").append("https://kenney.nl/assets/interface-sounds");
		system(op.c_str());
	}

	if (ansimuzButton->isClick())
	{
		string op = std::string("start ").append("https://opengameart.org/content/space-background-3");
		system(op.c_str());
	}

	if (jothButton->isClick())
	{
		string op = std::string("start ").append("https://opengameart.org/content/cyberpunk-moonlight-sonata");
		system(op.c_str());
	}

	if (multyPeopleButton->isClick())
	{
		string op = std::string("start ").append("https://opengameart.org/content/fast-fight-battle-music");
		system(op.c_str());
	}

	if (backButton->isClick()) sceneState = SceneState::MainMenu;

	matiasButton->update(window);
	ramiroButton->update(window);
	kenneyButton1->update(window);
	kenneyButton2->update(window);
	kenneyButton3->update(window);
	kenneyButton4->update(window);
	ansimuzButton->update(window);
	jothButton->update(window);
	multyPeopleButton->update(window);
	backButton->update(window);
}
