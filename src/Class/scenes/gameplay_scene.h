#pragma once
#include "scene.h"

#include "class/game_objects/ship.h"
#include "class/game_objects/meteor.h"

class GameplayScene : public Scene
{
private:
	// La nave que se usa
	Texture shipTexture;
	SoundBuffer engineSfxBuffer;
	SoundBuffer shiledSfxBuffer;
	SoundBuffer explodeShipSfxBuffer;
	Ship* ship;

	// Los disparos

	// Los meteoros
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

public:
	GameplayScene();
	~GameplayScene();

	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;
};

