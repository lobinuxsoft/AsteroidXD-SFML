#include "gameplay_scene.h"

GameplayScene::GameplayScene()
{
    shipTexture.loadFromFile("resources/images/ship_G.png");
    shipTexture.setSmooth(true);
    // TODO terminar el gameplay

    ship = new Ship(shipTexture, { screenWidth * 0.5f, screenHeight * 0.5f }, 0, { 0.5f,0.5f });
}

GameplayScene::~GameplayScene()
{
	delete ship;

    // Delete Meteors
    for (Meteor* m : bigMeteor)
    {
        delete m;
    }
    bigMeteor.clear();

    for (Meteor* m : mediumMeteor)
    {
        delete m;
    }
    mediumMeteor.clear();

    for (Meteor* m : smallMeteor)
    {
        delete m;
    }
    smallMeteor.clear();
}
