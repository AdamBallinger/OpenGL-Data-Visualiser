#ifndef fontrenderer_h
#define fontrenderer_h

#include "Vector3f.h"

#include <string>

class FontRenderer
{
public:

	static void RenderText(std::string, float, float, float, Vector3f);
	static void RenderText(std::string, float, float, float, Vector3f, bool);
};

#endif