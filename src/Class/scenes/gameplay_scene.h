#pragma once
#include "scene.h"

#include "class/game_objects/ship.h"
#include "class/game_objects/meteor.h"
#include "class/game_objects/hp_powerup.h"
#include "class/ui_objects/health_bar.h"
#include "class/ui_objects/button.h"
#include "my_utils/maths_utils.h"
#include "my_utils/vector2_utils.h"

class GameplayScene : public Scene
{
private:
	int gameLevel = 1;
	bool gameOver = false;
	bool victory = false;
	bool pause = false;
	
	// UI
	Font font;
	Text text;
	Button* continueButton;
	Button* backButton;
	Button* pauseButton;
	HealthBar* healtBar;

	SoundBuffer clickBufferSfx;
	SoundBuffer clickPlayBufferSfx;
	Music music;

	// La nave que se usa
	Texture shipTexture;
	SoundBuffer engineSfxBuffer;
	SoundBuffer shiledSfxBuffer;
	SoundBuffer explodeShipSfxBuffer;
	SoundBuffer laserShipSfxBuffer;
	Ship* ship;

	// Powerups
	Texture powerupTexture;
	SoundBuffer powerupBuffer;
	HpPowerup* hpPowerup;

	// Los meteoros
	const int meteorsSpeed = 1000;
	Texture meteorTexture;
	SoundBuffer meteorExplosion;
	vector<Meteor*> bigMeteor;
	vector<Meteor*> mediumMeteor;
	vector<Meteor*> smallMeteor;

	const int baseAmountBigMeteors = 4;
	int maxBigMeteors = baseAmountBigMeteors;
	int maxMediumMeteors = maxBigMeteors * 2;
	int maxSmallMeteors = maxMediumMeteors * 2;

	int midMeteorsCount = 0;
	int smallMeteorsCount = 0;
	int destroyedMeteorsCount = 0;

	void createMeteors();
	void meteorsCollideWhitShip();
	void bulletsCollideWhitMeteors();

public:
	GameplayScene();
	~GameplayScene();

	void resetGame();
	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;
};

