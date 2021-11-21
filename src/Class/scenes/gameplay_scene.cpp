#include "gameplay_scene.h"

void GameplayScene::createMeteors()
{
    destroyedMeteorsCount = 0;

    float posx, posy;
    float velx, vely;
    bool correctRange = false;

    // Reset all arrays of poiters

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
    //----------------------------

    maxBigMeteors = baseAmountBigMeteors * gameLevel;
    maxMediumMeteors = maxBigMeteors * 2;
    maxSmallMeteors = maxMediumMeteors * 2;

    for (int i = 0; i < maxBigMeteors; i++)
    {
        posx = static_cast<float>(RandomRange(0, screenWidth));

        while (!correctRange)
        {
            if (posx > screenWidth / 2 - 150 && posx < screenWidth / 2 + 150)
                posx = static_cast<float>(RandomRange(0, screenWidth));
            else
                correctRange = true;
        }

        correctRange = false;

        posy = static_cast<float>(RandomRange(0, screenHeight));

        while (!correctRange)
        {
            if (posy > screenHeight / 2 - 150 && posy < screenHeight / 2 + 150)
                posy = static_cast<float>(RandomRange(0, screenHeight));
            else
                correctRange = true;
        }


        correctRange = false;
        velx = static_cast<float>(RandomRange(-meteorsSpeed, meteorsSpeed));
        vely = static_cast<float>(RandomRange(-meteorsSpeed, meteorsSpeed));

        while (!correctRange)
        {
            if (velx == 0 && vely == 0)
            {
                velx = static_cast<float>(RandomRange(-meteorsSpeed, meteorsSpeed));
                vely = static_cast<float>(RandomRange(-meteorsSpeed, meteorsSpeed));
            }
            else correctRange = true;
        }

        Meteor* newBigMeteor = new Meteor(
            meteorTexture,
            Vector2f(posx, posy),
            static_cast<float>(RandomRange(0, 360)),
            Vector2f(1,1),
            Vector2f(velx, vely),
            static_cast<float>(meteorsSpeed + (gameLevel * meteorsSpeed)), true);

        newBigMeteor->setExplosionSfx(meteorExplosion);

        bigMeteor.push_back(newBigMeteor);
    }

    for (int i = 0; i < maxMediumMeteors; i++)
    {
        Meteor* newMediumMeteor = new Meteor(
            meteorTexture,
            Vector2f(-100, -100),
            static_cast<float>(RandomRange(0, 360)),
            Vector2f(0.5f, 0.5f),
            Vector2f(0, 0),
            static_cast<float>(meteorsSpeed + (gameLevel * meteorsSpeed)), false);

        newMediumMeteor->setExplosionSfx(meteorExplosion);

        mediumMeteor.push_back(newMediumMeteor);
    }

    for (int i = 0; i < maxSmallMeteors; i++)
    {
        Meteor* newSmallMeteor = new Meteor(
            meteorTexture,
            Vector2f(-100, -100),
            static_cast<float>(RandomRange(0, 360)),
            Vector2f(0.25f, 0.25f),
            Vector2f(0, 0),
            static_cast<float>(meteorsSpeed + (gameLevel * meteorsSpeed)), false);

        newSmallMeteor->setExplosionSfx(meteorExplosion);

        smallMeteor.push_back(newSmallMeteor);
    }

    midMeteorsCount = 0;
    smallMeteorsCount = 0;
}

void GameplayScene::meteorsCollideWhitShip()
{
    for (int a = 0; a < maxBigMeteors; a++)
    {
        if (bigMeteor[a]->getBounds().intersects(ship->getBounds()) && bigMeteor[a]->getActive())
        {
            gameOver = ship->damageShip(bigMeteor[a]->getPosition());
        }
    }

    for (int a = 0; a < maxMediumMeteors; a++)
    {
        if (mediumMeteor[a]->getBounds().intersects(ship->getBounds()) && mediumMeteor[a]->getActive())
        {
            gameOver = ship->damageShip(mediumMeteor[a]->getPosition());
        }
    }

    for (int a = 0; a < maxSmallMeteors; a++)
    {
        if (smallMeteor[a]->getBounds().intersects(ship->getBounds()) && smallMeteor[a]->getActive())
        {
            gameOver = ship->damageShip(smallMeteor[a]->getPosition());
        }
    }
}

void GameplayScene::bulletsCollideWhitMeteors()
{
    for (size_t a = 0; a < bigMeteor.size(); a++)
    {
        if (bigMeteor[a]->getActive() && ship->intersectBulletsWithBound(bigMeteor[a]->getBounds()))
        {
            bigMeteor[a]->explode();
            destroyedMeteorsCount++;

            for (int j = 0; j < 2; j++)
            {
                if (midMeteorsCount % 2 == 0)
                {
                    mediumMeteor[midMeteorsCount]->setPosition(bigMeteor[a]->getPosition());
                    mediumMeteor[midMeteorsCount]->setSpeedByAngle(ship->getRotation(), true);
                }
                else
                {
                    mediumMeteor[midMeteorsCount]->setPosition(bigMeteor[a]->getPosition());
                    mediumMeteor[midMeteorsCount]->setSpeedByAngle(ship->getRotation());
                }

                mediumMeteor[midMeteorsCount]->setActive(true);
                midMeteorsCount++;
            }

            a = maxBigMeteors;
        }
    }

    for (size_t b = 0; b < mediumMeteor.size(); b++)
    {
        if (mediumMeteor[b]->getActive() && ship->intersectBulletsWithBound(mediumMeteor[b]->getBounds()))
        {
            mediumMeteor[b]->explode();
            destroyedMeteorsCount++;

            for (int j = 0; j < 2; j++)
            {
                if (smallMeteorsCount % 2 == 0)
                {
                    smallMeteor[smallMeteorsCount]->setPosition(mediumMeteor[b]->getPosition());
                    smallMeteor[smallMeteorsCount]->setSpeedByAngle(ship->getRotation(), true);
                }
                else
                {
                    smallMeteor[smallMeteorsCount]->setPosition(mediumMeteor[b]->getPosition());
                    smallMeteor[smallMeteorsCount]->setSpeedByAngle(ship->getRotation());
                }

                smallMeteor[smallMeteorsCount]->setActive(true);
                smallMeteorsCount++;
            }

            b = maxMediumMeteors;
        }
    }

    for (int c = 0; c < maxSmallMeteors; c++)
    {
        if (smallMeteor[c]->getActive() && ship->intersectBulletsWithBound(smallMeteor[c]->getBounds()))
        {
            smallMeteor[c]->explode();
            destroyedMeteorsCount++;

            c = maxSmallMeteors;
        }
    }
}

GameplayScene::GameplayScene()
{

    // Ship textures and sounds
    shipTexture.loadFromFile("resources/images/ship_G.png");
    shipTexture.setSmooth(true);
    engineSfxBuffer.loadFromFile("resources/sfx/engineCircular_000.ogg");
    shiledSfxBuffer.loadFromFile("resources/sfx/forceField_000.ogg");
    explodeShipSfxBuffer.loadFromFile("resources/sfx/explosionCrunch_004.ogg");
    laserShipSfxBuffer.loadFromFile("resources/sfx/laserLarge_000.ogg");

    // Meteor textures and sounds
    meteorTexture.loadFromFile("resources/images/meteor_detailedLarge.png");
    meteorTexture.setSmooth(true);
    meteorExplosion.loadFromFile("resources/sfx/explosionCrunch_000.ogg");

    // Ship creation
    ship = new Ship(shipTexture, { screenWidth * 0.5f, screenHeight * 0.5f }, 0, { 0.5f,0.5f });
    ship->setEngineSfx(engineSfxBuffer);
    ship->setShieldSfx(shiledSfxBuffer);
    ship->setExplodeSfx(explodeShipSfxBuffer);
    ship->setLaserSfx(laserShipSfxBuffer);

    // UI 
    font.loadFromFile("resources/fonts/Roboto-Medium.ttf");
    text.setFont(font);
    text.setPosition(screenWidth * 0.5f, screenHeight * 0.5f);
    healtBar = new HealthBar(Vector2f(screenWidth * 0.5f, 15), ship->getMaxShield(), Color(66, 117, 245), Color(66, 84, 245));

    continueButton = new Button({ screenWidth * 0.5f, screenHeight * 0.55f }, "CONTINUE", 20);
    continueButton->setFont(font);
    continueButton->setPivot({ 0.5f, 1 });
    backButton = new Button({ screenWidth * 0.5f, screenHeight * 0.6f }, "VOLVER", 20);
    backButton->setFont(font);
    backButton->setPivot({ 0.5f, 1 });
    pauseButton = new Button({ screenWidth * 0.95f, screenHeight * 0.05f }, "II", 40, Color::Blue);
    pauseButton->setFont(font);
    pauseButton->setPivot({ 1,1 });

    //Meteors Creation
    createMeteors();
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

    delete healtBar;
    delete backButton;
    delete continueButton;
    delete pauseButton;

    /*font.~Font();
    shipTexture.~Texture();
    engineSfxBuffer.~SoundBuffer();
    shiledSfxBuffer.~SoundBuffer();
    explodeShipSfxBuffer.~SoundBuffer();
    meteorTexture.~Texture();
    meteorExplosion.~SoundBuffer();*/
}

void GameplayScene::resetGame()
{
    gameOver = false;
    victory = false;
    pause = false;

    ship->setPosition(screenWidth * 0.5f, screenHeight * 0.5f);
    ship->resetState();

    createMeteors();
}

void GameplayScene::updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime)
{
    // Update first
    if(!gameOver)
    {
        if (!pause)
        {
            ship->update(deltaTime);

            // Meteors logic: big meteors
            for (int i = 0; i < maxBigMeteors; i++)
            {
                bigMeteor[i]->update(deltaTime);
            }

            // Meteors logic: medium meteors
            for (int i = 0; i < maxMediumMeteors; i++)
            {
                mediumMeteor[i]->update(deltaTime);
            }

            // Meteors logic: small meteors
            for (int i = 0; i < maxSmallMeteors; i++)
            {
                smallMeteor[i]->update(deltaTime);
            }

            meteorsCollideWhitShip();
            bulletsCollideWhitMeteors();

            victory = destroyedMeteorsCount == maxBigMeteors + maxMediumMeteors + maxSmallMeteors;

            healtBar->setCurValue(ship->getShield());
        }
    }


    // Draw second
    ship->draw(window);

    // Meteors draw: big meteors
    for (int i = 0; i < maxBigMeteors; i++)
    {
        bigMeteor[i]->draw(window);
    }

    // Meteors draw: medium meteors
    for (int i = 0; i < maxMediumMeteors; i++)
    {
        mediumMeteor[i]->draw(window);
    }

    // Meteors draw: small meteors
    for (int i = 0; i < maxSmallMeteors; i++)
    {
        smallMeteor[i]->draw(window);
    }

    healtBar->draw(window);

    if(!gameOver)
    {
        if (pause)
        {
            text.setString("JUEGO PAUSADO");
            text.setOrigin({ text.getLocalBounds().width * 0.5f, text.getLocalBounds().height });
            window.draw(text);
        }

        if (!victory)
        {
            pauseButton->update(window);
            if (pauseButton->isClick()) pause = !pause;
        }
        else
        {
            text.setString("NIVEL " + to_string(gameLevel) + " COMPLETADO");
            text.setOrigin({ text.getLocalBounds().width * 0.5f, text.getLocalBounds().height });
            window.draw(text);
            continueButton->setText("SIGUIENTE NIVEL");
            continueButton->setPivot({ 0.5f, 1 });
            continueButton->update(window);
            backButton->update(window);

            if (continueButton->isClick())
            {
                gameLevel++;
                resetGame();
            }

            if (backButton->isClick())
            {
                sceneState = SceneState::MainMenu;
                resetGame();
            }
        }
    }
    else
    {
        text.setString("FIN DEL JUEGO");
        text.setOrigin({ text.getLocalBounds().width * 0.5f, text.getLocalBounds().height });
        window.draw(text);
        continueButton->setText("RE-INTENTAR");
        continueButton->setPivot({ 0.5f, 1 });
        continueButton->update(window);
        backButton->update(window);

        if (continueButton->isClick()) resetGame();
        
        if (backButton->isClick())
        {
            sceneState = SceneState::MainMenu;
            resetGame();
        }
    }
}
