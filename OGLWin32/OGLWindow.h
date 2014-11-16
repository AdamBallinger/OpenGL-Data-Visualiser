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

		// Store last x and y positions of mouse for panning.
		int lastX;
		int lastY;

		// offset for panning.
		bool shouldOffset;
		double offsetX;
		double offsetY;

		// Constant offset speed
		double X_SPEED = 20.0;
		double Y_SPEED = 20.0;

		// Constant keyboard bindings for key handling
		// Key number 1
		static const byte KEY_1 = 0x31;

		// Constant Default offset
		const double DEFAULT_X = 1.0;
		const double DEFAULT_Y = 1.0;

		// Constand Deadspace values for camera panning
		const double DEADSPACE_X = 3;
		const double DEADSPACE_Y = 3;

		// Constant minimum x and y panning speed.
		const int MIN_X_SPEED = 5;
		const int MIN_Y_SPEED = 5;

		// Constant maximum x and y panning speed.
		const int MAX_X_SPEED = 50;
		const int MAX_Y_SPEED = 50;

		// Constant step speed for panning
		const int X_STEP_SPEED = 5;
		const int Y_STEP_SPEED = 5;
		
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
		void		ResetView();

		void		RenderText(std::string, float, float, float, Vector3f);
		void		RenderText(std::string, float, float, float, Vector3f, bool);

		void		SetOffsetX(double);
		void		SetOffsetY(double);

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseRBDown(int x, int y);
		BOOL		MouseRBUp(int x, int y);
		BOOL		MouseMove ( int x, int y );
		// Handles keyboard input
		BOOL		HandleKey(WPARAM);
};