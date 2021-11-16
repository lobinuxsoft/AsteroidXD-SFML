#pragma once
#include "scene.h"

#include "class/ui_objects/button.h"

class TutorialScene : public Scene
{
private:
	string tutorialText = R"(
Destruye todos los asteroides para superar el nivel,
si los asteroides tocan la nave se reduce su integridad.

El medidor de integridad se encuentra en la esquina superior izquierda,
cuando esta se vacie el juego se termina.

Puedes pausar el juego si haces CLICK en el boton de pausa,
que se encuentra en la esquina superior derecha.

Comportamiento de la nave:
- Siempre mira donde esta el puntero del mouse.
- Boton derecho del mouse para acelerar.
- Boton izquierdo del mouse para disparar.

DISFRUTA EL JUEGO xD
)";

	Font font;
	Text sceneName;
	Text tutorialDescriptionText;
	Button* backButton;

public:
	TutorialScene();
	~TutorialScene() override;

	// Inherited via Scene
	virtual void updateAndDraw(SceneState& sceneState, RenderWindow& window, float deltaTime) override;

};

