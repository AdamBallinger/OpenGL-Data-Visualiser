#pragma once

#include <Windows.h>
#include "BarChart.h"
#include "LineChart.h"
#include "PieChart.h"

class OGLWindow
{
	private:
		HWND		m_hwnd;				//handle to a window
		HDC			m_hdc;				//handle to a device context
		HGLRC		m_hglrc;			//handle to a gl rendering context

		int			m_width;
		int			m_height;

		// global scale value for all geometry
		double global_scale;

		// offset for panning.
		bool shouldOffset;
		double offsetX;
		double offsetY;
		
		//This is not an ideal place to hold geometry data
		BarChart * barChart;
		LineChart * lineChart;
		PieChart * pieChart;

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

		void		SetVSync(bool);

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseRBDown(int x, int y);
		BOOL		MouseRBUp(int x, int y);
		BOOL		MouseMove ( int x, int y );
		// Handles keyboard input
		BOOL		HandleKey(WPARAM);
};