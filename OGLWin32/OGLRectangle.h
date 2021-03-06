#pragma once

#include "Renderable.h"
#include "Listener.h"
#include "Vector2f.h"

class OGLRectangle : public Renderable, public Listener
{
	private:
		Vector2f		m_topleft;
		Vector2f		m_bottomright;

	public:
						OGLRectangle();
						~OGLRectangle();

		void			Render();
		bool			MouseMove( int x, int y );
		bool			MouseLBUp( int x, int y );
		bool			MouseLBDown( int x, int y );
};