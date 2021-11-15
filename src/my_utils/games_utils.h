#pragma once

#include <string>

using namespace std;

static const string gameName = "Asteroid xD [Remake]";
static const string gameVersion = "v0.1";

static int screenWidth = 800;
static int screenHeight = 600;

static int gameLevel = 1;

enum class SceneState
{
	MainMenu, Gameplay, Tutorial, Credits, Quit
};