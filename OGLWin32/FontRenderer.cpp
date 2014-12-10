#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include "glfont2.h"

using namespace glfont;

GLFont fontRenderer;

/*
* Load in the font file to render characters from.
*/
void FontRenderer::Init()
{
	fontRenderer.Create("Arial.glf", 1);
}

/*
	Renders text to the screen from a bitmap file.
	text - Text being rendered.
	scale - Scale value the text should be rendered at.
	x - X coordinate of text.
	y - Y coordinate of text.
	col - RGB color of the text.
*/
void FontRenderer::RenderText(std::string text, float scale, float x, float y, Vector3f col)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glColor3f(col.GetX(), col.GetY(), col.GetZ());
	fontRenderer.Begin();
	fontRenderer.DrawString(text, scale, x, y);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

/*
	Render text with a shadow effect.
*/
void FontRenderer::RenderText(std::string text, float scale, float x, float y, Vector3f col, bool shadow)
{
	// Translate the shadow of the text backwards on the Z axis to prevent Z-clipping with the two layers.
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -1.5f);
	RenderText(text, scale, x + 2, y - 2, Vector3f(0.75f, 0.75f, 0.75f));
	glPopMatrix();

	RenderText(text, scale, x, y, col);
}