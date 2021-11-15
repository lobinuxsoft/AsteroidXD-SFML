#include "game_manager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "my_utils/games_utils.h"
#include "class/game_objects/parallax_background.h"
#include "class/scenes/main_menu_scene.h"

using namespace sf;
using namespace std;

SceneState sceneState = SceneState::MainMenu;

Vector2f mousePos;

Texture crossHairTex1;
Texture crossHairTex2;
Sprite crossHairSprite1;
Sprite crossHairSprite2;

ParallaxBackground* parallax;
MainMenuScene* mainMenuScene;


// Initialize game variables
static void initGame()
{
    crossHairTex1.loadFromFile("resources/images/crosshair158.png");
    crossHairTex1.setSmooth(true);
    crossHairTex2.loadFromFile("resources/images/crosshair185.png");
    crossHairTex2.setSmooth(true);

    crossHairSprite1.setTexture(crossHairTex1);
    crossHairSprite1.setOrigin({ crossHairTex1.getSize().x * 0.5f, crossHairTex1.getSize().y * 0.5f });
    crossHairSprite1.setScale({ 0.6f,0.6f });
    crossHairSprite1.setColor(Color(255, 154, 3));

    crossHairSprite2.setTexture(crossHairTex2);
    crossHairSprite2.setOrigin({ crossHairTex2.getSize().x * 0.5f, crossHairTex2.getSize().y * 0.5f });
    crossHairSprite2.setScale({ 0.5f,0.5f });
    crossHairSprite2.setColor(Color(255, 78, 3));

    parallax = new ParallaxBackground();
    mainMenuScene = new MainMenuScene();
}

// Update game (one frame)
static void update(RenderWindow& window, float deltaTime)
{
    parallax->update(window, deltaTime);

    switch (sceneState)
    {
    case SceneState::MainMenu:
        mainMenuScene->updateAndDraw(sceneState, window, deltaTime);
        break;
    case SceneState::Gameplay:
        break;
    case SceneState::Tutorial:
        break;
    case SceneState::Credits:
        break;
    case SceneState::Quit:
        window.close();
        break;
    }
}

// Unload game variables
static void unloadGame()
{
    delete parallax;
    delete mainMenuScene;
}

static void CrossHairBehaviour(RenderWindow& window, float deltaTime)
{
    crossHairSprite1.setPosition(mousePos);
    crossHairSprite2.setPosition(mousePos);

    crossHairSprite1.rotate(360 * deltaTime * 10);
    crossHairSprite2.rotate(-360 * deltaTime * 10);

    window.draw(crossHairSprite1);
    window.draw(crossHairSprite2);
}

void Run()
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    
    RenderWindow window(VideoMode(screenWidth, screenHeight), gameName + " - " + gameVersion);

    initGame();

    Clock deltaClock;
    float deltaTime = 0;

    while (window.isOpen())
    {
        // La cantidad de segundos que pasan en un frame
        deltaTime = deltaClock.restart().asSeconds() / 60;
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

#pragma region UPDATE AND DRAW

        update(window, deltaTime);

#pragma endregion
        
        mousePos = static_cast<Vector2f>(Mouse::getPosition(window));

        CrossHairBehaviour(window, deltaTime);

        window.display();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    unloadGame();         // Unload loaded data (textures, sounds, models...)
}