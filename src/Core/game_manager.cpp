#include "game_manager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

static const string gameName = "Asteroid xD SFML version";
static const string gameVersion = "v0.1";

int screenWidth = 800;
int screenHeight = 600;

// Initialize game variables
static void InitGame()
{
    
}

// Update game (one frame)
static void UpdateGame()
{

}

// Draw game (one frame)
static void DrawGame()
{
    
}

// Update and Draw (one frame)
static void UpdateDrawGameFrame()
{
    UpdateGame();
    DrawGame();
}

// Unload game variables
static void UnloadGame()
{
    
}

void Run()
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    string gameName = "Asteroid xD SFML";
    string gameVersion = "v0.1";
    
    RenderWindow window(VideoMode(screenWidth, screenHeight), gameName + " - " + gameVersion);

    InitGame();

    Clock deltaClock;
    float deltaTime = 0;

    while (window.isOpen())
    {
        deltaTime = deltaClock.restart().asSeconds();
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        // Unpdate and draw here
        UpdateDrawGameFrame();
        window.display();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)
}