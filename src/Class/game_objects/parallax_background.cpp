#include "parallax_background.h"

ParallaxBackground::ParallaxBackground()
{
	shader1.loadFromMemory(
		"uniform float offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, Shader::Vertex);

	shader2.loadFromMemory(
		"uniform float offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, Shader::Vertex);

	texture1.loadFromFile("resources/images/parallax-space-far-planets.png");
	texture1.setRepeated(true);

	texture2.loadFromFile("resources/images/parallax-space-stars.png");
	texture2.setRepeated(true);

	sprite1.setPosition(0, 0);
	sprite1.setTexture(texture1);
	sprite1.setScale(scale, scale);

	sprite2.setPosition(0, 0);
	sprite2.setTexture(texture2);
	sprite2.setScale(scale, scale);
}

void ParallaxBackground::update(RenderWindow& window, float deltaTime)
{
	shader1.setUniform("offset", offset1 += speed1 * deltaTime);
	shader2.setUniform("offset", offset2 += speed2 * deltaTime);

	window.draw(sprite1, &shader1);
	window.draw(sprite2, &shader2);
}
