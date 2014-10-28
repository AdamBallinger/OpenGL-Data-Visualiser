#pragma once

#include <Windows.h>
#include "OGLRectangle.h"

class OGLWindow
{
	private:
		HWND		m_hwnd;				//handle to a window
		HDC			m_hdc;				//handle to a device context
		HGLRC		m_hglrc;			//handle to a gl rendering context

		int			m_width;
		int			m_height;
		
		//This is not an ideal place to hold geometry data
		OGLRectangle   *m_rect;

protected:

		HGLRC CreateOGLContext (HDC hdc);
		BOOL DestroyOGLContext();
		BOOL InitWindow(HINSTANCE hInstance, int width, int height);
		void InitOGLState();

	public:
					OGLWindow();
					OGLWindow(HINSTANCE hInstance, int width, int height);
					~OGLWindow();

		void		Render();
		void		Resize( int width, int height );
		void		SetVisible( BOOL visible );
		void		DestroyOGLWindow();

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseMove ( int x, int y );
};