#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include "glfont2.h"

using namespace glfont;

GLFont fontRenderer;

void FontRenderer::RenderText(std::string text, float scale, float x, float y, Vector3f col)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	fontRenderer.Create("Arial.glf", 1);

	glMatrixMode(GL_MODELVIEW);
	glColor3f(col.GetX(), col.GetY(), col.GetZ());
	fontRenderer.Begin();
	fontRenderer.DrawString(text, scale, x, y);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void FontRenderer::RenderText(std::string text, float scale, float x, float y, Vector3f col, bool shadow)
{
	RenderText(text, scale, x + 2, y - 2, Vector3f(0.75f, 0.75f, 0.75f));
	RenderText(text, scale, x, y, col);
}